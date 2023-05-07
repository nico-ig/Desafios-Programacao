#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  string str;
  cin >> n >> str;

  if ( str[n-1] != 's' ) { cout << str[n-1] << "\n"; }
  else                   { cout << str[n-2] << str[n-1] << "\n"; }
}
