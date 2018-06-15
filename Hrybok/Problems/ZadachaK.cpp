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
for (int i = 1; i < N; ++i)
{
    V.push_back((V[V.size()-1]*B+C)%M);
}
vector<unsigned int> v;

for (int i = 0; i<K; i++)
{int kres=0;
    for (int j = 0; j <V.size(); j++)
    { if (V[kres]<=V[j])
        {
            kres=j;
        }}
        v.push_back(V[kres]);
         V[kres]=0;
    
}
for (int i=v.size()-1; i>=0; i--)
    cout << v[i]<<" ";
	return 0;
}