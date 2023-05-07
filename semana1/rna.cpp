#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  string str;
  cin >> n >> str;

  size_t ini = str.find("AAAAAAA");
  size_t fim = str.rfind("AAAAAAA");

  if ( ini == -1 ) { cout << 0 << "\n"; } 
  else
  {
    int sz = fim - ini + 7;
    cout << sz << "\n"; 
  }
}
