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
bool vis[1000];
void dfs(int u){
  vis[u] = true;
  cnt++;
  for(int v : g[u]){
    if(!vis[v]) dfs(v);
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
  for(int i = 0; i < 1000; i++){
    auto [u, v] = dis[i].second;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> S;
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      cnt = 0;
      dfs(i);
      S.push_back(cnt);
    }
  }
  sort(S.rbegin(), S.rend());
  cout << S[0] * S[1] * S[2];
  return 0;  
}
