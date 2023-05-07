#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt_tupla(int n) {
  int cnt = 0, c;
    for ( int b = 1; b < n/3 * 2; b++ ) 
      for ( int a = 1; a <= b; a++ )
      {
        c = n - b - a;
        cnt = c >= b ? cnt+1 : cnt;
      }

  return cnt;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  cin >> n;
  cout << cnt_tupla(n) << "\n";
}
