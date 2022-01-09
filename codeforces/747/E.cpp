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

// splits a std::string into vector<string> at a delimiter
vector<string> split(const string &s, const string &delims = " ") {
    vector<string> res;
    string token = "";
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        while (delims.find(s[i]) != string::npos) {
            res.push_back(token);
            token = "";
            ++i;
        }
        token += s[i];
    }
    if (token != "") res.push_back(token);
    return res;
}

const ll MAX_DEPTH = 1e6;
vector<vector<string>> ans(MAX_DEPTH + 1);

void Solution() {
    string s;
    cin >> s;
    vector<string> v(split(s, ","));
    vector<pair<string, ll>> a;
    for (ll i = 0; i < sz(v) - 1; i += 2)
        a.push_back({v[i], stoll(v[i + 1])});
    ll mx = 0;
    auto dfs = [&](const auto &self, ll idx, ll lvl) -> ll {
        amax(mx, lvl);
        ans[lvl].push_back(a[idx].first);
        ll id = idx;
        for (ll i = 0; i < a[idx].second; ++i) {
            id = self(self, id + 1, lvl + 1);
        }
        return id;
    };

    for (ll i = 0; i < sz(a); i = dfs(dfs, i, 1) + 1) {
        dbg(ans);
    }
    cout << mx << '\n';
    for (ll i = 1; i <= mx; ++i) {
        for (auto &x : ans[i]) cout << x << ' ';
        cout << '\n';
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