#include <iostream>
#include <fstream>
#include <map>
#define MAXVAL 1000000007
using namespace std;

long long int binpow (long long int a, long int n, long long int m);


int main()
{

    map<long long int, long long int> waste;
    long long int A, N, i;
    cin>>A>>N;
    
    long long int temp;
    long long int A2 = binpow(A,2,MAXVAL);
    long long int A3 = binpow(A,3,MAXVAL);
    long long int A4 = binpow(A,4,MAXVAL);
    long long int A5 = binpow(A,5,MAXVAL);
    long long int A6 = binpow(A,6,MAXVAL);
    long long int startPoint = (2015*A + 9*A2 + 24*A3)% MAXVAL;

    for (int iH=0; iH<24; iH++)
        for (int iM=0; iM<60; iM++)
            for (int iS=0; iS<60; iS++){
                temp = (startPoint + (iH*A4 + iM*A5 + iS*A6) % MAXVAL) % MAXVAL;
                ++waste[temp];
            }
    long int nBad=0;                
    for(i=0; i < N; ++i) 
    {
        scanf("%lld",&temp);
        if (waste[temp] != 0)
            ++nBad;
    }    

    printf("%ld",nBad);
    
    return 0;
}


long long int binpow (long long int a, long int n, long long int m) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow (a, n-1, m) * (a % m);
    else {
        long long int b = binpow (a, n/2, m) % m;
        return (b * b) % m;
    }
}
