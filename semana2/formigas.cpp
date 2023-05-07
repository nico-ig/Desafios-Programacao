#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, qtd;
  ll tam, tempoMin, tempoMax, pos, meio;
  cin >> n;

  while ( n-- )
  {
    tempoMin = 0;
    tempoMax = 0;
    cin >> tam >> qtd;
    meio = tam/2;

    while ( qtd-- )
    {
      cin >> pos;

      // tempoMin
      if ( pos <= meio )
      {
        if ( pos > tempoMin )
          tempoMin = pos;
      }

      else
      {
        if ( (tam - pos) > tempoMin )
          tempoMin = (tam - pos);
      }

      // tempoMax
      if ( pos <= meio )
      {
        if ( (tam - pos) > tempoMax )
          tempoMax = tam - pos;
      }

      else
      {
        if ( pos > tempoMax )
          tempoMax = pos;
      }

    }

    cout << tempoMin << " ";
    cout << tempoMax << "\n";
  }

}
