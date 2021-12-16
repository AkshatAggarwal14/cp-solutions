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

int query(int a, int b, int c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    ll res;
    cin >> res;
    if (res == -1) exit(0);
    return res ^ 1;
}

void Solution() {
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = query(i, (i + 1) % n, (i + 2) % n);
    }
    int a, b;
    for (int i = 0; i < n; ++i) {
        int nxt = (i + 1) % n;
        if (res[i] ^ res[nxt]) {
            a = (i + 1) % n;
            b = (i + 2) % n;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (i == a or i == b) continue;
        ans[i] = query(a, b, i);
    }
    int c, d;
    for (int i = 0; i < n; ++i) {
        if (i == a or i == b) continue;
        if (ans[i] == 1) {
            c = i;
        }
        if (ans[i] == 0) {
            d = i;
        }
    }
    ans[a] = query(c, d, a);
    ans[b] = query(c, d, b);
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) x.push_back(i + 1);
    }
    cout << "! " << x.size() << ' ';
    for (int i : x) cout << i << ' ';
    cout << endl;
}

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}