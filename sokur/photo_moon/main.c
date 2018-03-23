
#include "targetver.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifdef _WIN32
# include <windows.h>
#endif


struct obj_info {
	int id;                    // ідентифікатор об'єкта
	int lind;                  // лінійний індекс першого білого пікселя
	int count;                 // вказує кількість білих пікселів їх неперервної послідовності в рядка
	struct obj_info *next;     // список різних об'єктів
	struct obj_info *sibling;  // список рядків одного об'єкту
};

struct input_data {
	int w, h;
	char *cdata;
};

int              PhotoHandler (FILE *);                                      // обробляє фотографію
int              GetMatrix    (struct input_data *, FILE *);                 // вичитує з файлу дані
struct obj_info *ListCreator  (struct obj_info *, char *);                   // утворює список, повертає вказівник на голову списку
struct obj_info *ListInsert   (struct obj_info *, struct obj_info *, int *); // вставляє новий блок в список, повертає вказівник на голову списку


int main(argc, argv)
	int argc;
	char *argv[];
{
#ifdef _WIN32
	UINT  oldcodepage;
	DWORD bStatus;
#endif
	int radius;
	FILE *stm;


#ifdef _WIN32
	oldcodepage = GetConsoleOutputCP();
	bStatus = SetConsoleOutputCP(1251);
#endif


	stm = fopen(argv[1], "r");
	if (!stm) {
		perror("Невдале відкриття файлу");
		return (EXIT_FAILURE);
		/* NOTREACHED */
	};

	radius = PhotoHandler(stm);
	printf("%s: %d\n", "Радіус місяця", radius);

#ifdef _WIN32
	SetConsoleOutputCP(oldcodepage);
#endif
/*	getc(stdin); */

	return (0);
}

int PhotoHandler(aStm)
	FILE *aStm;
{
	struct obj_info *listHead;
	struct input_data data;
	int sts;

	sts = GetMatrix(&data, aStm);
	if (sts < 0) {
		return (sts);
		/* NOTREACHED */
	}
	listHead = NULL;
	listHead = ListCreator(listHead, &data);
	return (0);
}

struct obj_info *ListCreator(aListHead, aData)
	struct obj_info *aListHead;
	struct input_data *aData;
{
	int freeid;
	int pxlrow, pxlcol, pxlnum;
	int pxlup, pxlf, pxll, pxldiff;
	struct obj_info *element;
	struct obj_info *sibling, *next;

	pxlnum = 0;
	freeid = 0;
	do {
		pxlrow = pxlnum / aData->w;
		pxlcol = pxlnum % aData->w;
		if ('*' == aData->cdata[pxlnum]) {
			element = (struct obj_info *)malloc(sizeof(struct obj_info));
			element->id = freeid;
			element->lind = aData->cdata[pxlnum];
			element->count = 0;
			do {
				element->count++;
			} while (++pxlnum < aData->w * aData->h && aData->cdata[pxlnum] == '*');
			aListHead = ListInsert(aListHead, element, &freeid);



//			if (0 != pxlrow || '*' == aData->cdata[pxlup = pxlnum - aData->w]) { /* піксель старого об'єкта */
////				elementp = (struct obj_info *)malloc(sizeof(struct obj_info));
//				sibling = aList->sibling;
//				next = aList->next;
//				for (;;) { /* пошук необхідного запису в списку */
//					pxlf = cntelementcpy->lind;
//					pxll = cntelementcpy->lind + cntelementcpy->count;
//					pxldiff = pxll - pxlup;
////					elementcpyp = (struct obj_info *)malloc(sizeof(struct obj_info));
//					if (pxlf <= pxlup && pxlup <= pxll) {
//						element = (struct obj_info *)malloc(sizeof(struct obj_info));
//						element->sibling = sibling->sibling;
//						element->next = next->next;
//					}
//						
//				}
//			}
			//else { /* піксель нового об'єкта */
			//}
		}
	} while (++pxlnum < aData->w * aData->h);
	return (0);
}


struct obj_info *ListInsert(aListHead, aBlock)
	struct obj_info *aListHead;
	struct obj_info *aBlock;
{
	struct obj_info *element;

	element = aListHead;
}



int GetMatrix(aData, aStm)
	struct input_data *aData;
	FILE *aStm;
{
	int rownum;
	char *d, *q;

	fscanf(aStm, "%d %d", &(aData->w), &(aData->h));
	d = aData->cdata = (char *)calloc(aData->w * aData->h + 1, sizeof(char));
	rownum = 0;
	do {
		q = fgets(d, aData->w + 1, aStm);
		if (NULL == q || strlen(q) < aData->w)
			return (-ENOEXEC);
		d += aData->w;
	} while (++rownum < aData->h);
	fclose(aStm);
	return (0);
}
