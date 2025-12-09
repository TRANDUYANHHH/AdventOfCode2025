#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
template<typename T> bool chmin(T &x, T y) { return (y < x ? x = y, 1 : 0); }
template<typename T> bool chmax(T &x, T y) { return (y > x ? x = y, 1 : 0); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 496;
  vector<pair<int, int>> a;
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
    int dx = abs(a[i].first - a[j].first) + 1;
    int dy = abs(a[i].second - a[j].second) + 1;
    chmax(ans, 1ll * dx * dy);
  }
  cout << ans;
  return 0;  
}
