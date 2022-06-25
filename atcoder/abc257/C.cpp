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
    o_multiset<ll> ones, zeroes;
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> w(n);
    for (ll &i : w) cin >> i;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1')
            ones.insert(w[i]);
        else
            zeroes.insert(w[i]);
    }
    ll mini = *min_element(all(w)) - 1;
    ll maxi = *max_element(all(w)) + 1;
    w.push_back(mini);
    w.push_back(maxi);
    ll ans = 0;
    for (ll i = 0; i < sz(w); ++i) {
        // >= means adult
        ll correct_adults = sz(ones) - ones.order_of_key(w[i]);
        ll correct_kids = zeroes.order_of_key(w[i]);
        ans = max(ans, correct_adults + correct_kids);
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
