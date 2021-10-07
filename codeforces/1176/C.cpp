// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

vector<deque<ll>> vv;
ll getId(ll i, ll j) {
    while (!vv[i].empty() && vv[i].front() < j) {
        vv[i].pop_front();
    }
    if (vv[i].empty()) return -1;
    ll temp = vv[i].front();
    vv[i].pop_front();
    return temp;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    map<ll, ll> mp = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
    vv.resize(6);
    for (ll i = 0; i < n; ++i) vv[mp[a[i]]].push_back(i);
    // dbg(vv);
    ll ans = 0;
    while (true) {
        ll t1 = getId(0, 0);
        ll t2 = getId(1, t1);
        ll t3 = getId(2, t2);
        ll t4 = getId(3, t3);
        ll t5 = getId(4, t4);
        ll t6 = getId(5, t5);
        if (t1 == -1 || t2 == -1 || t3 == -1 || t4 == -1 || t5 == -1 || t6 == -1) break;
        ans++;
    }
    // dbg(ans);
    cout << n - 6 * ans << '\n';
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