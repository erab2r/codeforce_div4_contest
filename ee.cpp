#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll lo = 0, hi = x;
        auto feasible = [&](ll m) -> bool {
            ll count = 0;
            for (ll i = 0; i <= x; ++i) {
                bool ok = true;
                for (ll ai : a) {
                    if (abs(ai - i) < m) { ok = false; break; }
                }
                if (ok) ++count;
                if (count >= k) return true;
            }
            return false;
        };

        // Binary search the maximum minimal distance
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }

        // Collect k positions with distance >= best
        ll best = lo;
        vector<ll> ans;
        for (ll i = 0; i <= x && ans.size() < (size_t)k; ++i) {
            bool ok = true;
            for (ll ai : a) if (abs(ai - i) < best) { ok = false; break; }
            if (ok) ans.push_back(i);
        }

        // If still not enough (shouldn't happen), fill sequentially
        for (ll i = 0; i <= x && ans.size() < (size_t)k; ++i)
            if (find(ans.begin(), ans.end(), i) == ans.end()) ans.push_back(i);

        for (int i = 0; i < k; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
