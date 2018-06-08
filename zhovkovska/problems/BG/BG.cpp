#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;


int main()
{
//     clock_t cl;     //initializing a clock type
//     
//     cl = clock();
    
    std::fstream fIn;
    std::fstream fOut;
    fIn.open("INPUT.txt",std::ios::in);
    fOut.open("OUTPUT.txt",std::ios::out);
    map<unsigned int, unsigned int> animals;
    
    unsigned int N, M, i, x;
    unsigned int color;
    fIn >> N;
    for(i=0; i < N; ++i) 
    {
        fIn >> color;
        ++animals[color];
    }
    
    fIn >> M;
    for(i=0; i < M; ++i) 
    {
        fIn >> x;
        fOut << animals[x] << " ";
    }    
   
   fIn.close();
   fOut.close();
//     cout << cl/(double)CLOCKS_PER_SEC << endl;
    
    return 0;
}
