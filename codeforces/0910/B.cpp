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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> p = {a, a, a, a, b, b};
    int ans = 6;
    for (int i = 0; i < 10000; i++) {
        random_shuffle(p.begin(), p.end());
        int a = 1, c = n;
        for (int j = 0; j < 6; j++) {
            if (c < p[j]) {
                a++;
                c = n;
            }
            c -= p[j];
        }
        ans = min(a, ans);
    }

    cout << ans << endl;

    return 0;
}
