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

void Solution() {
    // x&y + x|y = x+y
    // a + x|y = s
    ll AND, SUM;
    cin >> AND >> SUM;
    ll OR = SUM - AND;
    if (OR < 0) return void(cout << "No\n");
    // if bit set in AND but not in OR, then it is not possible
    dbg(bitset<60>(AND).to_string());
    dbg(bitset<60>(OR).to_string());
    for (ll i = 0; i <= 60; ++i) {
        ll mask = (1LL << i);
        bool set_AND = (AND & mask);
        bool set_OR = (OR & mask);
        if (set_AND && !set_OR) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}