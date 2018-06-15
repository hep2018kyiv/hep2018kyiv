#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string a;
    long long p=0, max=0, i, n;
    int  buff;
    while(cin >> a){
    n=a.size();
    for(i=0; i<n; i++){
        if(a[i]>='0' && a[i]<='9') buff = a[i]-'0';
        else buff = a[i]-'A'+10;
        p += buff;
        if(buff>max) max=buff;
    }
    if(max==0){
        cout << "2" << endl;
        return 0;
    }
    else if (i==37) cout << "No solution." << endl;
    else{
        for(i=max+1; i<=36; i++){
            if( p%(i-1)==0 ){
                cout << i << endl;
                return 0;
            }
        }
    }
}
    return 0;
}
