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
    ll ops = 0, left = n;
    stack<char> st;
    for (ll i = 0; i < n;) {
        if (st.empty()) {
            st.push(s[i]);
            ++i;
        } else {
            if (s[i] == st.top()) {
                left -= 2;
                ops++;
                st.pop();
                ++i;
            } else if (st.top() == '(' && s[i] == ')') {
                st.pop();
                left -= 2;
                ops++;
                ++i;
            } else {
                if (st.top() != ')') break;
                // assert(s[i] == ')');
                ll pos = -1;
                for (ll j = i + 1; j < n; ++j) {
                    if (s[j] == ')') {
                        pos = j;
                        break;
                    }
                }
                dbg(i, pos);
                if (pos == -1) break;
                ops++;
                left -= (pos - i + 2);
                i = pos + 1;
                st.pop();
            }
        }
    }
    cout << ops << ' ' << left << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}