#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  
  ll t;
  cin >> t;

  while (t--) {
    ll n, d;
    cin >> n >> d;

    ll ex = n / d;
    cout << "[" << ex;

    n = n - d * ex;

    if (n <= d && n > 0)
      cout << ";";
    else
     cout << "]\n";

    while(n <= d && n > 0) {
      ull aux = n;
      n = d;
      d = aux;

      ex = n / d;
      n = n - d * ex;

      if(n <= d && n > 0)
        cout << ex << ",";
      else 
        cout << ex << "]\n";
    }
  }
}
