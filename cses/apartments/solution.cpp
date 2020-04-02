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
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& i : a) {
        cin >> i;
    } 
    for (auto& i : b) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0, j = 0; j < m && i < n; i++) {
        while (j < m && b[j] < a[i]-k) {
            j++;
        }
        if (a[i]-k <= b[j] && b[j] <= a[i]+k) {
            ans++;
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}
