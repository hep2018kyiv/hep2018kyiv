#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>

using namespace std;

unsigned long long advance(unsigned long long hash, const char& out, const char& in, const unsigned long long& Ck) {
    static const unsigned int Cinv = 222993064;
    static const unsigned int D = 1000000007;
    hash = (hash - out)%D;
    hash = hash * Cinv;
    hash = (hash + in*Ck)%D;
    return hash;
}

unsigned long long hashf(const string& str, size_t pos = 0) {
    if (pos == str.size()) {
        return 0;
    }
    static const unsigned long long C = 1009;
    static const unsigned long long D = 1000000007;
    return (hashf(str, pos+1)*C + str[pos])%D;
}

char xToChar(const unsigned long long& x) {
    return 'a' + (x>>16)%26;
}

unsigned long long nextX(const unsigned long long& x) {
    static const unsigned long long A = 1103515245;
    static const unsigned long long B = 12345;
    static const unsigned long long M = 1LL<<32;
    return (x*A + B) % M;
}

unsigned long long calculateCk(const int& K) {
    static const unsigned long long C = 1009;
    static const unsigned long long D = 1000000007;
    if (K == 0) {
        return 1L;
    }
    if (K % 2 == 1) {
        return (C*calculateCk(K-1)) % D;
    }
    return (calculateCk(K/2)*calculateCk(K/2)) % D;
}

char xToCharAndAdvance(unsigned long long& x) {
    char result = xToChar(x);
    x = nextX(x);
    return result;
}

string getStringPart(const int& pos, const int& K, unsigned long long& xAtEnd) {
    string res = "";
    unsigned long long x = 1;
    for (int i = 0; i < pos; ++i, x = nextX(x));
    for (int i = 0; i < K; ++i) {
        res.push_back(xToCharAndAdvance(x));
    }
    xAtEnd = x;
    return res;
}

string solve(const int& N, const int& K, unsigned long long& H) {
    unsigned long long x = 1;
    unsigned long long x_p = 1;
    unsigned long long Ck = calculateCk(K-1);
    string initial = getStringPart(0, K, x);
    unsigned long long hashed = hashf(initial);
    for (int pos = 1; pos <= N-K; ++pos) {
        char in = xToCharAndAdvance(x);
        char out = xToCharAndAdvance(x_p);
        hashed = advance(hashed, out, in, Ck);
        if (hashed == H) {
            return getStringPart(pos, K, x);
        }
    }
    return string("0");
}

int main(){
    unsigned long long N, K, H;
    cin>>N>>K>>H;
    cout<<solve(N, K, H)<<endl;
}
