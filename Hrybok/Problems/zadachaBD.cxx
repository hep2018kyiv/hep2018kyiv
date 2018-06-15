#include <iostream>

long long func(int n, int l) {
 static long long m[501][501];
 if (m[n][l] == 0) {
 long long q = 0;
 for (int ryad = n, strich = l; ryad - strich > strich; ++strich) q += 1 + f(ryad - strich, strich + 1);
 m[n][l] = q;
 }
 return m[n][l];
}
 
int main() {
 int n;
 std::cin >> n;
 std::cout << func(n, 1)<<std::endl;
}
