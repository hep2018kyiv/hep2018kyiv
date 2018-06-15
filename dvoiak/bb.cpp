#include <iostream>
#include <math.h>

using namespace std;


int main(int argc, char * argv[])
{
    unsigned long buff, k=0, i, c=1;
    cin >> buff;
    if (buff==0){
        cout<<10<<endl;
        return 0;
    }
    for (i = 9; i>1; i--){
        while (buff % i == 0){
            k += i*c;
            cout << k <<endl;
            c = c*10;
            buff /= i;
        }
    }
    if (buff != 1) cout << -1 <<endl;
    else cout << k <<endl;
    return 0;
}
