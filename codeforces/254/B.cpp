#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define ff first
#define ss second

array<ll, 12> y = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<ll, 13> pref;
vector<ll> vals(500, 0);

ll getNum(ll month, ll day) {
    return 100 + pref[month - 1] + day;
}

void Solution() {
    ll n, m, d, p, t, xx;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> m >> d >> p >> t;
        xx = getNum(m, d) - 1;
        for (ll j = xx; j >= xx - t + 1; --j) vals[j] += p;
    }
    dbg(vals);
    cout << *max_element(vals.begin(), vals.end()) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    partial_sum(y.begin(), y.end(), pref.begin() + 1);
    Solution();
    return 0;
}