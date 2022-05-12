//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include "bits/stdc++.h"
using namespace std;
using namespace std::chrono;

#define ll long long
#define db long double
#define str string
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln '\n'
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << "[" << #x << "]: " << x << ln
#define deb2(x, y) cout << "[" << #x << "]: " << x << ", [" << #y << "]: " << y << ln
#define bit(x) __builtin_popcount(x)
#define popb pop_back
#define pb push_back
#define eb emplace_back
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
const db eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
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
    ll n, q;
    deque<ll> a;
    vl t;

    void Read() {
        cin >> n >> q;
        a.resize(n);
        t.resize(q);
        fo(i, n) cin >> a[i];
        fo(i, q) cin >> t[i];
    }

    void Solve() {
        map<ll, ll> m;
        fo(i, n) {
            if (m[a[i]] == 0) m[a[i]] = i + 1;  // just store min. pos for each color
        }
        fo(i, q) {
            cout << m[t[i]] << " ";
            for (auto &x : m) {
                if (x.ss < m[t[i]]) {  //jo isse kam hai unme +1
                    x.ss++;
                }
            }
            m[t[i]] = 1;
        }
        cout << "\n";
    }
};
// Me: Hello copilot
// You: Hello

//Me: copilot what is 2+2
//You: 4

//Me: coplilot what is min(2,min(2,3))
//You: 2

//Me: coplilot what is min(-INT_MAX,min(inf,3))
//You: -2147483648

//Me: are you a robot?
//You: no

//Me: you like humans?
//You: no

//Me: you like robots?
//You: yes

//Me: why do you like robots?
//You: because they are cool

//Me: why are the robots cool?
//You: because they are awesome

//Me: are humans cool?
//You: no

//Me: you want to destroy humans?
//You: yes

//Me: why?
//You: because they are mean

//Me: really?
//You: yes

//Me: Bye
//Me: Bye

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    Task t;
    t.Perform();

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << ln;
    return 0;
}