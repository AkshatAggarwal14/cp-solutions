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

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    int ans = -1, mxcnt = 0, l = -1, r = -1;
    for (int i = 0; i < n; ++i) cin >> a[i], mp[a[i]].push_back(i);
    for (auto &[x, y] : mp) {
        vector<vector<int>> segs;
        for (int i = 0; i < sz(y); ++i) {
            if (segs.empty() || segs.back().back() != y[i] - 1)
                segs.emplace_back();
            segs.back().emplace_back(y[i]);
        }
        vector<int> id;
        int gg = sz(segs[0]);
        while (gg--) id.push_back(1);
        for (int i = 1; i < sz(segs); ++i) {
            id.push_back(-(segs[i].front() - segs[i - 1].back() - 1));
            gg = sz(segs[i]);
            while (gg--) id.push_back(1);
        }
        dbg(id, segs);
        int max_ending_here = 0;
        int max_so_far = 0;
        int _start = 0;
        int start = 0;
        int end = -1;

        for (int i = 0; i < sz(id); i++) {
            max_ending_here = max_ending_here + id[i];
            if (max_ending_here < 0) {
                max_ending_here = 0;
                _start = i + 1;
            }
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
                start = _start;
                end = i;
            }
        }
        if (max_so_far > mxcnt) {
            ans = x;
            mxcnt = max_so_far;
            dbg(id, start, end);
            int beg = segs.front().front();
            for (int i = 1; i <= start; ++i) beg += abs(id[i]);
            l = beg;
            for (int i = start + 1; i <= end; ++i) beg += abs(id[i]);
            r = beg;
            // l = mp[ans][start], r = l;
            // for (int i = start; i < end; ++i) r += abs(id[i]);
        }
    }
    cout << ans << ' ' << l + 1 << ' ' << r + 1 << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
