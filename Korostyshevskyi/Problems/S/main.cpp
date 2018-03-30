
#include "cmath"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{

int n = 0;
cin >> n;
double a[200000];
for (int i = 0; i < n; i++){
  cin >> a[i];
}
  int ans = a[0],
	sum = 0,
	min_sum = 0;
for (int r=0; r<n; ++r) {
	sum += a[r];
	ans = max (ans, sum - min_sum);
	min_sum = min (min_sum, sum);

}

    cout << ans;
    return 0;
}
