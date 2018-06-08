#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main()
{

    map<unsigned long int, unsigned long int> serNumb;
    unsigned long int A, N, i;
    cin>>A>>N;
    
    unsigned long int num;
    unsigned long int A2_temp = (A*A)%1000000007;
    unsigned long int A3_temp = (A2_temp*A)%1000000007;
    for (int iH=0; iH<24; iH++)
        for (int iM=0; iM<60; iM++)
            for (int iS=0; iS<60; iS++){
                num = (2015*A % 1000000007 + 9*A2_temp + 24*A3_temp) % 1000000007 + A2_temp*(iH*A2_temp + iM*A3_temp + iS*A2_temp*A2_temp % 1000000007) % 1000000007;
                ++serNumb[num];
            }
    unsigned int nPhones=0;                
    for(i=0; i < N; ++i) 
    {
        scanf("%lu",&num);
        if (serNumb[num] != 0)
            ++nPhones;
    }    

    printf("%u",nPhones);
    
    return 0;
}