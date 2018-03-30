#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long int D = 1000000007;
    int C = 1009;
    string line;
    
    cin >> line;
    int N = line.length();
    
    long long int hash = 0;
    long long int CN = 1;
    
    for(int i=0; i<N; i++)
    {
        hash = (hash + ((int) line[i])*CN) % D;
        CN = (CN*C) % D;
    }
    
    cout << hash;
    
    return 0;
    
}