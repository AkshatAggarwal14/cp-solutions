#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define sz(x) (ll)(x).size()

struct cmp2 {
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        return a.second > b.second;
    }
};
struct cmp3 {
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

void Solution() {
    ll q;
    cin >> q;
    // money, index
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp2> p2;  //idx
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp3> p3;  //money
    vector<ll> vis{-1};
    ll type, m;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> m;
            p2.emplace(m, sz(vis));
            p3.emplace(m, sz(vis));
            vis.push_back(0);
        } else if (type == 2) {
            while (vis[p2.top().second]) p2.pop();
            vis[p2.top().second] = 1;
            cout << p2.top().second << ' ';
            p2.pop();
        } else {
            while (vis[p3.top().second]) p3.pop();
            vis[p3.top().second] = 1;
            cout << p3.top().second << ' ';
            p3.pop();
        }
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}