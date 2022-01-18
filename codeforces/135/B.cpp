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

struct pt {
    ll x, y;
};

void Solution() {
    auto dist = [](pt p1, pt p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    };
    // tests if angle abc is a right angle
    auto isOrthogonal = [&](pt a, pt b, pt c) -> bool {
        // dot product == 0
        // ba dot bc = 0
        return ((b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0);
    };
    auto isRectangle = [&](pt p1, pt p2, pt p3, pt p4) {
        // all angles 90 degrees
        bool c1 = isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) && isOrthogonal(p3, p4, p1);
        bool c2 = isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) && isOrthogonal(p1, p4, p2);
        bool c3 = isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) && isOrthogonal(p2, p4, p3);
        return (c1 || c2 || c3);
    };
    auto isSquare = [&](pt p1, pt p2, pt p3, pt p4) {
        // orthogonal and equal distance
        if (isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) && isOrthogonal(p3, p4, p1)) {  // 1 2 3 4
            if (dist(p1, p2) == dist(p2, p3) && dist(p2, p3) == dist(p3, p4) && dist(p3, p4) == dist(p4, p1)) return true;
        }
        if (isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) && isOrthogonal(p1, p4, p2)) {  // 2 3 1 4
            if (dist(p2, p3) == dist(p3, p1) && dist(p3, p1) == dist(p1, p4) && dist(p1, p4) == dist(p4, p2)) return true;
        }
        if (isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) && isOrthogonal(p2, p4, p3)) {  // 3 1 2 4
            if (dist(p3, p1) == dist(p1, p2) && dist(p1, p2) == dist(p2, p4) && dist(p2, p4) == dist(p4, p3)) return true;
        }
        return false;
    };

    vector<pt> a(8);
    vector<ll> P(8);
    iota(all(P), 0);
    for (auto &[x, y] : a) cin >> x >> y;
    do {
        if (isSquare(a[P[0]], a[P[1]], a[P[2]], a[P[3]]) &&
            isRectangle(a[P[4]], a[P[5]], a[P[6]], a[P[7]])) {
            cout << "YES\n";
            for (ll i = 0; i < 4; ++i) cout << P[i] + 1 << ' ';
            cout << '\n';
            for (ll i = 4; i < 8; ++i) cout << P[i] + 1 << ' ';
            return;
        }
    } while (next_permutation(all(P)));
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}