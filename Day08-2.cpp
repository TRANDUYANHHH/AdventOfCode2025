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

long long D(int a, int b, int c, int x, int y, int z){
  return 1ll * (a - x) * (a - x) + 1ll * (b - y) * (b - y) + 1ll * (c - z) * (c - z);
}
int cnt;
vector<int> g[1000];
int par[1000];
int ss[1000];
int find(int u) { return u == par[u] ? u : find(par[u]); }
void unite(int u, int v){
  u = find(u);
  v = find(v);
  if(u != v){
    cnt--;
    if(ss[u] < ss[v]) swap(u, v);
    ss[u] += ss[v];
    par[v] = u;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 1000;
  vector<int> x(n), y(n), z(n);
  vector<pair<long long, pair<int, int>>> dis;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> z[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      long long dd = D(x[i], y[i], z[i], x[j], y[j], z[j]);
      dis.emplace_back(dd, make_pair(i, j));
    }
  }
  sort(all(dis));
  for(int i = 0; i < n; i++){
    par[i] = i;
    ss[i] = 1;
  }
  cnt = n;
  int i = 0;
  int ans;
  while(cnt > 1){
    auto [u, v] = dis[i].second;
    unite(u, v); 
    ans = x[u] * x[v];
    i++;
  } 
  cout << ans;
  return 0;  
}
