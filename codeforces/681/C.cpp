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
    ll n;
    cin >> n;
    string op;
    ll num;
    vector<string> res;
    multiset<ll> vals;

    auto insert = [&](ll N) {
        vals.insert(N);
        res.push_back("insert " + to_string(N));
    };
    auto removeMin = [&]() {
        if (vals.empty()) insert(1);
        assert(!vals.empty());
        vals.erase(vals.lower_bound(*vals.begin()));
        res.push_back("removeMin");
    };
    auto getMin = [&](ll N) {
        while (!vals.empty() && *vals.begin() < N) removeMin();
        if (vals.empty() || *vals.begin() > N) insert(N);
        res.push_back("getMin " + to_string(N));
    };

    for (ll i = 0; i < n; ++i) {
        cin >> op;
        if (op == "insert") {
            cin >> num;
            insert(num);
        } else if (op == "getMin") {
            cin >> num;
            getMin(num);
        } else {
            removeMin();
        }
    }

    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}