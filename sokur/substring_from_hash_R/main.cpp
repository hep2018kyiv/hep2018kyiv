
#if 0
# include "targetver.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#include <deque>
using namespace std;

#define M 0xFFFFFFFF
#define A 1103515245
#define B 12345
#define C 1009
#define D 1000000007


deque< char >         *FindSubSeq  (unsigned aLen, unsigned aSubLen, unsigned aHash);
deque< char >         *MakeSubSeq  (unsigned aSubLen, long long unsigned *aXbegin, long long unsigned *aXend);
long long unsigned     Xnext       (long long unsigned xold);
char                   GetASCII    (long long unsigned x);
long long unsigned     HashFcn     (deque< char > *aSequence);
long long unsigned     HashItr     (long long unsigned aHashOld, long long unsigned aRemove, long long unsigned anAdd); // don'w work


int main(int argc, char *argv[])
{
	unsigned seqLen, subseqLen, hash;
	deque< char > *subseq;

	//deque< char > myseq;
	//myseq.push_back('a');
	//myseq.push_back('b');
	//long long unsigned hash2;
	//hash2 = HashFcn(&myseq);
	//printf("ab hash: %llu\n", hash2);
	//myseq.push_back('r');
	//myseq.erase(myseq.begin());
	//hash2 = HashItr(hash2, 'a', 'r');
	//printf("br hash: %llu\n", hash2);

	scanf("%u %u %u", &seqLen, &subseqLen, &hash);
	subseq = FindSubSeq(seqLen, subseqLen, hash);
	if (NULL == subseq)
		printf("%d\n", 0);
	else {
		for (unsigned k = 0; k < subseqLen; k++)
			printf("%c", subseq->at(k));
		printf("\n");
	}
	return (0);
}

deque< char > *FindSubSeq(unsigned aLen, unsigned aSubLen, unsigned aHash)
{
	unsigned lenDiff = aLen - aSubLen;
	deque< char > *subseq;
	long long unsigned hash;
	long long unsigned xbegin, xend;

	xbegin = 1;
	subseq = MakeSubSeq(aSubLen, &xbegin, &xend);
	hash = HashFcn(subseq);
	for (unsigned i = 0; i <= lenDiff; i++) {
		if (aHash == hash)
			return (subseq);
			/* NOTREACHED */
		xend = Xnext(xend);
		subseq->push_back(GetASCII(xend));
		subseq->erase(subseq->begin());
		xbegin = subseq->at(0);
		hash = HashFcn(subseq);
//		hash = HashItr(hash, xbegin, xend);
	}
	return (NULL);
}

deque< char > *MakeSubSeq(unsigned aSubLen, long long unsigned *aXbegin, long long unsigned *aXend)
{
	deque< char > *subseq;
	long long unsigned x_k = 1;

	*aXbegin = x_k;
	subseq = new deque< char >(1);
	subseq->at(0) = GetASCII(x_k);
	*aXend = x_k;
	for (unsigned k = 1; k < aSubLen; k++) {
		*aXend = Xnext(*aXend);
		subseq->push_back(GetASCII(*aXend));
	}
	return (subseq);
}

long long unsigned Xnext(long long unsigned xold)
{
	return ((xold * A + B) & M);
}

char GetASCII(long long unsigned x)
{
	return ('a' + char((x >> 16) % 26));
}

long long unsigned HashItr(long long unsigned aHashOld, long long unsigned aRemove, long long unsigned anAdd)
{
	unsigned leftbaseoffset = (C % D) * C;

	return ( ((aHashOld + D - aRemove % D) * C + anAdd * leftbaseoffset) % D );
}

long long unsigned HashFcn(deque< char > *aSequence)
{
	long long unsigned hash;
	deque< char>::iterator itr = aSequence->end();

	itr--;
	if (1 == aSequence->size())
		return ( ((long long unsigned)(*itr) * C) % D );
		/* NOTREACHED */
	hash = (long long unsigned)(*itr) % D;
	do {
		itr--;
		hash = (hash * C + (long long unsigned)(*itr)) % D;
	} while (itr != aSequence->begin());
	return (hash);
}
