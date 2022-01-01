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

vector<ll> quantity, cost;
struct cmp {
    bool operator()(const ll &A, const ll &B) const {
        if (cost[A] == cost[B]) return A < B;
        return cost[A] < cost[B];
    }
};

void Solution() {
    ll n, m, dish_number, amount, temp;
    cin >> n >> m;
    quantity.assign(n + 1, -1), cost.assign(n + 1, -1);
    for (ll i = 1; i <= n; ++i) cin >> quantity[i];
    for (ll i = 1; i <= n; ++i) cin >> cost[i];
    map<ll, ll, cmp> dishes;  // map sorted by cost and then index
    for (ll i = 1; i <= n; ++i) dishes[i] = quantity[i];

    // returns how much removed
    auto remove = [&](const ll &what, const ll &how_much) -> ll {
        if (!dishes.contains(what)) return 0;
        ll t = min(how_much, dishes[what]);
        dishes[what] -= t;
        if (dishes[what] == 0) dishes.erase(what);
        return t;
    };

    while (m--) {
        cin >> dish_number >> amount;
        ll res = 0;
        temp = remove(dish_number, amount);
        res += temp * cost[dish_number];
        amount -= temp;  // remove present
        while (amount > 0 && !dishes.empty()) {
            ll dish_id = dishes.begin()->first;
            temp = remove(dish_id, amount);
            res += temp * cost[dish_id];
            amount -= temp;
        }
        cout << ((amount == 0) ? res : 0LL) << '\n';
    }
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