#include <iostream>
#include <math.h>

using namespace std;


int main(int argc, char * argv[])
{
    unsigned long buff;
    int i, k=0, c=0;
    cin >> buff;
    if (buff/10 == 0){
        cout << 10+buff <<endl;
        return 0;
    }
    for (i = 9; i>1; i--){
        while (buff % i == 0){
            buff /= i;
            k += i*pow(10,c);
            c++;
        }
    }
    if (buff != 1) cout << -1 <<endl;
    else cout << k <<endl;
    return 0;
}
