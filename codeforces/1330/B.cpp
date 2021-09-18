#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using str = string;
template <class T>
using v = vector<T>;
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
using ll = int;

bool check(const map<int, int> &s, const int &c) {
    if (s.begin()->first == 1 && s.begin()->second == 1 && s.rbegin()->first == sz(s) && s.rbegin()->second == 1 && c == sz(s)) return true;
    return false;
}

void Solution() {
    int n;
    cin >> n;
    v<int> arr(n);
    map<int, int> pref, suff;
    int cnt = 0;
    for (int i = 0; i < n; ++i) cin >> arr[i], ++suff[arr[i]];
    v<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        ++pref[arr[i]];
        --suff[arr[i]];
        if (suff[arr[i]] == 0) suff.erase(arr[i]);
        ++cnt;
        if (check(pref, cnt) && check(suff, n - cnt))
            ans.emplace_back(sz(pref), sz(suff));
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) cout << x << " " << y << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) Solution();
    return 0;
}