#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int t;
  cin >> t;

  vector<pair<int, int>> events;
  while (t--)
  {
    int e, s;
    cin >> e >> s;

    events.push_back({e, 1});
    events.push_back({s, -1});
  }

  sort(events.begin(), events.end());

  int curr = 0, max = -1;
  for ( auto ev : events )
  {
    curr += ev.second;
    if ( curr > max ) { max = curr; }
  }

  cout << max << "\n";
}


