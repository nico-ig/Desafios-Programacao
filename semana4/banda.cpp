#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  cin >> n;

  string s;
  for ( int i = 1; i <= n; i++ ) {
    cin >> s;

    size_t pos = 0;
    int cnt = 0;

    while ( (pos = s.find("_", pos)) != string::npos ) { 
      cnt++;
      pos+=3;
    }

    cout << "Caso " << i << ": " << cnt << "\n";
  }
}
