#include <iostream>
#include <string>

using namespace std;

unsigned long long hashf(const string& str, size_t pos = 0) {
    static const unsigned int C = 1009;
    static const unsigned int D = 1000000007;
    if (pos == str.size()) {
        return 0;
    }
    return (hashf(str, pos+1)*C + str[pos])%D;
}

int main(){
    string str;
    cin>>str;
    unsigned long long result = hashf(str);
    cout<<result;
}
