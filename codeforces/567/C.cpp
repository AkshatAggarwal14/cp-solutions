#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void test() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    if (n < 3) return void(cout << "0\n");
    // lets fix middle element, thus we need count of a[i]/k, before element, and k * a[i] after element
    o_multiset<ll> pre, suff;
    auto get = [&](o_multiset<ll> &x, ll element) {
        return x.order_of_key(element + 1) - x.order_of_key(element);
    };
    ll ans = 0;
    for (int i = 1; i < n; ++i) suff.insert(a[i]);
    for (int i = 1; i < n; ++i) {
        pre.insert(a[i - 1]);
        auto it = suff.find_by_order(suff.order_of_key(a[i]));
        suff.erase(it);
        if (a[i] % k == 0)
            ans += get(pre, a[i] / k) * get(suff, a[i] * k);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
