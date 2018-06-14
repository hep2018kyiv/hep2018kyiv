
#include <stdio.h>

#include <map>
using namespace std;


void MakeContainer(map< unsigned, unsigned > *);
void KeyComparator(map< unsigned, unsigned > *);


int main(int argc, char *argv[])
{
	map< unsigned, unsigned > teenage_mutant_ninja_turtles;
	map< unsigned, unsigned >::iterator itr;

	MakeContainer(&teenage_mutant_ninja_turtles);
	KeyComparator(&teenage_mutant_ninja_turtles);
	return (0);
}

void MakeContainer(map< unsigned, unsigned > *aMapP)
{
	unsigned countMutant;
	map< unsigned, unsigned >::iterator itr;

	scanf("%u", &countMutant);
	for (unsigned i = 0; i < countMutant; i++) {
		unsigned key;
		scanf("%u", &key);
		itr = aMapP->find(key);
		if (aMapP->end() != itr)
			++itr->second;
		else
			(*aMapP)[key] = 1;
	}
	return;
}

void KeyComparator(map< unsigned, unsigned > *aMapP)
{
	unsigned countKey;
	map< unsigned, unsigned >::iterator itr;

	scanf("%u", &countKey);
	for (unsigned i = 0; i < countKey; i++) {
		unsigned key;
		scanf("%u", &key);
		itr = aMapP->find(key);
		if (aMapP->end() == itr)
			printf("%u ", 0);
		else
			printf("%u ", itr->second);
	}
	return;
}
