#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef LOCAL    // =========== Local ===========
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else            // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long int
// #define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define rep(i,a) for (ll i=0;i<a;i++)
#define IO ios::sync_with_stdio(false); cin.tie(0)

template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
const int mod = 1e9 + 7, N = 1 << 20, INF = 0x3f3f3f3f;



void solve() {
  
  string a;
  long long b;
  vector<pair<string, long long> > v;
  while(cin>>a>>b) {
    v.push_back({a, b});
  }
  map<char, int> mp = {{'A', 13}, {'K', 12}, {'Q', 11}, {'J', 10}, {'T', 9}, {'9', 8}, {'8', 7}, {'7', 6}, {'6', 5}, {'5', 4}, {'4', 3}, {'3', 2}, {'2', 1}};
  sort(all(v), [&](pair<string, long long> a, pair<string, long long> b) {
    auto &[sa, tmp] = a;
    auto &[sb, tmp2] = b;
    char ma[256] = {}, mb[256] = {};
    for(int i = 0; i < (int)sa.size(); i++) {
      ma[sa[i]]++;
    }
    for(int i = 0; i < (int)sb.size(); i++) {
      mb[sb[i]]++;
    }
    sort(ma, ma + 256, greater<char>());
    sort(mb, mb + 256, greater<char>());
    for(int i = 0; i < 256; i++) {
      if(ma[i] != mb[i]) {
        return ma[i] < mb[i];
      }
    }
    for(int i = 0; i < 4; i++) {
      if(sa[i] != sb[i]){
        return mp[sa[i]] < mp[sb[i]];
      }
    }
    return mp[sa[4]] < mp[sb[4]];
  });
  long long sum = 0;
  // reverse(all(v));
  for(int i = 0; i < (int)v.size(); i++) {
    cout << v[i].second << ' ' << v[i].first << '\n';
    sum += (i + 1) * v[i].second;
  }
  cout << sum << '\n';
}

signed main() {
  IO;
  int t = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}