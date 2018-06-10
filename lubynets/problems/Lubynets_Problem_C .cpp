#include <iostream>
using namespace std;

long int gcd(long int a, long int b)
{
    if(a<0)
        a = -a;
    if(b<0)
        b = -b;
    
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    long int xA, yA, xB, yB;
    
    cin >> xA >> yA >> xB >> yB;
    
    cout << gcd(xA - xB, yA - yB) - 1;
    
    return 0;
    
}