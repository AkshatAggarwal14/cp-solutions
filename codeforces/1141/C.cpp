#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

// ----------------------------<optimizations>----------------------------
/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
// ---------------------------</optimizations>----------------------------

// ---------------------------------<PBDS>--------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using o_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using o_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
//member functions :
// 1. order_of_key (val): returns the no. of values less than val
// 2. find_by_order (k): returns the iterator to kth largest element.(0-based)
// for ordered_multiset, lower_bound and upper_bound swap roles
// --------------------------------</PBDS>--------------------------------

// -------------------------<Defines and typedefs>------------------------
using ll = int64_t;
using db = double;
using str = string;
using ull = unsigned long long;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define set_bits(x) __builtin_popcountll(x)
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define rall(x) (x).rbegin(), (x).rend()
#define ps(x, y) fixed << setprecision(y) << x
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define sz(x) ((ll)(x).size())
template <class T>
using V = vector<T>;
using vl = V<ll>;
using vvl = V<vl>;
template <class T, class U>
using P = pair<T, U>;
using pl = P<ll, ll>;
using vpl = V<pl>;
// ------------------------</Defines and typedefs>------------------------

// --------------------------------<Consts>-------------------------------
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db eps = 1e-12;
const double PI = acos(-1);
// -------------------------------</Consts>-------------------------------

// -------------------------------<Templates>-----------------------------
template <class T, class U = T>
bool amin(T& a, U&& b) {
    return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool amax(T& a, U&& b) {
    return a < b ? a = std::forward<U>(b), true : false;
}
// ------------------------------</Templates>-----------------------------

// ---------------------------------<Solve>-------------------------------

void Solution() {
    ll n;
    cin >> n;
    vl q(n - 1);
    fo(i, n - 1) cin >> q[i];
    vl p(n), mid(n, 0);
    ll s = 0;
    rep(i, 1, n) {
        s += q[i - 1];
        mid[i] = s;
    }
    dbg(mid);
    ll mini = -(*min_element(all(mid))) + 1;
    set<ll> st;
    fo(i, n) mid[i] += mini, st.insert(mid[i]);
    if (sz(st) == n && *st.begin() == 1 && *st.rbegin() == n) {
        fo(i, n) cout << mid[i] << " ";
    } else
        cout << -1;
}

// --------------------------------</Solve>-------------------------------

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }
#ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
    return 0;
}

/*
    ? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * n % mod = (n % mod + mod) % mod; (Handling negatives)
    * When using a set, lower_bound(all(set),l) is slower than set.lower_bound(l) because of random iterators
    * string .append() or += is O1, but s = s + s is On (as it creates a copy first), use wisely
    * DONT GET STUCK ON ONE APPROACH
    * use __lg(n) instead of log2(n), int: 32 - __builtin_clz(n), ll: 63 - __builtin_clzll(n), https://codeforces.com/blog/entry/45966
    * string.rfind() finds first occurence from end
    * (a & b) + (a | b) = a + b
    * TLE due to ll ? or multiple copies of large DS?
*/
