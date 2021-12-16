#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

ll query(ll a, ll b, ll c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    ll res;
    cin >> res;
    if (res == -1) exit(0);
    return res ^ 1;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> queries(n);
    for (ll i = 0; i < n; ++i) queries[i] = query(i, (i + 1) % n, (i + 2) % n);
    ll a = 0, b = 0, c = 0, d = 0;
    for (ll i = 0; i < n; ++i) {
        ll nxt = (i + 1) % n;
        if (queries[i] ^ queries[nxt]) {  // 1 of a or b is impostor
            a = (i + 1) % n;
            b = (i + 2) % n;
        }
    }
    vector<ll> mark(n);  // 1 -> impostor
    for (ll i = 0; i < n; ++i) {
        if (i == a or i == b) continue;
        mark[i] = query(a, b, i);  // if i is impostor, ans[i] = 1, else 0
    }
    for (ll i = 0; i < n; ++i) {
        if (i == a or i == b) continue;
        if (mark[i] == 1) c = i;  // impostor
        if (mark[i] == 0) d = i;  // crewmate
    }
    mark[a] = query(c, d, a);  // determine a,b using c,d
    mark[b] = query(c, d, b);
    vector<ll> res;
    for (ll i = 0; i < n; ++i)
        if (mark[i]) res.push_back(i + 1);  // push impostors in vector
    cout << "! " << sz(res) << ' ';
    for (ll &i : res) cout << i << ' ';
    cout << endl;
}

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}