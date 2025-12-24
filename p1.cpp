#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long e;
        cin >> e;
        while (e % 2 == 0) {
            e /= 2;
        }

        if (e == 1 || e == 3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}