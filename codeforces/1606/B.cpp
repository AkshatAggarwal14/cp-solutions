#include "bits/stdc++.h"

using namespace std;
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

vector<ll> vals;
void fill() {
    ll p = 1;
    while (p <= (ll)1e18) {
        vals.push_back(p);
        p <<= 1;
    }
}

void Solution() {
    ll n, k;
    cin >> n >> k;
    n--;
    ll ctr = 0;
    for (ll i = 0; i < sz(vals); ++i) {
        if (vals[i] < k && vals[i] <= n) {
            ctr++;
            n -= vals[i];
        }
    }
    cout << ctr + n / k + !!(n % k) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fill();
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}