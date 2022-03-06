#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

template <typename T, typename T_iterable>
vector<pair<T, ll>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, ll>> encoded;
    ll count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &X : a) cin >> X;
    ll L = -1, R = -1;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) {
            L = i;
            break;
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) R = i;
    }
    if (L == -1) return void(cout << "0\n");
    --L, ++R;
    cout << (R - L) << '\n';
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