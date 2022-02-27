#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N = 3e5 + 7;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = 3.14159265358979323846;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;

int higher(vector<int>& ar, int ex) {
    if (ar.back() < ex)
        return -1;
    int low = 0;
    int high = ar.size() - 1;
    int ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ar[mid] > ex) {
            ans = std::min(ans, mid);
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return ar[ans];
}

int lower(vector<int>& ar, int ex) {
    if (ar[0] > ex)
        return -1;
    int low = 0;
    int high = ar.size() - 1;
    int ans = low;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ar[mid] < ex) {
            ans = std::max(ans, mid);
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return ar[ans];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    int startx, starty;
    cin >> startx >> starty;

    int endx, endy;
    cin >> endx >> endy;

    map<int, vector<int>> row, col;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        row[a].pb(b);
        col[b].pb(a);
    }

    for (auto& ele : row)
        sort(ele.ss.begin(), ele.ss.end());

    for (auto& ele : col)
        sort(ele.ss.begin(), ele.ss.end());

    queue<pair<int, int>> bfs;
    map<pair<int, int>, int> dist;
    bfs.push({startx, starty});

    dist[{startx, starty}] = 0;
    while (!bfs.empty()) {
        auto node = bfs.front();
        bfs.pop();

        int x = node.ff;
        int y = node.ss;

        // cout << x << " " << y << " -> " << dist[{x,y}] << endl;
        if (row.find(x) != row.end()) {
            int k = higher(row[x], y);
            if (k != -1) {
                if (dist.find({x, k - 1}) == dist.end()) {
                    dist[{x, k - 1}] = dist[{x, y}] + 1;
                    bfs.push({x, k - 1});
                }
            }

            k = lower(row[x], y);
            if (k != -1) {
                if (dist.find({x, k + 1}) == dist.end()) {
                    dist[{x, k + 1}] = dist[{x, y}] + 1;
                    bfs.push({x, k + 1});
                }
            }
        }

        if (col.find(y) != col.end()) {
            int k = higher(col[y], x);
            if (k != -1) {
                if (dist.find({k - 1, y}) == dist.end()) {
                    dist[{k - 1, y}] = dist[{x, y}] + 1;
                    bfs.push({k - 1, y});
                }
            }

            k = lower(col[y], x);
            if (k != -1) {
                if (dist.find({k + 1, y}) == dist.end()) {
                    dist[{k + 1, y}] = dist[{x, y}] + 1;
                    bfs.push({k + 1, y});
                }
            }
        }
    }

    if (dist.find({endx, endy}) == dist.end())
        cout << -1 << "\n";
    else
        cout << dist[{endx, endy}] << "\n";
}