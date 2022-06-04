#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
ll prime[N] = {0};
ll k[N] = {0};

void Sieve() {
    for (ll i = 1; i < N; i++) k[i] = i;
    for (ll i = 2; i < N; i++) {
        if (prime[i] == 0)
            for (ll j = i; j < N; j += i) {
                prime[j] = 1;
                while (k[j] % (i * i) == 0)
                    k[j] /= (i * i);
            }
    }
}

ll countPairs(ll n) {
    map<ll, ll> freq;
    for (ll i = 1; i <= n; i++) freq[k[i]]++;
    ll sum = 0;
    for (auto i : freq) {
        sum += ((i.second - 1) * i.second) / 2;
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;
    Sieve();
    cout << n + 2 * countPairs(n) << '\n';
    return 0;
}
