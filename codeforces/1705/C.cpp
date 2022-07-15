#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define int ll
void test() {
	int n, c, q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	vector<int> len;
	len.push_back(n);
	vector<array<int, 2>> Q(c);
	for(auto &[x, y]: Q) cin >> x >> y, --x, --y, len.push_back(y - x  + 1);
	for(int i = 1; i < int(len.size()); ++i) len[i] += len[i - 1];
	while(q--) {
		int id;
		cin >> id;
		int cnt = 0;
		while(id > n) {
			auto i = lower_bound(len.begin(), len.end(), id) - len.begin();
			id = id - len[i - 1] + Q[i - 1][0];
			++cnt;
			assert(cnt <= c + 2);
		}
		cout << s[id - 1] << '\n';
		/*
		while(true) {
			if(id <= n) break; 
			auto i = lower_bound(len.begin(), len.end(), id) - len.begin();
			if(i == 0) break;
			cerr << i << '\n';
			int l = Q[i - 1][0], r = Q[i - 1][1];
			--l, --r;
			cerr << l << ' ' << r << ' ' << id << '\n';
			int before = len[i - 1];
			int pos_now = id - before;
			int new_pos = pos_now + l - 1;
			id = new_pos + 1;
		}
		cout << s[id - 1] << '\n';
		if(i == 0) {
			--id;
			cout << s[id] << '\n';
		} else {
			id -= len[i - 1];
			--id;
			int l = Q[i - 1][0], r = Q[i - 1][1];
			--l, --r;
			cerr << l << ' ' << r << ' ' << id << '\n';
			cout << s[id + l] << '\n';
		} */
	}
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tc = 1;
	cin >> tc;
	while(tc--) {
		test();
	}
}