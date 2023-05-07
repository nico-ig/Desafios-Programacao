#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> s(6);
vector<ll> v;
ll cnt = 0;

void gen(set<int> solved, ll n, ll i) {
  if ( i == 6 ) {
    if ( (s[0]*s[1] + s[2])/s[3] - s[4] == s[5] ) { 
      cnt++; 
      solved.insert(s[1]);
//      for ( ll e : s ) { cout << e << " "; }
//      cout << "\n";
    }
    return;
  }

  for ( int k = 0; k < n; k++ ) {
    if ( i == 0 ) {
      if ( solved.find(v[k]) != solved.end() ) { cnt = cnt*2; continue; }
    }
    else if ( i == 3 ) {
      if ( v[k] == 0 ) { continue; }
      if ( (s[0]*s[1] + s[2]) % v[k] != 0 ) { continue; }
    }

    s[i] = v[k];
    gen(solved, n, i+1);
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n;
  cin >> n;

  ll a;
  for ( int i = 0; i < n; i++ ) { cin >> a; v.push_back(a); }

  set<int> solved;
  gen(solved, n, 0);

  cout << cnt << "\n";
}
