#include <iostream>
#include <algorithm>    // std::sort
#include <fstream>
using namespace std;


int main()
{
    int N, K, B, C, M, A1, ind=0;
    cin>>N>>K>>B>>C>>M>>A1;
    long int seq[K];
    for (int i=0; i<K; i++)
        seq[i]=0;
    
    long int a, b, Ai = A1;
    seq[K-1] = A1;
    for (int i=1; i<N; i++){
        a = Ai % M;
        b = B % M;
        
        Ai = (a*b + C%M) % M;
        if (Ai >= seq[0]){
            ind++;
            seq[0] = Ai;
            std::sort(seq, seq + std::min(ind+1, K));                        
        }
    }

    for(int i=0; i < K; i++) 
    {
        cout<<seq[i]<<" ";
    }    
    return 0;
}
