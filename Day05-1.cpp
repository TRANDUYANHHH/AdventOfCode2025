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
  int n = 185, q = 1000;
  vector<pair<long long, long long>> a;
  for(int i = 0; i < n; i++){
    long long x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  int ans = 0;
  while(q--){
    long long ii;
    cin >> ii;
    for(auto [l, r] : a){
      if(ii >= l && ii <= r){
        ans++;
        break;
      }
    }
  }
  cout << ans;
  return 0;  
}
