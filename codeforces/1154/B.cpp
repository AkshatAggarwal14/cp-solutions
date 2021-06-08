//****************master._.mind****************
//-----------Author: Akshat Aggarwal-----------
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ub() upper_bound()
#define lb() lower_bound()
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

bool check(vl x, ll n)
{
    unordered_map<ll, ll> mp;
    fo(i, x.size())
    {
        if (x[i] > n)
            x[i] -= n;
        else if (x[i] < n)
            x[i] += n;
        mp[x[i]]++;
    }
    if (mp.size() == 1)
        return true;
    return false;
}

void solve()
{

    ll n;
    cin >> n;
    vl vec(n);
    fo(i, n) cin >> vec[i];
    if (n == 1)
    {
        cout << 0;
        return;
    }
    ll mini = *min_element(all(vec)), maxi = *max_element(all(vec));
    fo(i, n) vec[i] -= mini;
    // deb(check(vec, 3));
    rep(i, 0, maxi)
    {
        if (check(vec, i))
        {
            cout << i;
            return;
        }
    }
    cout << -1;
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}