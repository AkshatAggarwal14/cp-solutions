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

void Solution() {
    string s, e, o;
    cin >> s;
    // as we can swap opposite parties, the same parity digits remain in same position w.r.t. each other
    for (char &c : s) ((c - '0') % 2 ? o : e) += c;
    dbg(o, e);
    ll i = 0, j = 0, n = sz(e), m = sz(o);
    while (i < n && j < m) {
        if (e[i] < o[j]) {
            cout << e[i];
            ++i;
        } else {
            cout << o[j];
            ++j;
        }
    }
    while (i < n) {
        cout << e[i];
        ++i;
    }
    while (j < m) {
        cout << o[j];
        ++j;
    }
    cout << '\n';
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