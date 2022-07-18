#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e8;
int dp[102][102][12][2];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    /*
    dp[n1][n2][k][0] -> if k type 1s at end, having used n1 and n2
    dp[n1][n2][k][1] -> if k type 2s at end, having used n1 and n2
    */
    memset(dp, -1, sizeof(dp));
    function<int(int, int, int, int)> dfs = [&](int used_n1, int used_n2, int consec, int type) {
        if (used_n1 > n1 || used_n2 > n2) return 0;
        if (type == 0 && consec > k1) return 0;
        if (type == 1 && consec > k2) return 0;
        if (used_n1 == n1 && used_n2 == n2) return 1;

        int &ans = dp[used_n1][used_n2][consec][type];
        if (ans != -1) return ans;
        int ans1 = 0, ans2 = 0;
        // use type 0:
        if (type == 0) {
            ans1 = dfs(used_n1 + 1, used_n2, consec + 1, 0);
        } else {
            ans1 = dfs(used_n1 + 1, used_n2, 1, 0);
        }
        // use type 1:
        if (type == 1) {
            ans2 = dfs(used_n1, used_n2 + 1, consec + 1, 1);
        } else {
            ans2 = dfs(used_n1, used_n2 + 1, 1, 1);
        }
        return ans = (ans1 + ans2) % MOD;
    };
    cout << dfs(0, 0, 0, 0) << '\n';
}