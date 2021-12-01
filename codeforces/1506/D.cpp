#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// make pair with count of contiguous..
vector<ll> compress(priority_queue<ll> &pq) {
    vector<ll> res;
    ll cnt = 0, last = pq.top();
    while (!pq.empty()) {
        if (pq.top() == last) {
            cnt++;
        } else {
            res.push_back(cnt);
            last = pq.top(), cnt = 1;
        }
        pq.pop();
    }
    if (cnt) res.push_back(cnt);
    return res;
}

void Faster() {
    ll n, num;
    cin >> n;
    priority_queue<ll> pq1;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        pq1.push(num);
    }
    vector<ll> cnt = compress(pq1);
    priority_queue<ll> pq;
    for (auto val : cnt) pq.push(val);
    while (sz(pq) > 1) {
        ll p1 = pq.top();
        pq.pop();
        ll p2 = pq.top();
        pq.pop();
        p1--, p2--;
        if (p1) pq.push(p1);
        if (p2) pq.push(p2);
    }
    if (pq.empty()) return void(cout << 0 << '\n');
    cout << pq.top() << '\n';
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
    Faster();
    // Solution();
    return 0;
}