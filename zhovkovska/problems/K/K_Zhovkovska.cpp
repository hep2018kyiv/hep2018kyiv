#include <iostream>
#include <fstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

//vectors

// int main()
// {
//     int N, K, B, C, M, A1, i, ind=0;
//     cin>>N>>K>>B>>C>>M>>A1;
//     std::vector<long int> myvector;
//     
//     long int Ai = A1;
//     myvector.push_back(Ai);
//     for (i=1; i<N; i++){
//         long int a = Ai % M;
//         long int b = B % M;
//         Ai = ((a*b) + C%M) % M;
//         myvector.push_back(Ai);
//     }
//     std::sort(myvector.begin(), myvector.end());
//     
//     for (auto it=myvector.end()-K; it!=myvector.end(); ++it)
//         std::cout << *it << ' ' ;
//     std::cout << '\n';
//     return 0;
// }



// int main()
{
    int N, K, B, C, M, A1;
    cin>>N>>K>>B>>C>>M>>A1;
    long int seq[N];
    
    seq[0] = A1;
    for (int i=1; i<N; i++){
        long int a = seq[i-1] % M;
        long int b = B % M;
        seq[i] = ((a*b) + C%M) % M;
        //         cout<<seq[i]<<" ";
    }
    std::sort(seq, seq+N);
    
    //     for(int i = 0; i < N; i++) 
    //     {
    //         cout<<seq[i]<<" ";
    //     }    
    //     cout<<endl;
    
    for(int i = K-1; i >= 0; i--) 
    {
        cout<<seq[N-1-i]<<" ";
    }    
    return 0;
}

// //pointers
// int main()
// {
//     int N, K, B, C, M, A1;
//     cin>>N>>K>>B>>C>>M>>A1;
//     long int *seq, a, b;
//     seq = (long int *)malloc(N*sizeof(long int));
//     cout<<"atata"<<endl;
//     
//     seq[0] = A1;
//     for (int i=1; i<N; i++){
//         a = seq[i-1] % M;
//         b = B % M;
//         seq[i] = ((a*b) + C%M) % M;
//         //         cout<<seq[i]<<" ";
//     }
//     std::sort(seq, seq+N);
//     
//     //     for(int i = 0; i < N; i++) 
//     //     {
//     //         cout<<seq[i]<<" ";
//     //     }    
//     //     cout<<endl;
//     
//     for(int i = K-1; i >= 0; i--) 
//     {
//         cout<<*seq+N-i<<" ";
//     }    
//     return 0;
// }
