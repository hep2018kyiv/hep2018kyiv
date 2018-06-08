#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;


int main()
{    
    map<unsigned int, unsigned int> animals;
    
    unsigned int N, M, i, x;
    unsigned int color;
    cin >> N;
    for(i=0; i < N; ++i) 
    {
        cin >> color;
        ++animals[color];
    }
    
    cin >> M;
    for(i=0; i < M; ++i) 
    {
        cin >> x;
        cout << animals[x] << " ";
    }    

    return 0;
}
