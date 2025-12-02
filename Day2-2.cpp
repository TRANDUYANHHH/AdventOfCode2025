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

set<long long> se;
vector<long long> nums;
vector<long long> pref;
long long to_num(string s){
  long long x = 0;
  for(char c : s){
    x = x * 10ll + (c - '0');
  }
  return x;
}

void prepare(){
  for(int i = 1; i <= 99999; i++){
    int len = sz(to_string(i));
    string t = to_string(i);
    string tt = t + t;
    for(int j = len * 2; j <= 10; j += len){
      se.insert(to_num(tt));
      tt += t;
    }
  }
  for(auto x : se) nums.push_back(x);
  pref.assign(sz(nums) + 1, 0);
  for(int i = 1; i <= sz(nums); i++){
    pref[i] = pref[i - 1] + nums[i -1];
  }
}

long long f(long long x){
  auto it = upper_bound(all(nums), x) - nums.begin();
  return pref[it];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  prepare();
  int n = 30;
  long long ans = 0;
  for(int i = 0; i < n; i++){
    long long l, r;
    cin >> l >> r;
    ans = ans + f(r) - f(l - 1);
  }
  cout << ans;
  return 0;  
}
