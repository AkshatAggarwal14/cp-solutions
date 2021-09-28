#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const ll N = 1e5;
vector<int> adj[N];
bool vis[N];
ll len = 0;

void dfs(ll x) {
    vis[x] = true;
    len++;
    for (auto node : adj[x]) {
        if (vis[node]) continue;
        dfs(node);
    }
}

void Solution() {
    vector<ll> lens;
    ll n, num;
    cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> num, adj[i].push_back(num);
    for (ll i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        len = 0;
        dfs(i);
        if (len) lens.push_back(len);
    }
    sort(lens.begin(), lens.end());
    ll ans;
    if ((ll)lens.size() > 1) {
        ans = static_cast<ll>(pow((lens[(ll)lens.size() - 2] + lens.back()), 2));
        for (ll i = 0; i < (ll)lens.size() - 2; i++) ans += lens[i] * lens[i];
    } else
        ans = lens[0] * lens[0];
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}