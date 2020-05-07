/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, k;
    cin >> n >> k;

    vector<bool> snack(n, 0);

    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int x;
            cin >> x;
            x--;
            snack[x] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!snack[i]) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
