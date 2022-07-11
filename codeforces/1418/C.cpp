#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; ++i) cin >> a[i];
        // friend starts, if he playes, he uses skip points for 1s
        // i can freely play
        // dp[i][0] -> skip points needed for first i elements, if friend played last turn
        // dp[i][1] -> skip points needed for first i elements, if i played last turn
        vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
        dp[0][1] = 0;
        dp[1][0] = a[1];  // first move by friend
        for (ll i = 2; i <= n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 2][1] + a[i - 1]) + a[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
}