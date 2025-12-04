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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 137;
  vector<string> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    if(a[i][j] == '.') continue;
    int cc = 0;
    for(int k = 0; k < 8; k++){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if(ni >= 0 && nj >= 0 && ni < n && nj < n && a[ni][nj] == '@'){
        cc++;
      }
    }
    if(cc < 4) {
      ans++;
    }
  }
  cout << ans;
  return 0;  
}
