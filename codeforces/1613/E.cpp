#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void Solution() {
    ll n, m, lx = 0, ly = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L') {
                lx = i, ly = j;
            }
        }
    }
    vector<vector<int>> done(n, vector<int>(m, 0));
    queue<pair<ll, ll>> bfs;
    bfs.push({lx, ly});
    while (!bfs.empty()) {
        ll X = bfs.front().first;
        ll Y = bfs.front().second;
        bfs.pop();
        for (ll k = 0; k < 4; ++k) {
            ll nX = X + dx[k], nY = Y + dy[k];
            if (nX < 0 || nY < 0 || nX >= n || nY >= m) continue;
            if (grid[nX][nY] != '.') continue;
            // now check every cell
            ll allowed = 0;
            for (ll kk = 0; kk < 4; ++kk) {
                ll nnX = nX + dx[kk], nnY = nY + dy[kk];
                if (nnX >= 0 && nnX < n && nnY >= 0 && nnY < m && grid[nnX][nnY] == '.') allowed++;
            }
            if (allowed <= 1) {
                grid[nX][nY] = '+';
                bfs.push({nX, nY});
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) cout << grid[i][j];
        cout << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}