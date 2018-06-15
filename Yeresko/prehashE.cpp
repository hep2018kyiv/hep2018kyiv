#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<long long int> populateHashtable(long int N1) {
    set<long long int> result = set<long long int>();
    long long int input;
    for (int i = 0; i < N1; ++i) {
        scanf("%lld", &input);
        result.insert(input);
    }
    return result;
}

int solve(set<long long int> hashes, long int N2) {
    long long int input;
    int result = 0;
    for (int i = 0; i < N2; ++i) {
        scanf("%lld", &input);
        if (hashes.count(input) != 0) {
            result += 1;
        }
    }
    return result;
}

int main() {
    long int N1;
    scanf("%ld", &N1);
    set<long long int> initial = populateHashtable(N1);
    long int N2;
    scanf("%ld", &N2);
    printf("%d\n", solve(initial, N2));
}
