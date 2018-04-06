#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;


int main()
{
    
    map<unsigned int, unsigned int> serNumb;
    
    unsigned int N, K, i, nPhones=0;
    unsigned long int num;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> num;
        ++serNumb[num];
    }
    cin >> K;
    for(i=0; i < K; ++i) 
    {
        cin>>num;
        if (serNumb[num] != 0)
           ++nPhones;
    }    

    cout<<nPhones;

    return 0;
}
