#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, x, cnt = 1, pos = 0;
  cin >> n;
  vector<pair<int, int>> v;

  while ( n-- )
  {
    cin >> x;
    v.push_back(make_pair(x, pos++));
  }
  
  sort(v.begin(), v.end());

  for ( int i = 0; i < v.size() - 1; i++ )
  {
    if ( v[i].second > v[i+1].second ) 
      cnt++;
  }

  cout << cnt << "\n";
 }
