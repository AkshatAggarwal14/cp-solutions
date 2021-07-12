//@aryanpathania
#include <bits/stdc++.h>
#define MOD 1'000'000'007
//#define MOD = 998'244'353
#define int int64_t
typedef long long ll;
typedef long double ld;
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

void solve() {
    int n;
    std::cin >> n;
    std::deque<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    while (d[0] != 1) {
        int temp = d[0];
        d.pop_front();
        d.push_back(temp);
    }

    if (std::is_sorted(d.begin(), d.end())) {
        std::cout << "YES" << '\n';
        return;
    }

    int temp = d[0];
    d.pop_front();
    d.push_back(temp);

    // if (std::is_sorted(d.begin(), d.end(), greater<int>())) { //!SAME
    if (std::is_sorted(d.begin(), d.end(), compare)) {
        std::cout << "YES" << '\n';
        return;
    }

    std::cout << "NO" << '\n';
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testcases;
    std::cin >> testcases;

    while (testcases--) {
        solve();
    }

    return 0;
}
/*
───────▄▀▀▀▀▀▀▀▀▀▀▄▄
────▄▀▀░░░░░░░░░░░░░▀▄
──▄▀░░░░░░░░░░░░░░░░░░▀▄
──█░░░░░░░░░░░░░░░░░░░░░▀▄
─▐▌░░░░░░░░▄▄▄▄▄▄▄░░░░░░░▐▌
─█░░░░░░░░░░░▄▄▄▄░░▀▀▀▀▀░░█
▐▌░░░░░░░▀▀▀▀░░░░░▀▀▀▀▀░░░▐▌
█░░░░░░░░░▄▄▀▀▀▀▀░░░░▀▀▀▀▄░█
█░░░░░░░░░░░░░░░░▀░░░▐░░░░░▐▌
▐▌░░░░░░░░░▐▀▀██▄░░░░░░▄▄▄░▐▌
─█░░░░░░░░░░░▀▀▀░░░░░░▀▀██░░█
─▐▌░░░░▄░░░░░░░░░░░░░▌░░░░░░█
──▐▌░░▐░░░░░░░░░░░░░░▀▄░░░░░█
───█░░░▌░░░░░░░░▐▀░░░░▄▀░░░▐▌
───▐▌░░▀▄░░░░░░░░▀░▀░▀▀░░░▄▀
───▐▌░░▐▀▄░░░░░░░░░░░░░░░░█
───▐▌░░░▌░▀▄░░░░▀▀▀▀▀▀░░░█
───█░░░▀░░░░▀▄░░░░░░░░░░▄▀
──▐▌░░░░░░░░░░▀▄░░░░░░▄▀
─▄▀░░░▄▀░░░░░░░░▀▀▀▀█▀
▀░░░▄▀░░░░░░░░░░▀░░░▀▀▀▀▄▄▄▄▄

*/