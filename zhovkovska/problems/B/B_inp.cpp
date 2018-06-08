#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;

void swap(int *a, int *b);

int main()
{
    clock_t cl;     //initializing a clock type
    
    cl = clock();
    
    std::fstream fIn;
    std::fstream fOut;
    fIn.open("INPUT.txt",std::ios::in);
    fOut.open("OUTPUT.txt",std::ios::out);
    unsigned long int N, K;
    int x[7], length=0;
    
    fIn >> N >> K;
    fIn.close();
    
    while (N > 0)
    {
        x[length] = N % 10;
        N /= 10;
        length++;
    }
    int iter = 0;
    int xMax = 0;
    for(int i=length-1; i>=0 && iter<K ;i--) {    
        int k=0;
        for(int j=i;j>=0;j--) { 
            if (x[j]>=xMax){
                xMax = x[j];
                k = j;
            }
        }
        swap(x[k],x[i]);    
        iter ++;
        xMax=0;
    }       

    if (iter%2 != K%2)
        swap(x[length-1],x[length-2]);
        
    for (int i=length-1; i>=0; i--)
        fOut << x[i];
    fOut.close();
    
    cout << endl << cl/(double)CLOCKS_PER_SEC << endl;
    cout << (sizeof(x) + sizeof(K) + sizeof(N) + sizeof(length) + sizeof(xMax) + sizeof(iter) + sizeof(fIn) + sizeof(fOut)) / 1048576.0 <<endl;
    return 0;
    
    
}


void swap(int *a, int *b)
{
    int c = *a;
    *a=*b;
    *b=c;
}
