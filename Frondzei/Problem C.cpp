#include <iostream>
using namespace std;

long int gcd(long int a, long int b) //алгоритм Евкліда для пошуку найбільшого спільного дільника
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
    long int xa, ya, xb, yb;
    
    cin >> xa >> ya >> xb >> yb;
    
    cout << gcd(xa - xb, ya - yb) - 1;
    
    return 0;
    
}

