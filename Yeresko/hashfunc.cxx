#include <iostream>
#include <string>
using namespace std;

void hashfunc()
{

    int p = 1009;
    long long p_pow = 1;
    int d = 1000000007;
    unsigned long long hash = 0;
    string input;
    cout << "Vvedit strichku ";
    getline(cin, input);

    if(input.length()>1000){
        return "invalid input";
    }

    for(int i = 0; i < input.length(); ++i)
    {
        hash += input[i]*p_pow;
        cout << p_pow << " . " << input[i] << " . " << hash <<endl;
        p_pow *= p;
    }

    cout << hash % d << endl;

    return 0;

}
