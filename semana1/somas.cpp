#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  list<int> a;
  int n;

//  int x;
//  while (cin >> x) { cout << x << "."; }

 while (cin >> n)
 {
    int i = n/2;

    int x;
    while ( n-- )
    {
      cin >> x;
      a.push_back(x); 
    }

    ll s;
    ll e = 0;
    while ( i-- )
    {
      cin >> x;
      s = a.front() + a.back();
      a.pop_front();
      a.pop_back();
      e += abs(x-s);
    }

    cout << e << "\n";
  }
}
