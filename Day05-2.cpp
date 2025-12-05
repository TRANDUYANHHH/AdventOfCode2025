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
  int n = 185;
  vector<pair<long long, long long>> a(n);
  for(int i = 0; i < n; i++){
    long long l, r;
    cin >> l >> r;
    a[i] = make_pair(l, r);
  }
  sort(all(a));
  vector<pair<long long, long long>> seg;
  for(int i = 0; i < n;){
    long long l = a[i].first;
    long long r = a[i].second;
    int il = i;
    while(il < n && a[il].first <= r){
      r = max(r, a[il].second);
      il++;
    }
    seg.emplace_back(l, r);
    i = il;
  }
  long long ans = 0;
  for(auto [l, r] : seg){
    ans = ans + (r - l + 1);
  }
  cout << ans;
  return 0;  
}
