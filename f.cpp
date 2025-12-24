#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    if (!(cin >> tc)) 
        return 0;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(n+1);
        for (int i = 0; i < n-1; i++) {
            int h, e; 
            cin >> h >> e;
            arr[h].push_back(e);
            arr[e].push_back(h);
        }
        vector<int> p(n+1, -1), sz(n+1, 0);
        vector<int> ss; 
        ss.reserve(n);
        ss.push_back(1);
        p[1] = 0;
        for (int i = 0; i < (int)ss.size(); i++) {
            int u = ss[i];
            for (int v : arr[u]) 
                if (v != p[u]) {
                p[v] = u;
                ss.push_back(v);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            int u = ss[i];
            sz[u] = 1;
            for (int v : arr[u]) 
                if (v != p[u]) 
                    sz[u] += sz[v];
        }
        long long result = 0;
        if (n >= k) {
            result += n;
        }
        for (int u = 1; u <= n; ++u) {
            for (int v : arr[u]) {
                int cmp;
                if (p[u] == v) {
                    cmp = sz[u];
                } else {
                    cmp = n - sz[v];
                }
                if (cmp >= k) {
                    int r = n - cmp;
                    result += r;
                }
            }
        }

        cout << result << '\n';
    }
    return 0;
}
