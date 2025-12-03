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

long long f[13];

long long F(string s){
  int n = sz(s);
  vector<vector<long long>> dp(2, vector<long long>(13));
  int cur = 0;
  dp[1][1] = s[n - 1] - '0';
  for(int i = n - 2; i >= 0; i--){
    for(int j = 1; j <= min(12, n - i); j++){
      dp[cur][j] = max(f[j - 1] * (s[i] - '0') + dp[1 - cur][j - 1],  dp[1 - cur][j]);
    }
    cur = 1 - cur;
  }
  return dp[1 - cur][12];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  f[0] = 1;
  for(int i = 1; i <= 12; i++){
    f[i] = f[i - 1] * 10;
  }
  int n = 200;
  long long ans = 0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    ans += F(s);
  }
  cout << ans;
  return 0;  
}
