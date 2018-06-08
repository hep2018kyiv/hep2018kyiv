#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;


// int main()
// {
//     long int N, K, B, C, M, A1;
//     cin>>N>>K>>B>>C>>M>>A1;
//     map<long int, int> seq;
//     
//     long int val = A1;
//     for (int i=1; i<N; i++){
//         long int a = val % M;
//         long int b = B % M;
//         val = ((a*b) + C%M) % M;
//         ++seq[val];
// //         cout<<val<<" ";
//     }
// //     cout<<"\n";
//     long int finSeq[K], k=0;
//     map<long int,int>::iterator it=seq.end();
//     while (it!=seq.begin() && k<K){
//         for (long int i=0; i<it->second; i++){
//             finSeq[k] = it->first;
//             k++;
//         }
//         --it;
//     }
//     
//     for(it=seq.begin(); it!=seq.end(); ++it)
//         cout<<it->first<<" ";
//     
//     cout<<endl;
//     
//     for(long int i = K-1; i >= 0; i--) 
//     {
//         cout<<finSeq[i]<<" ";
//     }    
//     return 0;
// }



int main()
{
    int N, K, B, C, M, A1, ind=0;
    cin>>N>>K>>B>>C>>M>>A1;
    map<long int, long int> seq;
    
    long int Ai = A1;
    ++seq[A1];
    for (int i=1; i<N; i++){
        long int a = Ai % M;
        long int b = B % M;
        
        Ai = (a*b + C%M) % M;
        if (Ai >= seq.begin()->first || ind<K){
            ind++;
//             seq.begin()->second -=1;
            ++seq[Ai];
        }
    }
    
    long int finSeq[K], k=0;
    auto it=seq.rbegin();
//     cout<<K<<"   "<<k<<endl;
    while (it!=seq.rend() && k<K){
        for (long int i=0; i<it->second; i++){
            finSeq[k] = it->first;
            k++;
        }
        ++it;
    }
    
    
    for(long int i = K-1; i >= 0; i--) 
    {
        cout<<finSeq[i]<<" ";
    }    
    return 0;
    
}
