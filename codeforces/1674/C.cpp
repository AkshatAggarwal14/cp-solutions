#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        if(t == "a") cout << "1\n";
        else if(count(t.begin(), t.end(), 'a')) cout << "-1\n";
        else cout << (1LL<<int(s.size())) << '\n';
    }
}