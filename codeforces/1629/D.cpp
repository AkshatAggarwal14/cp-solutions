#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

bool isPalindrome(const string &s) {
    for (ll i = 0; i < sz(s); ++i)
        if (s[i] != s[sz(s) - 1 - i]) return false;
    return true;
}

void Solution() {
    set<string> st;
    ll n;
    string s;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    for (ll i = 0; i < n; ++i) {
        s = a[i];
        if (isPalindrome(s))
            return void(cout << "YES\n");
        else {
            if (sz(s) == 1) {
                return void(cout << "YES\n");
            } else if (sz(s) == 2) {
                // 3 4 5
                // s[1] | s[0] s[1]
                string s1 = "";
                s1 += s[1];
                // if (st.contains(s1)) return void(cout << "YES\n");

                // rev s
                s1 += s[0];
                if (st.contains(s1)) return void(cout << "YES\n");

                // rev x s
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    string t = s1;
                    t += ch;
                    if (st.contains(t)) return void(cout << "YES\n");
                }
            } else if (sz(s) == 3) {
                // 4 5 6
                // s[2] | s[0] s[1] s[2]
                string s1 = "";
                s1 += s[2];
                // if (s[0] == s[1])
                // if (st.contains(s1)) return void(cout << "YES\n");
                // s[2] s[1] | s[0] s[1] s[2]
                s1 += s[1];
                if (st.contains(s1)) return void(cout << "YES\n");

                s1 += s[0];
                if (st.contains(s1)) return void(cout << "YES\n");
            }
        }
        st.insert(s);
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}