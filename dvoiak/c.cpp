#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


long gcd(long a, long b)
{
   if (b == 0) return a;
   return gcd(b, a % b);
}

int main(int argc, char * argv[])
{
    long x1, y1, x2, y2;
    long i = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    // long x = x1>=x2 ? x1-x2 : x2-x1;
    long x = labs(x1-x2);
    long y = y1>=y2 ? y1-y2 : y2-y1;
    long a = x>=y ? x : y;
    long b = a==x ? y : x;
    cout<< gcd(a, b)-1 <<endl;
    return 0;
}
