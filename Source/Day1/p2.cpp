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

string s[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
// int sz[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};



signed main() {
  IO;
  string s;
  long long sum = 0;
  auto check = [](string &s, int p) {
    for (int i = 0; i < 9; i++) {
      if(s.substr(p, sz[i]) == ::s) return i + 1;
    }
    for(int i = 0; i < 9; i++) {
      string tmp; 
      tmp += char(i + 1 + '0');
      if(s.substr(p, 1) == tmp) return i + 1;
    }
    return 0;
  };

  while(cin >> s) {
    for(int i = 0; i < (int)s.size(); i++) { 
      if(check(s, i)) {
        sum += check(s, i) * 10;
        break;
      }
    }
    for(int i = s.size() - 1; i >= 0; i--) { 
      if(check(s, i)) {
        sum += check(s, i);
        break;
      }
    }
    // sum += (*find_if(all(s), [](char &c) { return '0' <= c && c <= '9';}) - '0') * 10 +
    //        (*find_if(rall(s), [](char &c) { return '0' <= c && c <= '9';}) - '0');
  }
  cout << sum << '\n';
}