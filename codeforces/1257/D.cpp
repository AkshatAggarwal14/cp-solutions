#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

template <class T, class U = function<T(const T &, const T &)>, class V = function<T()>>
class Sparse_Table {
    int N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;
    V id;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP, const V &ID)
        : N(int(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP), id(ID) {
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T slow_query(int L, int R) {
        T res = id();
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res = op(res, st[L][j]);
                L += (1 << j);
            }
        }
    }
    T query(int L, int R) {
        if (L > R) return id();
        int j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll n_heroes;
    cin >> n_heroes;
    vector<ll> max_power(n, -INF);  // find max power for given endurance
    // if hero can do 5 monsters, with power 100, he can do 4 too
    for (ll i = 0, p, si; i < n_heroes; ++i) {
        cin >> p >> si, --si;
        max_power[si] = max(max_power[si], p);
    }
    for (ll i = n - 2; i >= 0; --i) max_power[i] = max(max_power[i], max_power[i + 1]);
    Sparse_Table<ll> st(
        a,
        [](const ll &A, const ll &B) -> ll { return max(A, B); },
        []() -> ll { return -INF; });
    int index = 0;
    ll ans = 0;
    // dbg(max_p);
    while (index < n) {
        int L = index, R = int(n) - 1;
        --L, ++R;
        while (R > L + 1) {
            int M = (L + R) / 2;
            // if max power of given length is >= max of array
            // binary search for how far can i go (longest endurance possible) if the hero selected can fight the monster with maximum power in this range
            if (max_power[M - index] >= st.query(index, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        if (index == L + 1) return void(cout << "-1\n");  // if none found
        index = L + 1;                                    // if found move to next segment
        ++ans;                                            // how many segments?
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}