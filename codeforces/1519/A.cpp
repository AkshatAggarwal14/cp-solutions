#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a,b);
    ll k = (b + a - 1)/a;
   // cout << k << endl;
    if (k - 1 <= c) cout << "YES" << endl; else cout << "NO" << endl;
}
int main () {
    ll t;
    cin >> t;
    while (t--) solve();
}