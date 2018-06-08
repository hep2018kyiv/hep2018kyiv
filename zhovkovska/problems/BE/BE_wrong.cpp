#include <iostream>
#include <fstream>
using namespace std;



int main()
{    
    
    int w, h, iC=-1, jC=-1;
    char x;
    int maxR=-1, rad=0;
    cin >> w >> h;
    
    int picD[h][w], picU[h][w], pic[h][w];
    for(int i=0; i < h; ++i) {
        for(int j=0; j < w; ++j) {
            cin >> x;
            if (x == '.'){
                picD[i][j] = 0;
                picU[i][j] = 0; }
            else {
                picD[i][j] = 1;
                picU[i][j] = 1; }
        }
    }
    
    
    for(int i=1; i < h; ++i) 
        for(int j=0; j < w; ++j) 
            if (picU[i][j] != 0){
                picU[i][j] = std::min( picU[i-1][j],picU[i][j-1] )+1;
            }
            
    for(int i=h-2; i > -1; --i) 
        for(int j=1; j < w; ++j) {
            if (picD[i][j] != 0){
                picD[i][j] = std::min( picD[i+1][j],picD[i][j-1] )+1;
            }
        }
                
                
    for(int i=0; i < h; ++i){ 
        for(int j=0; j < w; ++j){ 
            pic[i][j] = std::min(picD[i][j], picU[i][j]);
            std::cout<<pic[i][j]<<" ";
            if (maxR < pic[i][j]){ 
                maxR = pic[i][j];
                iC = i;
                jC = j;
            }
        }
        std::cout<<std::endl;    
    }                
    cout << maxR-1;
    //     cout << maxR-1 << endl;
    //     cout << jC+1 << " " << iC+1;
    return 0;
}
