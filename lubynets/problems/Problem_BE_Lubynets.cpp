#include <iostream>
#include <cmath>
using namespace std;

int maxRad(int I, int J, int w, int h)
{
    int Min = I;
    if(J < Min)
        Min = J;
    if(w-I-1 < Min)
        Min = w-I-1;
    if(h-J-1 < Min)
        Min = h-J-1;
    
    return Min;
}

int main()
{
    int w, h;
    char c[200][200];
    cin >> w >> h;
    
    for(int j=0; j<h; j++)
        for(int i=0; i<w; i++)
            cin >> c[i][j];
        
    int num[100];
    for(int i=0; i<100; i++)
        num[i] = 0;
    int DX[100][163];
    int DY[100][163];
    
    int r;
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            r = (int) (sqrt(i*i + j*j)+1);
            if(r - sqrt(i*i + j*j) == 1)
                r--;
            if(r > 99)
                break;
            DX[r][num[r]] = i;
            DY[r][num[r]] = j;
            num[r]++;
        }
    
    int radius = 0;
    
    for(int i=1; i<=w-2; i++)
        for(int j=1; j<=h-2; j++)
            if(c[i][j]=='*')
            {
                bool moon = true;
                for(int R=1; R<=maxRad(i, j, w, h); R++)
                {
                    for(int k=0; k<num[R]; k++)
                        if(c[i+DX[R][k]][j+DY[R][k]]=='.' || \
                           c[i+DX[R][k]][j-DY[R][k]]=='.' || \
                           c[i-DX[R][k]][j+DY[R][k]]=='.' || \
                           c[i-DX[R][k]][j-DY[R][k]]=='.')
                        {
                            moon = false;
                            break;
                        }
                    if(moon == true && R>radius)
                        radius = R;
                }
            }
            
    cout << radius;
    
    return 0;    
}