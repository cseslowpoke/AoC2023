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
  vector<string> v;
  string s;
  // cin >> s;
  while(cin >> s) {
    v.pb(s);
    // cout << s << '\n';
  }
  int n = v.size(), m = v[0].size();
  int sum = 0, now, left;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if('0' <= v[i][j] && v[i][j] <= '9') {
        // cout << v[i][j] << ' ' << i << ' ' << j << '\n';
        left = j;
        now = v[i][j] - '0';
        while(j + 1 < m && '0' <= v[i][j + 1] && v[i][j + 1] <= '9') {
          now = now * 10 + v[i][++j] - '0';
        }
        bool flag = false;
        for(int ii = max(0, i - 1); ii <= min(n - 1, i + 1); ii++) {
          for(int jj = max(0, left - 1); jj <= min(m - 1, j + 1); jj++) {
            // cout << ii << ' ' << jj << '\n';
            if(v[ii][jj] != '.' && (v[ii][jj] < '0' || v[ii][jj] > '9')) {
              flag = true;
              break;
            }
          }
          if(flag) {
            // cout << now << '\n';
            sum += now;
            break;
          }
        }
      }
    }
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