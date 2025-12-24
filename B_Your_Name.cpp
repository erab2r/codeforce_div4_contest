#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        map<char, int> freq;
        for (char c : s) 
            freq[c]++;
        for (char c : t) 
            freq[c]--;

        bool pos = true;
        for (auto &p : freq) {
            if (p.second != 0) {
                pos = false;
                break;
            }
        }

        cout << (pos ? "YES\n" : "NO\n");
    }

    return 0;
}
