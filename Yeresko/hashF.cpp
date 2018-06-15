#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const long long int B = 1000000007;
const long long bad_day = 24;
const long long bad_month = 9;
const long long bad_year = 2015;

unsigned long long modPow(
    long long int A,
    long long int P,
    long long int B
) {
    if (P == 0) {
        return 1L;
    }
    long long int halfPower = modPow(A, P/2, B);
    long long int result = halfPower * halfPower % B;
    if (P % 2 == 1) {
        return result = result*A % B;
    }
    return result;
}

long long int hashf(
    long long int year,
    long long int month,
    long long int day,
    long long int hour,
    long long int minute,
    long long int second,
    long long int A,
    long long int B
) {
    return (year   * modPow(A, 1, B) +
            month  * modPow(A, 2, B) +
            day    * modPow(A, 3, B) +
            hour   * modPow(A, 4, B) +
            minute * modPow(A, 5, B) +
            second * modPow(A, 6, B)) % B;
}

set<long long int> populateHashtable(long long int A) {
    long long int initial_hash = hashf(bad_year, bad_month, bad_day, 0, 0, 0, A, B);
    long long int A4 = modPow(A, 4, B);
    long long int A5 = modPow(A, 5, B);
    long long int A6 = modPow(A, 6, B);
    set<long long int> result = set<long long int>();
    for (long long int hour = 0; hour < 24; ++hour) {
        long long int hour_hash = (initial_hash + hour*A4)%B;
        for (long long int minute = 0; minute < 60; ++minute) {
            long long int minute_hash = (hour_hash + minute*A5)%B;
            for (long long int second = 0; second < 60; ++second) {
                result.insert((minute_hash + second*A6)%B);
            }
        }
    }
    return result;
}

int solve(set<long long int> hashes, int N) {
    long long int input;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &input);
        if (hashes.count(input) != 0) {
            result += 1;
        }
    }
    return result;
}

int main() {
    long long int A;
    int N;
    scanf("%lld %d", &A, &N);
    printf("%d\n", solve(populateHashtable(A), N));
}
