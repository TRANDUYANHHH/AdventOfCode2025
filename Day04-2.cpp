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

int A[150][150];
int n;
bool f(int i, int j){
  if(i < 0 || i >= n || j < 0 || j >= n) return false;
  if(A[i][j] == 0) return false;
  int cc = 0;
  for(int k = 0; k < 8; k++){
    int ni = dx[k] + i;
    int nj = dy[k] + j;
    if(ni >= 0 && nj >= 0 && ni < n && nj < n){
      cc += A[ni][nj];
    }
  }
  return cc < 4;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  n = 137;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c;
      cin >> c;
      A[i][j] = (c == '@');
    }
  }
  int ans = 0;
  queue<pair<int, int>> Q;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    if(f(i, j)) {
      Q.emplace(i, j);
    }
  }
  while(!Q.empty()){
    queue<pair<int, int>> nQ;
    while(!Q.empty()){
      auto [i, j] = Q.front(); Q.pop();
      if(A[i][j] == 0) continue;
      A[i][j] = 0;
      ans++;
      for(int k = 0; k < 8; k++){
        if(f(i + dx[k], j + dy[k])){
          nQ.emplace(i + dx[k], j + dy[k]);
        }
      }
    }
    Q = nQ;
  }
  cout << ans;
  return 0;  
}
