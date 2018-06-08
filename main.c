
#include "targetver.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#ifdef _WIN32
# include <windows.h>
#else
# include <sys/time.h>
#endif

#define WAITING_FIRST_BLOCK        1
#define WAITING_NON_FIRST_BLOCK    2

//
// ird - image region detection
//

struct input_data {
	int            w, h;
	char          *cdata;
};

struct ird_taskctx {
	int            free_id;                   // вільний ідентифікатор для наступного блоку
	int            img_w, img_h;              // ширина, висота фотографії
};

struct ird_block {
	int                id;                    // ідентифікатор об'єкта
	int                lind;                  // лінійний індекс початку блоку
	int                len;                   // довжина блоку
	union {
		struct ird_block  *next;              // наступний регіон
		struct ird_block  *prev_sibling;      // попередній блок
	};
	struct ird_block  *next_sibling;          // наступний блок
};

struct ird_region {
	int                region_id;
	double             CM[2];                  // центр мас
	int                radius;
	struct ird_region *next;
};

int                PhotoHandler        (FILE *);                        // обробляє фотографію
int                GetMatrix           (struct input_data *, FILE *);   // вичитує з файлу дані

struct ird_block  *ListPushFront       (struct ird_block *aHead, struct ird_block *anElem);                          // новий регіон попереду списку (повертає голову списку)
struct ird_block  *ListReplace         (struct ird_block *aPrev, struct ird_block *anOld, struct ird_block *aNew);   // заміна першого елемента регіону
void               ListInsertSibling   (struct ird_block *aPosToInsertAfter, struct ird_block *anElem);              // вставити елемент посеред регіону

struct ird_block  *IrdListCreate       (struct ird_taskctx *, FILE *);
struct ird_block  *IrdElemCreate       (int *, struct ird_taskctx *, FILE *);
struct ird_block  *IrdListInsert       (struct ird_block *, struct ird_block *, struct ird_taskctx *);
struct ird_block  *IrdListReplace      (struct ird_block *aPrev, struct ird_block **anOld, struct ird_block *aNew);  // заміна першого елемента регіону
struct ird_block  *IrdSortAfterReplace (struct ird_block *, struct ird_block *);
struct ird_block  *IrdListMerge        (struct ird_block *aPrev1, struct ird_block *aPrev2, struct ird_block *anItrRegion1, struct ird_block *anItrRegion2);
struct ird_region *IrdCentreOfMass     (struct ird_block *, struct ird_taskctx *);
void               IrdGetRadius        (struct ird_region *, struct ird_block *, struct ird_taskctx *);


int main(argc, argv)
	int argc;
	char *argv[];
{
#ifdef _WIN32
	UINT  oldcodepage;
	DWORD bStatus;
	DWORD start_t, end_t;
#else
	struct timeval tv_start, tv_end;
	int start_t, end_t;
#endif
	int radius;
	FILE *stm;
	double total_t;


#ifdef _WIN32
	oldcodepage = GetConsoleOutputCP();
	bStatus = SetConsoleOutputCP(1251);
	start_t = GetTickCount();
#else
	gettimeofday(&tv_start, NULL);
#endif


//	printf("%s\n", argv);
	stm = fopen(argv[1], "r");
	if (!stm) {
		perror("Невдале відкриття файлу (Unsuccessful file opening)");
		return (EXIT_FAILURE);
		/* NOTREACHED */
	};
	
	radius = PhotoHandler(stm);
//	printf("%s: %d\n", "Радіус місяця (Moon radius)", radius);

#ifdef _WIN32
	SetConsoleOutputCP(oldcodepage);
	end_t = GetTickCount();
#else
	gettimeofday(&tv_end, NULL);
#endif

//#ifdef _WIN32
//	printf("start_t: %ul\n", start_t);
//	printf("end_t:   %ul\n", end_t);
//#else
//	printf("start_t: %ld.%ld\n", tv_start.tv_sec, tv_start.tv_usec);
//	printf("end_t:   %ld.%ld\n", tv_end.tv_sec, tv_end.tv_usec);
//#endif
//	printf("wasted time: %lf\n", total_t);
//	getc(stdin);
	return (radius);
}

