#include "stdafx.h"
#include <iostream>
using namespace std;
// change for test
int main()
{
    int R, N;   // field size, number of robots;
    
    cin >> R >> N;
    
    int x[5001];
    int y[5001];   // coordinates of robots
    
    for(int i=1; i<=N; i++)
        cin >> x[i] >> y[i];
    
    int S = 0;                      // number of opened robots
    
    for(int i=1; i<=N; i++)
    {
        double azimuth[5001];
        int chir[5001];
        
        for(int j=i+1; j<=N; j++)
        {
            if(x[i] == x[j])
            { 
                azimuth[j] = 10000;
                if(y[j] > y[i])
                    chir[j] = 1;
                else
                    chir[j] = 0;
            }
            else
            {
                azimuth[j] = 1.*(y[j]-y[i])/(x[j]-x[i]);
                if(x[j] > x[i])
                    chir[j] = 1;
                else 
                    chir[j] = 0;
            }
            
            int flag = 0;
            for(int k=i+1; k<j; k++)
                if(azimuth[k] == azimuth[j] && chir[k] == chir[j])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                S = S+1;
                        
        }
        
    }
    S = 2*S;
    
    cout << S;    
    
    return 0;
}