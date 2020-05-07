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
    
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto& i : heights) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j+i < n; j++) {
            if (heights[j]+heights[j+i] == i) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