int PhotoHandler(aStm)
		FILE *aStm;
{
	struct input_data data;
	struct ird_taskctx ctx;
	struct ird_block *listHeadB,*itr, *itb;
	struct ird_region *listHeadR, *itrr;
	int sts;
	int radius;

	fscanf(aStm, "%d %d\n", &(ctx.img_w), &(ctx.img_h));

	listHeadB = IrdListCreate(&ctx, aStm);
	fclose(aStm);

	//for (itr = listHeadB; itr != NULL; itr = itr->next) {
	//	printf("%s:\n", "next region");
	//	for (itb = itr; itb != NULL; itb = itb->next_sibling) {
	//		printf("lind = %d\n", itb->lind);
	//	}
	//}
	listHeadR = IrdCentreOfMass(listHeadB, &ctx);
	IrdGetRadius(listHeadR, listHeadB, &ctx);
	radius = 0;
	for (itrr = listHeadR; itrr != NULL; itrr = itrr->next) {
		if (radius < itrr->radius)
			radius = itrr->radius;
	}
	//for (itrr = listHeadR; itrr != NULL; itrr = itrr->next) {
	//	printf("CM_x = %8.2lf\tCM_y = %8.2lf\n", itrr->CM[0], itrr->CM[1]);
	//	printf("radius = %d\n", itrr->radius);
	//}
	return (radius);
}

void IrdGetRadius(aHeadR, aHeadB, aCtx)
		struct ird_region *aHeadR;
		struct ird_block *aHeadB;
		struct ird_taskctx *aCtx;
{
	struct ird_region *itrr;
	struct ird_block *itr, *itb;
	double radius;
	int x, y, n;

	for (itr = aHeadB, itrr = aHeadR; itr != NULL; itr = itr->next, itrr = itrr->next) {
		n = 0;
		radius = 0;
		for (itb = itr; itb != NULL; itb = itb->next_sibling) {
			double r;

			x = itb->lind % aCtx->img_w + 1;
			if ( (1 == itb->len) && ( (x != (int)(itrr->CM[0])) && ((x - 1) != (int)(itrr->CM[0])) ) )
				continue;
				/* NOTREACHED */
			y = itb->lind / aCtx->img_w + 1;
			r = sqrt((x - itrr->CM[0]) * (x - itrr->CM[0]) + (y - itrr->CM[1]) * (y - itrr->CM[1]));
			radius = (radius * n + r) / (n + 1);
			n++;
			if (itb->len != 1) {
				x = (itb->lind + itb->len - 1) % aCtx->img_w + 1;
				y = (itb->lind + itb->len - 1) / aCtx->img_w + 1;
				r = sqrt((x - itrr->CM[0]) * (x - itrr->CM[0]) + (y - itrr->CM[1]) * (y - itrr->CM[1]));
				radius = (radius * n + r) / (n + 1);
				n++;
			}
		}
		itrr->radius = ceil(radius);
	}
	return;
}

struct ird_region *IrdCentreOfMass(aHead, aCtx)
		struct ird_block *aHead;
		struct ird_taskctx *aCtx;
{
	struct ird_region *head, *region, *itrr;
	struct ird_block *itr, *itb;
	double CM_x, CM_y;
	int n;
	int region_id;
	int lind, x, y;

	region_id = 0;
	head = NULL;
	for (itr = aHead; itr != NULL; itr = itr->next) {
		CM_x = 0, CM_y = 0, n = 0;
		for (itb = itr; itb != NULL; itb = itb->next_sibling) {
			for (lind = itb->lind; lind < (itb->lind + itb->len); lind++) {
				x = lind % aCtx->img_w + 1;
				y = lind / aCtx->img_w + 1;
				CM_x = (CM_x * n + x) / (n + 1);
				CM_y = (CM_y * n + y) / (n + 1);
				n++;
			}
		}
		region = (struct ird_region *)malloc(sizeof(struct ird_region));
		region->CM[0] = CM_x;
		region->CM[1] = CM_y;
		if (NULL == head) {
			head = region;
			itrr = head;
		}
		else {
			itrr->next = region;
			itrr = itrr->next;
		}
		itrr->next = NULL;
	}
	return (head);
}

