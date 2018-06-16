#include <iostream>
using namespace std;
int N;
int rez[10];

int main(){
    cin>>N;
    for (int i=9; i>1; i--){
        if (N%i==0){
            
            N = N / i;
            rez[i]+=1;
            i = 10;
                        
        }
        if (N<10){
            rez[N]+=1;
            break;
        }
    }
    if (N>9){
        cout<<-1;
    }
    else{
        while(rez[2]>1){
            rez[2]-=2;
            rez[4]+=1;
        }
        while(rez[3]>1){
        rez[3]-=2;
        rez[9]+=1;
        }
        if(rez[2]==1 && rez[4]==1){
            rez[2]-=1;
            rez[4]-=1;
            rez[8]+=1;
        }
        if(rez[2]==1 && rez[3]==1){
            rez[2]-=1;
            rez[3]-=1;
            rez[6]+=1;
        }

        for(int i=0; i<10;i++){
            if(rez[i]==0){
                continue;
            }
            else{
                while(rez[i]!=0){
                    cout<<i;
                    rez[i]-=1;
                }
            }
        }
    }
}