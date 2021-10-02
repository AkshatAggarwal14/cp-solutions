#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

void Solution() {
    ll n, t, num;
    cin >> n >> t;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    fo(i, n - 1) {
        cin >> num;
        adj[i + 1].push_back(i + num + 1);
    }

    function<void(ll)> dfs = [&](ll parent) {
        vis[parent] = true;
        for (auto child : adj[parent])
            if (!vis[child]) dfs(child);
    };

    dfs(1);
    if (vis[t])
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}