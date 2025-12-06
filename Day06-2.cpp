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
  int line = 4;
  int n = 1000;
  vector<string> A(line);
  for(int i = 0; i < line; i++){
    getline(cin, A[i]);
  }
  vector<char> S(n);
  for(int i = 0; i < n; i++){
    cin >> S[i];
  }
  int ii = sz(A[0]) - 1;
  int cur = n - 1;
  long long ans = 0;
  while(ii >= 0){
    int jj = ii;
    vector<int> nums;
    while(jj >= 0){
      int cnt = 0;
      int x = 0;
      for(int i = 0; i < line; i++){
        if(A[i][jj] == ' '){
          cnt++;
        } else {
          x = x * 10 + (A[i][jj] - '0');
        }
      }
      if(cnt == line){
        break;
      }
      jj--;
      nums.push_back(x);
    }
    if(S[cur] == '*'){
      long long tt = 1;
      for(auto x : nums){
        tt = tt * x;
      }
      ans += tt;
    } else {
      long long tt = 0;
      for(auto x : nums){
        tt = tt + x;
      }
      ans += tt;
    }
    cur--;
    nums.clear();
    ii = jj - 1;
  }
  cout << ans;
  return 0;  
}
