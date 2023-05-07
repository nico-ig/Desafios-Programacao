#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  ll h, a = 0, max = 0;
  vector<ll> hist;
  stack<int> s;
  cin >> n;

  for ( int i = 0; i <= n; i++ )
  {
    if ( i == n ) { h = 0; }
    else { cin >> h; }
    hist.push_back(h);
    
    while ( !s.empty() && hist[s.top()] > h) {
      a = hist[s.top()]; 
      s.pop();
      a *= s.empty()? i : (i - s.top() - 1);
      if ( a > max ) { max = a; }
    }

    s.push(i);
  }

  cout << max << "\n";
}
