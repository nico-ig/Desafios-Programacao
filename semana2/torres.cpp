#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, h;
  char d;
  stack<int> towers;
  cin >> n;
  while ( n-- )
  {
    cin >> h >> d;
    if ( d == 'L' )
    {
      if ( towers.empty() || (towers.top() > h) )
        towers.push(h);
      else
      {
        cout << "N\n";
        return 0;
      }
    }

    else
    {
      if ( towers.empty() || (towers.top() != h) )
      {
        cout << "N\n";
        return 0;
      }

      towers.pop();
    }
  }

  if ( towers.empty() )
    cout << "S\n";
  else
    cout << "N\n";

}
