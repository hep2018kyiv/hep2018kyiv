#include <iostream>
#include "math.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int N,K,B,C,M,A;
	cin>>N>>K>>B>>C>>M>>A;
        
        
        vector<unsigned int> V;
         V.push_back(A);
        for (int j = 1; j<K; j++)
        {
   V.push_back((V[V.size()-1]*B+C)%M);}
   
   std::sort(V.rbegin(), V.rend());
   unsigned int chislo=V[V.size()-1];
   
   for (int i = K; i < N; i++)
{ chislo=(chislo*B+C)%M;
        if (V[K-1]<chislo)
        {    V[K-1]=chislo;
            std::sort(V.rbegin(), V.rend());
      }
}


for (int i=V.size()-1; i>=0; i--)
    cout << V[i]<<" ";
	return 0;
}