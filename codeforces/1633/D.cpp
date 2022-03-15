#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll N = 1005;
const ll INF = 1e18;

ll knapsack(ll W, vector<ll> weight, vector<ll> value) {
    // making and initializing dp array
    ll n = ll(weight.size());
    assert(ll(value.size()) == n);
    vector<ll> dp(W + 1, 0);
    for (ll i = 1; i < n + 1; i++) {
        for (ll w = W; w >= 0; w--) {
            // finding the maximum value
            if (weight[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - weight[i - 1]] + value[i - 1]);
        }
    }
    return dp[W];  // returning the maximum value of knapsack
}

int main() {
    vector<ll> operations(N + 1, INF);
    operations[1] = operations[0] = 0;
    for (ll par = 1; par <= N; par++) {
        for (ll child = 1; child <= N; child++) {
            ll val = par + (par / child);
            if (val <= N) operations[val] = min(operations[val], operations[par] + 1);
        }
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> op(n), coins(n);
        for (ll &B : op) cin >> B, B = operations[B];
        for (ll &C : coins) cin >> C;
        // DP, atmost k operations, maximise coins
        // max(operations[i]) = 12, thus min(k, 12 * n)
        cout << knapsack(min(k, 12 * n), op, coins) << '\n';
    }
    return 0;
}

/*
1
4 4
1 7 5 2
2 6 5 2

*/