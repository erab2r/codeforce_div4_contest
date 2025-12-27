#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long total = 0;
        for (long long x : a) total += x;

        long long ans = LLONG_MIN;
        long long pref = 0;

        for (int k = 0; k < n; k++) {
            long long left = pref;
            long long right = total - pref - a[k];
            ans = max(ans, left - right);
            pref += a[k];
        }

        cout << ans << "\n";
    }
    return 0;
}
