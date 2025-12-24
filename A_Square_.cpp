#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<int> arr = {a, b, c, d};
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
