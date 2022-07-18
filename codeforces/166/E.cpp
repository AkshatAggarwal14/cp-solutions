#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e7 + 5;
const ll MOD = 1e9 + 7;
// https://github.com/naman1601/cp-templates/blob/main/mint.sublime-snippet
template <int Modulus = MOD>
struct Mint {
    int value;

    Mint(long long v = 0) {
        value = int(v % ll(Modulus));
        if (value < 0) value += Modulus;
    }
    Mint(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }
    friend string to_string(const Mint& a) { return to_string(a.value); }
    Mint& operator+=(Mint const& b) {
        value = ((value + b.value) % Modulus + Modulus) % Modulus;
        return *this;
    }
    Mint& operator-=(Mint const& b) {
        value = ((value - b.value) % Modulus + Modulus) % Modulus;
        return *this;
    }
    Mint& operator*=(Mint const& b) {
        value = (int((value * 1LL * b.value) % Modulus) + Modulus) % Modulus;
        return *this;
    }

    static Mint mexp(Mint a, long long e) {
        Mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    static Mint inverse(Mint a) { return mexp(a, Modulus - 2); }
    Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend istream& operator>>(istream& istream, Mint& a) {
        long long v;
        istream >> v;
        a = v;
        return istream;
    }
    friend ostream& operator<<(ostream& ostream, Mint const& a) { return ostream << a.value; }
    friend bool operator==(Mint const& a, Mint const& b) { return a.value == b.value; }
    friend bool operator!=(Mint const& a, Mint const& b) { return a.value != b.value; }
};

using mint = Mint<MOD>;

mint dp[2][4];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    // dp[i][0] = currently at A at ith step
    // dp[i][1] = currently at B at ith step
    // dp[i][2] = currently at C at ith step
    // dp[i][3] = currently at D at ith step
    for (int i = 0; i < 4; ++i) dp[0][i] = dp[1][i] = 0;
    dp[0][3] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i % 2][0] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][3];
        dp[i % 2][1] = dp[(i + 1) % 2][0] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][3];
        dp[i % 2][2] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][0] + dp[(i + 1) % 2][3];
        dp[i % 2][3] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][0];
    }
    cout << dp[n & 1][3] << '\n';
}