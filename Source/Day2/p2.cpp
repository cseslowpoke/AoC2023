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
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long int
#define mp make_pair
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
  map<char,int> mp;
  mp['r'] = 0;
  mp['g'] = 1;
  mp['b'] = 2;
  string tmp;
  // int sz[3] = {12, 13, 14};
  int sum = 0;
  for(int i = 1; cin >> tmp >> tmp; i++) {
    string s, t;
    getline(cin, s);
    stringstream ss(s);
    // bool flag = true;
    int sz[3] = {};
    while(ss >> s >> t) {
      sz[mp[t[0]]] = max(sz[mp[t[0]]], stoi(s));
    }
    sum += sz[0] * sz[1] * sz[2];
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