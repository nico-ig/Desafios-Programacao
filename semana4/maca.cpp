#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll qtdR, qtdG, cntC, cntR, cntG;
  cin >> qtdR >> qtdG >> cntR >> cntG >> cntC; 

  ll x;
  vector<pair<ll, char>> v;
  while ( cntR-- ) {
    cin >> x;
    v.push_back({x, 'r'});
  }

  while ( cntG-- ) {
    cin >> x;
    v.push_back({x, 'g'});
  }

  while ( cntC-- ) {
    cin >> x;
    v.push_back({x, 'c'});
  }

  sort(v.begin(), v.end());

  pair<ll, char> p;
  ll qtdC = 0;
  ll cnt = 0;

  while ( (qtdR > 0 || qtdG > 0) && (qtdC < qtdR + qtdG) ) {
    p = v.back(); v.pop_back();

    if ( p.second == 'r') {
      if ( qtdR > 0 ) { qtdR--; cnt+=p.first; }

    } else if ( p.second == 'g' ) {
        if ( qtdG > 0 ) { qtdG--; cnt+=p.first; }

    } else { 
      cnt+=p.first;

      if ( qtdR == 0 ) { qtdG--; }
      else if ( qtdG == 0 ) { qtdR--; }
      else { qtdC++; }
    }

  }

  cout << cnt << "\n";
}
