#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

// splits a std::string into vector<string> at a delimiter
vector<string> split(const string &s, const string &delims = ";, ") {
    vector<string> res;
    string token = "";
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        while (delims.find(s[i]) != string::npos) {
            res.push_back(token);
            token = "";
            ++i;
        }
        token += s[i];
    }
    if (token != "") res.push_back(token);
    return res;
}

void Solution() {
    string s;
    cin >> s;
    vector<string> ans = split(s, ";,");
    string s1 = "", s2 = "";
    auto valid = [](string str) {
        if (str.empty()) return false;
        if (str == "0") return true;
        if (str[0] == '0') return false;
        for (char &c : str)
            if (!(c >= '0' && c <= '9')) return false;
        return true;
    };
    for (const auto &tok : ans) {
        if (valid(tok)) {
            if (tok != "") s1.append(tok);
            s1 += ',';
        } else {
            if (tok != "") s2.append(tok);
            s2 += ',';
        }
    }
    if (s2 == ",") {
        if (s1.back() == ',') s1.pop_back();
        string res1 = "";
        for (char &c : s1)
            if (c != '\0') res1 += c;
        cout << (s1 == "" ? "-" : "\"" + res1 + "\"") << '\n';
        cout << "\"\"" << '\n';
        return;
    }
    if (s1.back() == ',') s1.pop_back();
    if (s2.back() == ',') s2.pop_back();
    string res1 = "", res2 = "";
    for (char &c : s1)
        if (c != '\0') res1 += c;
    for (char &c : s2)
        if (c != '\0') res2 += c;
    cout << (s1 == "" ? "-" : "\"" + res1 + "\"") << '\n';
    cout << (s2 == "" ? "-" : "\"" + res2 + "\"") << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}