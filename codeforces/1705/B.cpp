#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define int ll
void test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &A: a) cin >> A;
	a.pop_back();
	reverse(a.begin(), a.end());
	while(!a.empty() && a.back() == 0) a.pop_back();
	reverse(a.begin(), a.end());
	set<int> zeroes;
	n = int(a.size());
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0){ 
			zeroes.insert(i);
			// cerr << i << '\n';
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		while(a[i] > 0 && !zeroes.empty()) {
			int ii = *zeroes.begin();
			a[ii] = 1;
			zeroes.erase(ii);
			++ans;
			--a[i];
		}
	}
	for(int i = 0; i < n; ++i) ans += a[i];
	cout << ans << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tc = 1;
	cin >> tc;
	while(tc--) {
		test();
	}
}