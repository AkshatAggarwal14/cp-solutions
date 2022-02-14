#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

pair<ll, ll> findClosest(const vector<ll> &x, ll target) {
    ll mid;
    ll lo = 0;
    ll hi = sz(x) - 1;
    while (hi - lo > 1) {
        mid = ((lo + hi) / 2);
        if (x[mid] < target) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return {x[lo], x[hi]};
    // if (target - x[lo] <= x[hi] - target) return x[lo];
    // return x[hi];
}

// make almost equal, for each r, choose smallest g >= r, then b is lowerbound mean
void Solution() {
    ll nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<ll> rr(nr), gg(ng), bb(nb);
    for (ll &R : rr) cin >> R;
    for (ll &G : gg) cin >> G;
    for (ll &B : bb) cin >> B;
    sort(all(rr));
    rr.resize(unique(all(rr)) - rr.begin());
    sort(all(gg));
    gg.resize(unique(all(gg)) - gg.begin());
    sort(all(bb));
    bb.resize(unique(all(bb)) - bb.begin());
    auto val = [&](ll x, ll y, ll z) {
        return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
    };
    auto solve = [&](vector<ll> a, vector<ll> b, vector<ll> c) {
        ll res = LLONG_MAX;
        for (ll i = 0; i < sz(c); ++i) c[i] *= 2;
        for (ll i = 0; i < sz(a); ++i) {
            ll R = a[i];
            auto G = findClosest(b, R);
            ll G1 = G.first, G2 = G.second;
            auto B = findClosest(c, R + G.first);
            auto B_ = findClosest(c, R + G.second);
            ll B1 = B.first, B2 = B.second, B3 = B_.first, B4 = B_.second;
            amin(res, val(R, G1, B1 / 2));
            amin(res, val(R, G2, B1 / 2));
            amin(res, val(R, G1, B2 / 2));
            amin(res, val(R, G2, B2 / 2));
            amin(res, val(R, G1, B3 / 2));
            amin(res, val(R, G2, B3 / 2));
            amin(res, val(R, G1, B4 / 2));
            amin(res, val(R, G2, B4 / 2));
        }
        return res;
    };
    cout << min({solve(rr, gg, bb), solve(gg, bb, rr), solve(rr, bb, gg)}) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}