#include <cmath>
#include <iostream>
using namespace std;

int MaxSearch (int *c, int number)
{
    int Max = -1, I;
    for(int i=0; i<number; i++)
        if(c[i] > Max)
        {
            Max = c[i];
            I = i;
        }
    return I;
}

int c2N(int *c, int number)
{
    int N = 0;
    for(int i=0; i<number; i++)
        N = N + c[i]*pow(10, i);
    
    return N;
}

int main()
{
    int N;
    long long int K;
    cin >> N >> K;
    
    int dim = 0, N1 = N;
    
    while(N1!=0)
    {
        N1 = N1/10;
        dim++;
    }
        
    int *c = new int [dim];
    
    for(int i=0; i<dim; i++)
    {
        c[i] = N%10;
        N = N/10;
    }
        
    bool same = false;
    int d[10];
    for(int i=0; i<10; i++)
        d[i] = 0;
    
    for(int i=0; i<dim; i++)
    {
        d[c[i]]++;
        if (d[c[i]] > 1)
            same = true;
    }
            
    long long int step = 0;
    int dim0 = dim;
    int I, c1;
    
    for(int i=0; i<dim-1; i++)
        if(step < K)
        {
            I = MaxSearch(c, dim0);
            dim0--;
            if(c[I]!=c[dim0])
            {
                if(c[I]==c[I+1] && c[dim0]>c[dim0-1] && K==2)
                {
                    c1 = c[I+1];
                    c[I+1] = c[dim0];
                    c[dim0] = c1;
                    step = step + 1;
                }
                else if(c[I]==c[I+2] && c[dim0]>c[dim0-1] && K==2)
                {
                    c1 = c[I+2];
                    c[I+2] = c[dim0];
                    c[dim0] = c1;
                    step++;
                }
                else
                {
                    c1 = c[I];
                    c[I] = c[dim0];
                    c[dim0] = c1;
                    step++;
                }
            }
        }
        
    if (step==K || same==true)
        cout << c2N(c, dim);
    else
        if((K-step)%2 == 0)
            cout << c2N(c, dim);
        else
        {
            c1 = c[0];
            c[0] = c[1];
            c[1] = c1;
            cout << c2N(c, dim);
        }
        
    return 0;
}