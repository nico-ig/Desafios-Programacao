#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  list<ll> fita; 
  auto cabeca = fita.begin();
  auto auxit = fita.begin();

  int n, ic, iv, mc;
  char op;
  cin >> n;

  while ( n-- )
  {
    cin >> op;

    switch ( op )
    {
      case 'm':
        cin >> mc;
        if ( mc < 0 ) {
          for ( int i = 0; i < abs(mc); i++ )
            cabeca = --cabeca;
        }
        else {
          for ( int i = 0; i < abs(mc); i++ )
            cabeca = ++cabeca;
        }
      break;

      case 'i':
        cin >> ic >> iv;
        fita.insert(cabeca, ic, iv); 

        for ( int i = 0; i < ic; i++ )
          cabeca = --cabeca;
      break;

      case 'd':
      cabeca = fita.erase(cabeca);
        
      break;

      case 'q':
        cout << *cabeca << "\n"; 
      break;

    }

  }
}
