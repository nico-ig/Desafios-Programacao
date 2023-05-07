#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  cin >> n;

  int n1 = n;
  ull b;
  vector<ull> v;
  while ( n1-- )
  {
    cin >> b;
    v.push_back(b);
  }

  sort(v.begin(), v.end()); 

  //Acha a razao
  if ( v[0] == 0 || v[1] == 0 || v[2] == 0 ) { cout << "0\n"; return 0;}
  ull r1 = v[1] / v[0];
  ull r2 = v[2] / v[1];
  ull r3 = v[3] / v[2];

  ull r;
  if ( r1 != r2 ) {
    r = r3 == r1 ? r1 : r2;
  }
  else
    r = r1;

  queue<ull> exp1, exp2;

  exp1.push(v[0]);
  if ( r == 0 ) { exp2.push(0); }
  else
    exp2.push(v[0]/r);

  for ( int i = 1; i <= n; i++ )
  {
    exp1.push(exp1.back() * r);
    exp2.push(exp2.back() * r);
  }

  //v0 eh a2
  if ( exp2.back() == v[n-1] )
    cout << exp2.front() << "\n";

  if ( v[0] == v[1] ) return 0;

  // v0 eh a1
  for ( int i = 0; i < n; i++ ) {
    if ( exp1.front() != v[i] ) 
    {
      i--;  
      cout << exp1.front() << "\n";
    }
    exp1.pop();
  }

  // Ultimo ta faltando
  if ( !exp1.empty() )
    cout << exp1.front() << "\n";
} 
