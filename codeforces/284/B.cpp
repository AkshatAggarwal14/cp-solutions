//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln '\n'
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << "[" << #x << "]: " << x << ln
#define deb2(x, y) cout << "[" << #x << "]: " << x << ", [" << #y << "]: " << y << ln
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define rall(x) (x).rbegin(), (x).rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.ff) + ", " + to_string(p.ss) + "}";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << to_string(H) << ln;
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class Task {
   public:
    void Perform() {
        Read();
        Solve();
    }

   private:
    ll n;
    string s;

    void Read() {
        cin >> n >> s;
    }

    void Solve() {
        map<char, ll> cnt;
        fo(i, n)++ cnt[s[i]];
        if (cnt['I'] == 0)
            cout << cnt['A'] << '\n';
        else if (cnt['I'] == 1)
            cout << "1\n";
        else if (cnt['I'] >= 2)
            cout << "0\n";
        else
            cout << cnt['I'] << '\n';
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    Task t;
    t.Perform();
    return 0;
}