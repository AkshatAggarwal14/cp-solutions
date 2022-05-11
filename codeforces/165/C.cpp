// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector<ll> pref(s.length() + 1);
    pref[0] = 0;
    for (ll i = 1; i < s.length() + 1; ++i) pref[i] = (s[i - 1] == '1' ? 1 : 0) + pref[i - 1];
    // dbg(pref);
    ll ans = 0;
    map<ll, ll> cnt;
    for (ll i = 0; i < s.length() + 1; ++i) {
        ++cnt[pref[i]];
        ans += cnt[pref[i] - k];
    }
    if (k == 0) {
        ans = 0;
        for (auto [x, y] : cnt) {
            ans += (y * (y - 1)) / 2;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}