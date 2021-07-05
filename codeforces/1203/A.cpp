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

bool checkClockwise(ll arr[], ll n)
{
    ll element = INT_MAX; // min element
    ll index = -1;        // min index

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < element)
        {
            element = arr[i];
            index = i;
        }
    }

    ll flag1 = 1;
    for (ll i = 1; i < index; i++)
    {
        if (arr[i] < arr[i - 1]) // all elements before minimum index must be in increasing order
        {
            flag1 = 0;
            break;
        }
    }

    ll flag2 = 1;
    for (ll i = index + 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1]) // all elements after minimum index must be in increasing order
        {
            flag2 = 0;
            break;
        }
    }

    if (flag1 && flag2 && (arr[0] == arr[n - 1] + 1 || (arr[0] == 1 && arr[n - 1] == n)))
        return true;
    return false;
}

void solve()
{

    ll n;
    cin >> n;
    ll arr[n], rev[n];
    fo(i, n) cin >> arr[i];
    fo(i, n) rev[n - i - 1] = arr[i];

    if (checkClockwise(arr, n) || checkClockwise(rev, n))
        cout << "YES";
    else
        cout << "NO";
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