#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long unsigned int function_modul(long unsigned int a, long unsigned int b, long unsigned int c) {
	long unsigned int min = (a<b) ? a : b;
	long unsigned int max = (a>b) ? a : b;
        if (a<b)
            {long unsigned int min =a;
            long unsigned int max =b;
            }
        else
        {
           long unsigned int min =b;
            long unsigned int max =a; 
        }
	long unsigned int modul = max % c;
	long unsigned int res = 0;
	for (unsigned int i = 0; i<8 * sizeof(long unsigned int); i++) 
        {
		if ((min >> i) == 0) break;
		if (((min & (1 << i)) >> i) != 0) 
                    res += modul;
                if (res >= c)
                    res -= c;
		modul *= 2;
		if (modul >= c) 
                    modul -= c;
	}
	return res;
}
int main()
{
	long unsigned int A, N, serial;
	long unsigned int B = 1.e+9 + 7;
	cin >> A >> N;
	const unsigned int max_num = 24 * 60*60;
	vector<long unsigned int> vec;
	long unsigned int a[6];
	a[0] = A % B;
	for (int i = 1; i<6; ++i) 
            a[i] = function_modul(a[i - 1], a[0], B);
	long unsigned int date = function_modul(2015, a[0], B) + function_modul(9, a[1], B) + function_modul(24, a[2], B);
	if (date >= B) 
            date %= B;
	for (unsigned int i = 0; i<max_num; i++) {
		long unsigned int date_tmp = date;
		int hour = i / (60*60);
		int min = (i % (60*60)) / (60);
		int sec = i % 60;
		date_tmp += (function_modul(hour, a[3], B) + function_modul(min, a[4], B) + function_modul(sec, a[5], B));
		vec.push_back(date_tmp%B);
	}
	long unsigned int num = 0;
	for (unsigned int i = 0; i<N; i++) {
		cin>> serial;
		if ( find(vec.begin(), vec.end(), serial) != vec.end())
                    ++num;
	}
	cout << num;
	return 0;

}

