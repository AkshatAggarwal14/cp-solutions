#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    string s;
    cin >> n >> s;
    n = (1LL << n);
    vector<ll> p(n, 0), pR(n, 0);
    iota(1 + all(p), 1);
    // also reverse on each level
    ll len = n / 2, x = 1;
    while (len > 1) {
        reverse(p.begin() + x, p.begin() + x + len);
        x += len;
        len /= 2;
    }
    reverse(all(p));
    p.pop_back();
    p.insert(p.begin(), 0);
    s = "." + s;
    dbg(s, p);

    for (ll i = 0; i < n; ++i) pR[p[i]] = i;

    vector<ll> SegTree(n, -1);
    auto calc = [&](ll i) {
        if (i >= n / 2) {
            SegTree[i] = ((s[p[i]] == '?') ? 2 : 1);
        } else {
            if (s[p[i]] == '?') {
                SegTree[i] = SegTree[2 * i + 1] + SegTree[2 * i];
            } else if (s[p[i]] == '0') {
                SegTree[i] = (SegTree[2 * i]);
            } else {
                SegTree[i] = (SegTree[2 * i + 1]);
            }
        }
    };

    for (ll i = n / 2; i < n; ++i) calc(i);
    for (ll i = n / 2 - 1; i >= 1; --i) calc(i);

    auto update = [&](ll id, char ch) {
        ll i = pR[id];
        s[p[i]] = ch;
        for (ll j = i; j >= 1; j /= 2) calc(j);
    };

    dbg(SegTree, s, p, pR);
    ll q;
    cin >> q;
    while (q--) {
        ll id;
        char ch;
        cin >> id >> ch;
        update(id, ch);
        dbg(SegTree, s);
        cout << SegTree[1] << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
