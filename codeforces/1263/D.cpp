#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

struct DSU {
    int N;
    vector<int> par, siz;
    DSU(int n) : N(n), par(N), siz(N, 1) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void join(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
    int get_size(int X) { return siz[root(X)]; }
    int components() {
        int cnt = 0;
        for (int i = 0; i < N; ++i) cnt += (root(i) == i);
        return cnt;
    }
};
void Solution() {
    int n;
    cin >> n;
    string s;
    DSU dsu(n);
    vector<int> occ(26, -1);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (char &c : s) {
            if (occ[c - 'a'] != -1)
                dsu.join(occ[c - 'a'], i);
            occ[c - 'a'] = i;
        }
    }
    cout << dsu.components() << '\n';
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