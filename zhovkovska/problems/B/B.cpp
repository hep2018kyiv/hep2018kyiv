#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b);

int main()
{

    unsigned long int N, K, M=0;
    int x[8], i, length=0;
    
    cin >> N >> K;
    while (N > 0)
    {
        x[length] = N % 10;
        N /= 10;
        length++;
    }
    int iter = 0;
    int xMax = x[length-1];
    for(i=length-1; i>=0 && iter<K ;i--) {    
        int k=i;
        xMax = x[i];
        for(int j=i-1;j>=0;j--) { 
            if (x[j]>=xMax){
                xMax = x[j];
                k = j;
            }
        }
        if (k != i && x[k] != x[i]){
            swap(x[k],x[i]);    
            iter ++;            
        }
    }       

    if (x[1]<x[0] && x[length-1]==x[length-2] && iter==2)
        swap(x[0],x[1]);
    if (iter%2 != K%2){
        i=length-1;
        while (x[i] != x[i-1] && i>0){
            i--;
        }
        if (i!=0)   swap(x[i],x[i-1]);
        else        swap(x[0],x[1]);
    }        
    for (i=length-1; i>-1; i--){
        M*=10;
        M += x[i];
    }
    cout<<M;
    return 0;
}


void swap(int *a, int *b)
{
    int c = *a;
    *a=*b;
    *b=c;
}
