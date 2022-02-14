#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> int { return int(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

// identify each square from top left corner.
// start from the end, where we have the last 2x2 square
void Solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid)
        for (auto &cell : row) cin >> cell;

    auto valid_square = [&](int i, int j) -> bool {
        if (i < 0 || i >= n - 1 || j < 0 || j >= m - 1) return false;
        set<int> st;
        for (int dx = 0; dx <= 1; ++dx)
            for (int dy = 0; dy <= 1; ++dy)
                if (grid[i + dx][j + dy] != -1)
                    st.insert(grid[i + dx][j + dy]);
        return (sz(st) == 1);
    };

    vector<array<int, 3>> ans;
    queue<pair<int, int>> bfs;
    auto insert = [&](int i, int j) {
        set<int> st;
        for (int dx = 0; dx <= 1; ++dx)
            for (int dy = 0; dy <= 1; ++dy)
                if (grid[i + dx][j + dy] != -1)
                    st.insert(grid[i + dx][j + dy]);
        ans.push_back({i, j, *st.begin()});
        for (int dx = 0; dx <= 1; ++dx)
            for (int dy = 0; dy <= 1; ++dy)
                bfs.emplace(i + dx, j + dy), grid[i + dx][j + dy] = -1;
    };
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m - 1; ++j)
            if (valid_square(i, j))
                insert(i, j);
    while (!bfs.empty()) {
        auto [i, j] = bfs.front();
        bfs.pop();
        for (int dx = -1; dx <= 0; ++dx)
            for (int dy = -1; dy <= 0; ++dy)
                if (valid_square(i + dx, j + dy))
                    insert(i + dx, j + dy);
    }
    dbg(grid, ans);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] != -1) return void(cout << "-1\n");
    reverse(all(ans));
    cout << sz(ans) << '\n';
    for (auto &[i, j, c] : ans) cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}