struct ird_block *IrdListCreate(aCtx, aStm)
		struct ird_taskctx *aCtx;
		FILE *aStm;
{
	struct ird_block *listHead, *itr, *itb;
	struct ird_block *element;
	int pxlnum;

	listHead = NULL;
	pxlnum = -1;
	for (;;) {
		element = IrdElemCreate(&pxlnum, aCtx, aStm);
		if (NULL == element)
			break;
		listHead = IrdListInsert(listHead, element, aCtx);
		//for (itr = listHead; itr != NULL; itr = itr->next) {
		//	printf("%s:\n", "next region");
		//	for (itb = itr; itb != NULL; itb = itb->next_sibling) {
		//		printf("lind = %d\n", itb->lind);
		//	}
		//}
	}
	return (listHead);
}

struct ird_block *IrdElemCreate(aLind, aCtx, aStm)
		int *aLind;
		struct ird_taskctx *aCtx;
		FILE *aStm;
{
	struct ird_block *element;
	int pxl, img_dim;

	img_dim = aCtx->img_w * aCtx->img_h;
	do {
		pxl = fgetc(aStm);
		if ('\n' != pxl)
			(*aLind)++;
	} while ( ('.' == pxl) || ('\n' == pxl) );
	if (EOF == pxl)
		return (NULL);
		/* NOTREACHED */
	element = (struct ird_block *)malloc(sizeof(struct ird_block));
	element->lind = *aLind;
	element->len = 0;
	element->id = -1;
	do {
		(element->len)++;
		pxl = fgetc(aStm);
		(*aLind)++;
	} while ( (*aLind < (img_dim - 1)) && ((*aLind + 1) % aCtx->img_w != 0) && ('*' == pxl) );
	return (element);
}

struct ird_block *IrdListInsert(aHead, anElem, aCtx)
		struct ird_block  *aHead, *anElem;
		struct ird_taskctx *aCtx;
{
	int i0, i1,                               // block's start and finish comparing with
	    j0, j1;                               // inserting block's start and finish
	struct ird_block *itr, *itrPrev;          // region iterator
	int state;
	int stateAttr;

	stateAttr = 0;
	j0 = anElem->lind;
	j1 = anElem->lind + anElem->len - 1;
	for (itr = aHead, itrPrev = NULL; itr != NULL; itr = itr->next) {
		struct ird_block *itb;

		state = WAITING_FIRST_BLOCK;
		for (itb = itr; itb != NULL; itb = itb->next_sibling) {
			i0 = itb->lind;
			i1 = itb->lind + itb->len - 1;

			if (i1 + aCtx->img_w < j0) {
				if (WAITING_FIRST_BLOCK == state)
					goto L_ret_from_routine;
					/* NOTREACHED */
				break; /* goto next region */
			}

			if (i0 + aCtx->img_w > j1) {
				state = WAITING_NON_FIRST_BLOCK;
				continue; /* goto next sibling */
			}

			if (0 == stateAttr) {
				IrdListReplace(itrPrev, &itr, anElem);
				if (NULL != itrPrev)
					IrdSortAfterReplace(aHead, itrPrev);
				stateAttr = 1;
				break; /* goto next region */
			}
			itr = IrdListMerge(NULL, itrPrev, anElem, itr);
			break; /* goto next region */
		}
		if (0 == stateAttr)
			itrPrev = itr;
	}

 L_ret_from_routine:
	if (0 == stateAttr)
		ListPushFront(aHead, anElem);
	return (anElem);
}

