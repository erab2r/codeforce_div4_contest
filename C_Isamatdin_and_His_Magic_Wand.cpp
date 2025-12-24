#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    if (!(cin >> tc)) 
        return 0;
    while (tc--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        bool ans_Even = false, ans_Odd = false;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] % 2 == 0) 
                ans_Even = true;
            else 
                ans_Odd = true;
        }
        if (ans_Even && ans_Odd) {
            sort(arr.begin(), arr.end());
        }
        for (int i = 0; i < n; i++) {
            if (i) 
                cout << ' ';
            cout << arr[i];
        }
        cout << '\n';
    }
    return 0;
}










