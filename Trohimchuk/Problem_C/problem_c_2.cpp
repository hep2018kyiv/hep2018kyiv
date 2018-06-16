#include <iostream>

using namespace std;

int find_robots_2(double a, double b, int k){
    double kk_a = a /2.0;
    double kk_b = b/2.0;
    if (((int)kk_a == kk_a )&& ((int)kk_b == kk_b)){ 
        (k == 0) ? k=1 : k=k*2+1;
       k = find_robots_2(kk_a, kk_b, k);
    }
    if ((((int)kk_a != kk_a ) || ((int)kk_b != kk_b) ) && kk_a>1 && kk_b>1 ){ 
        double kp;
        (kk_a>kk_b) ? kp=kk_a/kk_b : kp=kk_b/kk_a;
        if ((int)kp==kp)  (k +=(int)(kp-1)) ; 
    }
    
    return k;
}


int main(){
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int a = 0;
    int b = 0;
    int k = 0;
    cin>> x1>>y1>>x2>>y2;
    a = y2 - y1;
    b = x2 - x1;
    if(a<0)  a*=-1;
    if(b<0)  b*=-1;
    a == 0 ? k=b-1 : k=0;
    b == 0 ? k=a-1 : k=k;
    if((x1=y1) && (x2==y2) && (x1 !=x2))   x2>x1 ? k = x2-x1-1 : k=x1-x2-1;  
    if (k ==0) k = find_robots_2(a*1.0, b*1.0, k);
    //cout<<"k= "<<k<<endl;
    if (k <0) k*=(-1);

    k == -1 ? cout<<0 : cout<<k;

}