struct ird_block *IrdListMerge(aPrev1, aPrev2, anItrRegion1, anItrRegion2) // злиття на позиції першого регіону
		struct ird_block   *aPrev1, *aPrev2, *anItrRegion1, *anItrRegion2;
{
	struct ird_block *regionMerge;
	struct ird_block *regionHead;

/* перебудова в розташуванні регіонів у списку */
	if (anItrRegion1->lind < anItrRegion2->lind) {
		regionMerge = anItrRegion2;
		if (NULL != aPrev1)
			aPrev1->next = regionMerge;
		if (NULL != aPrev2) {
			aPrev2->next = anItrRegion2->next;
			regionMerge->next = anItrRegion1->next;
		}
		anItrRegion2 = anItrRegion2->next_sibling;
	}
	else {
		regionMerge = anItrRegion1;
		if (NULL != aPrev2)
			aPrev2->next = anItrRegion2->next;
		else
			regionMerge->next = anItrRegion2->next;
		anItrRegion1 = anItrRegion1->next_sibling;
	}
	regionMerge->next_sibling = NULL;
	regionHead = regionMerge;

/* злиття регіонів */
	for (;;) {
		if (NULL == anItrRegion1) {
			regionMerge->next_sibling = anItrRegion2;
			anItrRegion2->prev_sibling = regionMerge;
			goto L_ret_from_routine;
			/* NOTREACHED */
		}
		else if (NULL == anItrRegion2) {
			regionMerge->next_sibling = anItrRegion1;
			anItrRegion1->prev_sibling = regionMerge;
			goto L_ret_from_routine;
			/* NOTREACHED */
		}
		if (anItrRegion1->lind < anItrRegion2->lind) {
			struct ird_block *tempPrev;
			tempPrev = anItrRegion2;
			anItrRegion2 = anItrRegion2->next_sibling;
			ListInsertSibling(regionMerge, tempPrev);
		}
		else {
			struct ird_block *tempPrev;
			tempPrev = anItrRegion1;
			anItrRegion1 = anItrRegion1->next_sibling;
			ListInsertSibling(regionMerge, tempPrev);
		}
		regionMerge = regionMerge->next_sibling;
		regionMerge->next_sibling = NULL;
	}
 L_ret_from_routine:
	return (regionHead);
}

struct ird_block *IrdSortAfterReplace(aHead, aRegion)
		struct ird_block   *aHead, *aRegion;
{
	struct ird_block *temp;

	temp = aRegion->next;
	aRegion->next = temp->next;
	temp->next = aHead;
	return (aRegion->next);    // повертає наступний регіон, який треба перевірити
}

struct ird_block *ListPushFront(aHead, anElem)
		struct ird_block   *aHead, *anElem;
{
	anElem->next_sibling = NULL;
	anElem->next = aHead;
	return (anElem);
}

struct ird_block *ListReplace(aPrev, anOld, aNew)
		struct ird_block   *aPrev, *anOld, *aNew;
{
	aNew->next = anOld->next;
	anOld->prev_sibling = aNew;
	aNew->next_sibling = anOld;
	if (NULL == aPrev)
		return (aNew);
	aPrev->next = aNew;
	return (aPrev);
}

struct ird_block *IrdListReplace(aPrev, anOld, aNew)
			struct ird_block   *aPrev, **anOld, *aNew;
{
	struct ird_block *ret;
	ret = ListReplace(aPrev, *anOld, aNew);
	*anOld = (*anOld)->next; // це необхідно, оскільки в область пам'яті itr->next тепер записано itr->prev_sibling
	return (ret);
}

void ListInsertSibling(aPosToInsertAfter, anElem)
		struct ird_block   *aPosToInsertAfter, *anElem;
{
	struct ird_block *nextSibling;
	nextSibling = aPosToInsertAfter->next_sibling;
	anElem->next_sibling = nextSibling;
	anElem->prev_sibling = aPosToInsertAfter;
	if (NULL != nextSibling)
		nextSibling->prev_sibling = anElem;
	aPosToInsertAfter->next_sibling = anElem;
}

int GetMatrix(aData, aStm)
		struct input_data *aData;
		FILE *aStm;
{
	int rownum;
	char *d, *q;

	fscanf(aStm, "%d %d\n", &(aData->w), &(aData->h));
	d = aData->cdata = (char *)calloc(aData->w * aData->h + 3, sizeof(char));
//	printf("w:%d h:%d\n", aData->w, aData->h);
	rownum = 0;
	do {
		q = fgets(d, aData->w + 3, aStm);
//		printf("input:%d:%s\n", (int)strlen(q), q);
		if (NULL == q || (int)strlen(q) < aData->w)
			return (-ENOEXEC);
		d += aData->w;
	} while (++rownum < aData->h);
	return (0);
}
