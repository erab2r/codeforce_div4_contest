#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull mygcd(ull a, ull b) {
    while (b) {
        ull h = b;
        b = a % b;
        a = h;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAXP = 2000000;
    vector<bool> val(MAXP + 1, false);
    vector<int> p;
    for (int i = 2; i <= MAXP; ++i) {
        if (!val[i]) {
            p.push_back(i);
            if ((long long)i * i <= MAXP)
                for (int j = i * i; j <= MAXP; j += i) 
                    val[j] = true;
        }
    }
    int tc; 
    cin >> tc;
    while (tc--) {
        int n; 
        cin >> n;
        ull g = 0;
        for (int i = 0; i < n; i++) {
            ull x; 
            cin >> x;
            if (i == 0) 
                g = x;
            else 
                g = mygcd(g, x);
        }

        long long result = -1;
        for (int e : p) {
            if (g % e != 0) { 
                result = e; 
                    break; }
        }

        if (result == -1) {
            auto isPrime = [&](long long x) -> bool {
                if (x < 2) 
                    return false;
                for (int pr : p) {
                    if ((long long)pr * pr > x) 
                        break;
                    if (x % pr == 0) 
                        return false;
                }
                return true;
            };
            long long cur = MAXP + 1;
            if (cur % 2 == 0) ++cur;
            while (cur <= (long long)1e9) {
                if (isPrime(cur) && (g % cur != 0)) {
                        result = cur; 
                            break; }
                cur += 2;
            }
        }
        cout << result << '\n';
    }
}
