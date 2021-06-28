#include <iostream>

using namespace std;

int main() {
    long long int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << (n * m + 1) / 2 << '\n';
    }
}