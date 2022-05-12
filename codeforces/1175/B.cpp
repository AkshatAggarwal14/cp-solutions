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

const ll INF = (1LL << 32);
void Solution() {
    ll n, num;
    string op;
    cin >> n;
    stack<ll> multiplier;
    multiplier.push(1);
    ll ans = 0;
    while (n--) {
        cin >> op;
        if (op == "for") {
            cin >> num;
            num = min(INF, multiplier.top() * num);
            multiplier.push(num);
        } else if (op == "end") {
            multiplier.pop();
        } else {
            ans += multiplier.top();
            if (ans >= INF) return void(cout << "OVERFLOW!!!\n");
        }
    }
    cout << ans << '\n';
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