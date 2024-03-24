#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define oo 1123456789

int N, C;
vector<int> P(1e4+15, 0);
vector<vector<int>> mem(1e4+15, vector<int> (1e4+15, -oo));

int pd(int i, int k) {
  if (i > N && k != 0) {
    return -oo;
  }

  if (i + C*k > (N+1)) {
    return -oo;
  }

  if (i > N && k == 0) {
    return 0;
  }

  if (mem[i][k] != -oo) {
    return mem[i][k];
  }

  if (k == 0) {
    int res = pd(i+1, k) + P[i];
    mem[i][k] = res;
    return res;
  }

  int res = max(pd(i+C, k-1), pd(i+1, k) + P[i]);
  mem[i][k] = res;

  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int k;
  cin >> N >> k >> C;

  for(int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    P[i] = a;
  }

  int res = pd(1, k);

  cout << (res != -oo ? res : 0);
  
}
