#include <iostream>
using namespace std;
 
int main()
{
    long long N,Q=0,a=1;
   cin >> N;
   if(N==0)
    {
        cout<<"10"<<endl;
        return 0;
    }
    if(N<10)
    {
        cout<<N<<endl;
        return 0;
    }
    for(long long i=9; i>1; --i)
    {
        while( (N%i) == 0)
        {
            Q += a*i;
            a = a*10;
            N /= i;
        }
    }
  if(N>1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
   cout << Q << endl;
 
    return 0;
}