#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  map<int, vector<ll>>map;
  int n, valor, cor;
  cin >> n;

  while ( n-- )
  {
    cin >> valor >> cor;
    map[cor].push_back(valor);
  }

  for ( auto im : map )
  {
    vector<ll> v = im.second;
    for ( int i = 0; i < v.size() - 1; i++ )
    {
      if ( v[i] > v[i+1] )
      {
        cout << "NO\n";
        return 0;
      }
    }
  }

  cout << "YES\n";
}
