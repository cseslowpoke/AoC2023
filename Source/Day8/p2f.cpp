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
  map<string, pair<string, string> > mp;
  string op;
  cin >> op;
  string a, b, c, tmp;
  while(cin >> a >> tmp >> b >> c) {
    mp[a] = {b.substr(1, 3), c.substr(0, 3)};
  }
  long long ans = 0;
  vector<string> now;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      string s = string(1, 'A' + i) + string(1, 'A' + j) + "A";
      if(mp.count(s)) {
        now.push_back(s);
      }
    }
  }
  cout << now.size();
  for(;;ans++) {
    cout << ans << '\n';
    if(op[ans % op.size()] == 'L') {
      for(int i = 0; i < now.size(); i++) {
        now[i] = mp[now[i]].X;
      }
    }
    else {
      for(int i = 0; i < now.size(); i++) {
        now[i] = mp[now[i]].Y;
      }
    }
    int flag = 1;
      for(int i = 0; i < now.size(); i++) {
        if(now[i][2] != 'Z') {
          flag = 0;
          break;
        }
      }
      if(flag) {
        break;
      }
  }
  cout << ans << '\n';
}

signed main() {
  IO;
  int t = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}