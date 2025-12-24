#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<long long> arr(n), e(n);
        for (auto &x : arr) 
            cin >> x;
        for (auto &x : e) 
            cin >> x;
        vector<long long> value = arr;
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(), value.end()), value.end());
        int h = value.size();

        const long long INF = 1e18;
        vector<long long> dp(h, 0), set_dp(h, 0);
        for (int j = 0; j < h; j++) {
            dp[j] = (value[j] == arr[0]) ? 0 : e[0];
        }

        for (int i = 1; i < n; i++) {
            vector<long long> pref(h);
            pref[0] = dp[0];
            for (int j = 1; j < h; j++)
                pref[j] = min(pref[j - 1], dp[j]);

            for (int j = 0; j < h; j++) {
                long long cost = (value[j] == arr[i]) ? 0 : e[i];
                set_dp[j] = pref[j] + cost;
            }
            dp.swap(set_dp);
        }

        cout << *min_element(dp.begin(), dp.end()) << "\n";
    }
}
