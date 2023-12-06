#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;


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
  string tmp;
  cin >> tmp;
  getline(cin, tmp);
  stringstream ss(tmp);
  vector<long long> seed[2];
  seed[0].clear();
  seed[1].clear();
  long long x;
  while(ss >> x) {
    seed[0].pb(x);
  }
  getline(cin, tmp);
  vector<tuple<long long,long long,long long> > v;
  for(int i = 0; i < 7; i++) {
    while(true) {
      getline(cin, tmp);
      if('a' <= tmp[0] && tmp[0] <= 'z'){
        break;
      }
      stringstream ss(tmp);
      long long a, b, c;
      ss >> a >> b >> c;
      v.push_back({a, b, c});
    }
    for(auto j: seed[i & 1]) {
      int flag = 1;
      for(auto [a, b, c]: v) {
        if(j >= b && j < b + c) {
          seed[(i + 1) & 1].pb(a + j - b);
          flag = 0;
          break;
        }
      }
      if(flag) {
        seed[(i + 1) & 1].pb(j); 
      }
    }
    v.clear();
    seed[i & 1].clear();
    for(auto j: seed[(i+1) &1]) cout << j << ' ';
        cout << '\n';
  }
  sort(all(seed[1]));
  cout << seed[1][0] << endl;

}

signed main() {
  // IO;
  int t = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}