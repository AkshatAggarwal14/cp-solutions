/*	ॐ	*/
// Akshat Aggarwal
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
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

void solve()
{
    int n;
    cin >> n;
    ll a[n];

    fo(i, n) cin >> a[i];

    fo(i, n) a[i] -= i; //ai=ai-i

    map<ll, ll> cnt;
    fo(i, n) cnt[a[i]]++; //like hash maps--> stores a[i] as key and cnt[a[i]] as value, first gives key. second gives value
    ll ans = 0;

    for (auto i : cnt)
    {
        ans += i.S * (i.S - 1) / 2; //! nC2 to make a pair
    }

    cout << ans;

    //! TLE on Case 4
    /*ll n, ans = 0;
    cin >> n;
    ll arr[n];
    vl ar;
    fo(i, n)
    {
        cin >> arr[i];
        ar.pb(arr[i] - i);
    }
    sortall(ar);
    for (ll i = 0; i < n - 1; i++)
        for (ll j = i + 1; j < n; j++)
            if (ar[i] == ar[j])
                ans++;

    cout << ans;*/
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}