#include <bits/stdc++.h>
using namespace std;

struct binary_trie {
    struct TrieNode {
        TrieNode *bit[2];
        int cnt, end;
        TrieNode() {
            cnt = end = 0;
            bit[0] = bit[1] = nullptr;
        }
    };

    TrieNode *root = new TrieNode();
    void insert(int x) {
        TrieNode *cur = root;
        // reverse number in binary for due to max queries
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) {
                cur->bit[b] = new TrieNode();
            }
            cur = cur->bit[b];
            ++cur->cnt;
        }
        ++cur->end;
    }

    void remove(int x) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) return;  // word doesnt exist
            if (cur->bit[b]->cnt == 1) {
                cur->bit[b] = nullptr;
                return;
            }
            cur = cur->bit[b];
            --cur->cnt;
        }
        --cur->end;
    }

    int get_min_xor(int x) {
        TrieNode *cur = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            // start from end to get max ans
            int b = (x >> i) & 1;
            if (cur->bit[b]) {  // if opposite set
                cur = cur->bit[b];
            } else if (cur->bit[b ^ 1]) {
                ans |= (1 << i);
                cur = cur->bit[b ^ 1];
            }
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    binary_trie trie;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        trie.insert(num);
    }
    for (auto &i : a) {
        int val = trie.get_min_xor(i);
        trie.remove(val ^ i);
        cout << val << ' ';
    }

    return 0;
}
