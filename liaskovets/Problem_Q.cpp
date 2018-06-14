#include <iostream>
#include <string>
using namespace std;
int C = 1009;
int D = 1000000007;

long long int hash(string & stroka, size_t count = 0) {
    if (count == stroka.size())
    {    return 0;
    }
    else
    return (hash(stroka, count+1)*C + stroka[count])%D;
}

int main(){
    string stroka;
    cin>>stroka;
    long long int result = hash(stroka);
    int a = stroka[0];
   // cout<<a<<endl;
    cout<<result<<endl;;
}
