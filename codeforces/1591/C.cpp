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

// make pair with count of contiguous..
vector<pair<ll, ll>> compress(const vector<ll> &t) {
    if (t.empty()) return {};
    vector<pair<ll, ll>> res;
    ll cnt = 0, last = t[0];
    for (ll i = 0; i < sz(t); ++i) {
        if (t[i] == last) {
            cnt++;
        } else {
            res.push_back({last, cnt});
            last = t[i], cnt = 1;
        }
    }
    if (cnt) res.push_back({last, cnt});
    return res;
}

void Solution() {
    ll n, k, num;
    cin >> n >> k;
    vector<ll> pos, neg;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        ((num > 0) ? pos : neg).push_back(abs(num));
    }
    sort(all(pos));
    sort(all(neg));
    ll ans1 = 0, ans2 = 0, l1 = 0, l2 = 0;
    for (ll i = sz(pos) - 1; i >= 0; i -= k) {
        ll s = 0;
        for (ll j = i; j >= i - k && j >= 0; --j) {
            amax(s, pos[j]);
        }
        if (i == sz(pos) - 1) {
            ans1 += s;
            l1 = s;
        } else
            ans1 += 2 * s;
    }
    dbg(ans1, l1);
    for (ll i = sz(neg) - 1; i >= 0; i -= k) {
        ll s = 0;
        for (ll j = i; j >= i - k && j >= 0; --j) {
            amax(s, neg[j]);
        }
        if (i == sz(neg) - 1) {
            ans2 += s;
            l2 = s;
        } else
            ans2 += 2 * s;
    }
    dbg(ans2, l2);
    cout << ans1 + ans2 + min(l1, l2) << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}