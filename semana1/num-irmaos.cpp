#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n;
  cin >> n;
  while ( n-- ) {
     string str;
     cin >> str;

     int bx = str.c_str()[str.size()-1] & 1;

     cin >> str;
     int by = str.c_str()[str.size()-1] & 1;

     if ( by != bx ) 
       cout << "NAO PARCEIROS" << "\n";
     else
        cout << "PARCEIROS" << "\n";
   }
}
