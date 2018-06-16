#include <iostream>
#include <set>
#include <cmath>
using namespace std;



const long long int B = 1000000007;

const long long year = 2015;
const long long day = 24;
const long long month = 9;

long long int hash_function(long long int year, long long int month, long long int day, long long int hour,
			    long long int minute, long long int second, long long int A) {
    return (year   * pow(A, 1) +
            month  * pow(A, 2) +
            day    * pow(A, 3) +
            hour   * pow(A, 4) +
            minute * pow(A, 5) +
            second * pow(A, 6));
}

set<long long int> allHash(long long int A) {
    long long int started_hash = hash_function(year, month, day, 0, 0, 0, A)%B;
    
    long long int A4 = pow(A, 4);
    long long int A5 = pow(A, 5);
    long long int A6 = pow(A, 6);
    
    set<long long int> all_hashes = set<long long int>();
    
    for (long long int hour = 0; hour < 24; ++hour) {
      
        long long int hour_hash = (started_hash + hour*A4)%B;
	
        for (long long int minute = 0; minute < 60; ++minute) {
          
	  long long int minute_hash = (hour_hash + minute*A5)%B;
           
	  for (long long int second = 0; second < 60; ++second) {
          
	    all_hashes.insert((minute_hash + second*A6)%B);
            
	    
	  }
        }
    }
    return all_hashes;
}


int main() {
    long long int A;
    int N;
    cin>>A>>N;
     long long int input;
    int all_hashes = 0;
    set<long long int> hashes;
    hashes = allHash(A);
    for (int i = 0; i < N; ++i) {
        cin>>input;
        if (hashes.count(input) != 0) {
            all_hashes += 1;
        }
    }
    cout<<  all_hashes;
}
