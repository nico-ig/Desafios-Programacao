#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  ll n;
  while (cin >> n) {
    ll h,c, l;
    cin >> h >> c >> l;
    unsigned long long cat1 = h*n;
    unsigned long long cat2 = c*n;
    long double hip = sqrt(cat1*cat1 + cat2*cat2);
    long double a = hip * l; 
    cout << setprecision(4) << fixed << a/10000 << "\n";
  }
}
