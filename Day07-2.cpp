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
  int n = 142, m = 141;
  vector<string> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  vector<vector<long long>> dp(n, vector<long long>(m));
  for(int i = 0; i < m; i++){
    if(A[0][i] == 'S'){
      dp[1][i] = 1;
    }
  }
  for(int i = 2; i < n; i++) for(int j = 0; j < m; j++) {
    if(A[i - 1][j] != '^') dp[i][j] = dp[i - 1][j];
    if(A[i - 1][j - 1] == '^'){
      dp[i][j] += dp[i - 1][j - 1];
    }
    if(A[i - 1][j + 1] == '^'){
      dp[i][j] += dp[i - 1][j + 1];
    }
  }
  long long ans = 0;
  for(int i = 0; i < m; i++){
    ans += dp[n - 1][i];
  }
  cout << ans;
  return 0;  
}
