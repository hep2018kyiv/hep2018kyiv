#include <iostream>
#include <string>
using namespace std;

void maximum (string lis, long n, long long &p, long long &max)
{
for(int i=0; i<n; i++)
    {
    if(lis[i]>='0' && lis[i]<='9') 
        { p+= (lis[i]-'0');
            if(lis[i]-'0'>max)
                max=lis[i]-'0'; }
    else   
        { p+= (lis[i]-'A'+10);
        if(lis[i]-'A'+10>max)
        max=lis[i]-'A'+10;}
    }
}


int main()
{
    
string lis;
long long p=0,max=0,i=0;
   while(cin >> lis)
{    
    long n=lis.size();
 
    maximum(lis, n, p, max);

    if(max==0)
    { i=0;
    cout << "2" << endl;}
    else {
    for(i=max+1; i<=36; i++)
    if(p%(i-1)==0)
    { cout << i << endl; return 0; }}
    if(i==37)
    cout << "No solution." << endl;
    
}
return 0;
}
