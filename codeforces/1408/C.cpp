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
constexpr double EPS = 1e-6;

void test() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    a.push_back(l);
    reverse(all(a));
    a.push_back(0);
    reverse(all(a));
    auto get_dist = [&](double time) {
        ll speed = 1;
        double dist = 0;
        for (ll i = 1; i <= n + 1; ++i) {
            double d = abs(double(a[i] - a[i - 1]));
            double t = d / double(speed);
            if (time >= t) {
                time -= t;
                dist += d;
            } else {
                dist += double(speed) * time;
                break;
            }
            ++speed;
        }
        return dist;
    };
    // max time when dist(a) + dist(b) <= l
    auto can = [&](double time) {
        double dA = get_dist(time);
        reverse(all(a));
        double dB = get_dist(time);
        reverse(all(a));
        dbg(dA, dB, time);
        return (dA + dB <= double(l));
    };
    double L = 1, R = double(l);
    double ans = -1;
    // iterations = log2(Range/EPS)
    for (ll _ = 0; _ < 50; ++_) {
        double M = (L + R) / 2;
        if (can(M)) {
            L = M;
            ans = M;
        } else {
            R = M;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(15);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
