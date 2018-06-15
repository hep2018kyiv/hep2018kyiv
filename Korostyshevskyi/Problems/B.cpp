#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

int MassToInt (int n[6], int digs){
  int tenpow = 1;
  int ansv = 0;

  for (int i = 0; i < digs; i++){
    ansv += n[i]*tenpow;
    tenpow *= 10;
  }
  return ansv;
}

int main() {

  int N;
  int K;

  cin >> N >> K ;
  int n[6];
  int digs = 0;

  while (N/10 != 0){
    n[digs] = N % 10;
    digs ++;
    N /= 10;
  }
  n[digs] = N;
  digs ++;

  int swap;

  vector<int>  Perestanovki;
  Perestanovki.push_back(MassToInt(n, digs));
  //Perestanovki.push_back(654321);
  int counter;

 if (K > digs) K = digs + (K - digs) % 2;

 for (int i = 0; i < K; i++){

  counter = Perestanovki.size();
  //cout << "counter " << counter << endl;
  for (int i = 0; i < counter; i ++){
    for (int j = 0; j < digs ; j++){
      n[j] = Perestanovki[0]%10;
      Perestanovki[0] /= 10;
    }

    //cout << MassToInt(n, digs)<< endl;
    Perestanovki.erase(Perestanovki.begin());
    for (int j = 0; j < digs - 1; j++){
      for(int k = j + 1; k < digs; k++){
        swap = n[j];
        n[j] = n[k];
        n[k] = swap;
        Perestanovki.push_back(MassToInt(n, digs));
        //cout << j << " " << k << " " << MassToInt(n, digs)<< endl;
        swap = n[j];
        n[j] = n[k];
        n[k] = swap;

      }
    }
  }

  sort (Perestanovki.begin(), Perestanovki.end());

  int cntr = 0;
  while(cntr < Perestanovki.size()-1){
    //cout << Perestanovki[cntr] << endl;
    if (Perestanovki[cntr] == Perestanovki[cntr+1]){
      Perestanovki.erase(Perestanovki.begin()+cntr);
    }
    else cntr ++;
  }

}



  cout << Perestanovki[Perestanovki.size() - 1] << endl;

  return 0;
}
