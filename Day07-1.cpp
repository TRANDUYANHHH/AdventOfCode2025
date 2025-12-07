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
  int n = 142;
  vector<string> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int ans = 0; 
  int len = sz(A[0]);
  for(int i = 0; i < len; i++){
    if(A[0][i] == 'S'){
      A[1][i] = '|';
    }
  }
  for(int i = 2; i < n; i += 2){
    for(int j = 0; j < len; j++){
      if(A[i][j] == '^' && A[i - 1][j] == '|'){
        ans++;
        A[i + 1][j - 1] = '|';
        A[i + 1][j + 1] = '|';
      } else if(A[i - 1][j] == '|') {
        A[i + 1][j] = '|';
      }
    }
  }
  cout << ans;
  return 0;  
}
