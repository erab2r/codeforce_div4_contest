#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> m_int(vector<pair<ll,ll>>& s1) {
    vector<pair<ll,ll>> ss;
    if (s1.empty()) 
        return ss;
    sort(s1.begin(),s1.end());
    ll L = s1[0].first, R = s1[0].second;
    for (size_t i = 1; i < s1.size(); i++) {
        if (s1[i].first <= R + 1) {
            R = max(R, s1[i].second);
        } else {
            ss.emplace_back(L,R);
            L = s1[i].first;
            R = s1[i].second;
        }
    }
    ss.emplace_back(L,R);
    return ss;
}

bool fun(ll m, const vector<ll>& a, ll x, ll k) {
    if (m == 0) {
        return (x + 1) >= k;
    }
    ll r = m - 1;
    vector<pair<ll,ll>> s2;
    for (ll ai : a) {
        ll L = max(0LL, ai - r);
        ll R = min(x, ai + r); 
        if (L <= R) s2.emplace_back(L, R);
    }
    if (s2.empty()) return (x + 1) >= k;
    auto merged =  m_int(s2);
    ll f = 0;
    for (auto &p : merged) {
        f += (p.second - p.first + 1);
        if (f > x + 1) { f = x + 1; break; }
    }
    ll allowed = (x + 1) - f;
    return allowed >= k;
}

vector<ll> c_pos(ll m, const vector<ll>& a, ll x, ll k) {
    vector<ll> ans;
    if (k == 0) return ans;
    unordered_set<ll> used; used.reserve((size_t)k*2);
    if (m == 0) {
        for (ll p = 0; p <= x && (ll)ans.size() < k; ++p) {
            ans.push_back(p);
            used.insert(p);
        }
        return ans;
    }
    ll r = m - 1;
    vector<pair<ll,ll>> segs;
    for (ll ai : a) {
        ll L = max(0LL, ai - r);
        ll R = min(x, ai + r);
        if (L <= R) segs.emplace_back(L, R);
    }
    auto mr =  m_int(segs);
    ll pos = 0;
    for (auto &iv : mr) {
        if (pos <= iv.first - 1) {
            ll start = pos;
            ll end = iv.first - 1;
            for (ll p = start; p <= end && (ll)ans.size() < k; p++) {
                ans.push_back(p);
                used.insert(p);
            }
        }
        pos = iv.second + 1;
        if ((ll)ans.size() >= k) break;
    }
    for (ll p = pos; p <= x && (ll)ans.size() < k; ++p) {
        if (used.find(p) == used.end()) {
            ans.push_back(p);
            used.insert(p);
        }
    }
    if ((ll)ans.size() < k) {
        for (ll p = 0; p <= x && (ll)ans.size() < k; ++p) {
            if (used.find(p) == used.end()) {
                ans.push_back(p);
                used.insert(p);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    if (!(cin >> tc)) 
        return 0;
    while (tc--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> arr(n);
        for (int i = 0; i < (int)n; i++) 
            cin >> arr[i];
        ll l = 0, h = x;
        while (l < h) {
            ll mid = l + (h - l + 1) / 2;
            if (fun(mid, arr, x, k)) 
                l = mid;
            else 
                h = mid - 1;
        }
        ll pos = l;
        auto result = c_pos(pos, arr, x, k);
        for (int i = 0; i < (int)k; ++i) {
            if (i) 
                cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}


