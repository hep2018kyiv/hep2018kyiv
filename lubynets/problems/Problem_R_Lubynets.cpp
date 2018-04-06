#include <iostream>
#include <cstring>
using namespace std;

long long int Cf(long long int hashold, int c1i, int clast, long long int CK, long long int D)
{
    return (hashold - c1i + clast*CK)%D;
}

int main()
{
    int N, K;
    long long int H;
    cin >> N >> K >> H;    
    
    const long long int A = 1103515245;
    const int B = 12345;
    const int C = 1009;
    const long long int D = 1000000007;
    long long int y;
    
    long long int *x = new long long int [N];
    char *c = new char [N];
    
    long long int *CN = new long long int [K+1];
    CN[0] = 1;
    for(int i=1; i<=K; i++)
        CN[i] = (CN[i-1]*C)%D;
    
    int W[C];
    W[0] = 0;
    for(int a=1; a<C; a++)
        W[C - (287*a)%C] = a;

    x[0] = 1;
    for(int i=1; i<K; i++)
        x[i] = (x[i-1]*A + B)%(4294967296);
     
    for(int i=0; i<K; i++)
        c[i] = 'a' + (char)((x[i]>>16)%26);

    long long int hash = 0;
    for(int i=0; i<K; i++)
        hash = (hash + (int)c[i] * CN[i])%D;

    int k = K;
    while(!(hash==H) && k<N)
    {
        x[k] = (x[k-1]*A + B)%(4294967296);
        c[k] = 'a' + (char)((x[k]>>16)%26);
        y = Cf(hash, (int)c[k-K], (int)c[k], CN[K], D);
        hash = ((W[y%C]*D + y)/C)%D;
        k++;
    }

    if (hash==H)
    {
        for(int i=k-K; i<k; i++)
            cout << c[i];
    }
        else
            cout << 0;
    
    delete x;
    delete CN;
    delete c;
        
    return 0;
    
}