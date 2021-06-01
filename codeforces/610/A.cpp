#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n, i;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << 0 << "\n";
        return;
    }
    n = n / 2;
    for (i = 0; i < n / 2; i++)
        ;
    if (n % 2 == 0)
        i--;
    cout << i << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}