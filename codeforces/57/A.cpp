// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll n;
vector<vector<bool>> vis;
vector<vector<ll>> dis;
bool valid(ll x, ll y) {
    if (x < 0 || y < 0 || x > n || y > n) return false;
    if (vis[x][y]) return false;  // if already visited or empty
    return true;
}

// graph moves - 4 directions
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

void Solution() {
    ll x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    dis.resize(n + 1, vector<ll>(n + 1, 0));
    queue<pair<ll, ll>> bfs;
    vis.resize(n + 1, vector<bool>(n + 1, false));
    bfs.emplace(x1, y1);
    vis[x1][y1] = true;
    while (!bfs.empty()) {
        ll x = bfs.front().first;
        ll y = bfs.front().second;
        bfs.pop();
        if (x == x2 && y == y2) break;
        if (x == 0 || x == n || y == 0 || y == n) {
            for (ll i = 0; i < 4; ++i) {  // 4 directions
                ll X = x + dx[i];
                ll Y = y + dy[i];
                if (valid(X, Y)) {
                    vis[X][Y] = true;
                    bfs.emplace(X, Y);
                    dis[X][Y] = dis[x][y] + 1;
                }
            }
        }
    }
    cout << dis[x2][y2] << '\n';
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