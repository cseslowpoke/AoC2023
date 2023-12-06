#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;


#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<long long, long long>
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
  vector<pll> seed[2];
  seed[0].clear();
  seed[1].clear();
  long long x, y;
  while(ss >> x >> y) {
    seed[0].eb(x, y);
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
    for(int j = 0; j < (int)seed[i & 1].size(); j++) {
        int flag = 1;
        for(auto [a, b, c]: v) {
            if (seed[i & 1][j].X >= b && seed[i & 1][j].X < b + c) {
                seed[(i + 1) & 1].eb(a + seed[i & 1][j].X - b, min(seed[i & 1][j].Y, b + c - seed[i & 1][j].X));
                if (seed[i & 1][j].Y + seed[i & 1][j].X - 1 >= b + c) {
                    seed[i & 1].eb(b + c, seed[i & 1][j].Y - (b + c - seed[i & 1][j].X));
                }
                flag = 0;
                break;
            }
        }
        if (flag) {
            seed[(i + 1) & 1].eb(seed[i & 1][j].X, seed[i & 1][j].Y);
        }
    }
    v.clear();
    seed[i & 1].clear();
  }
  sort(all(seed[1]));
  cout << seed[1][0].X << endl;
}

signed main() {
//   IO;
  int t = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}