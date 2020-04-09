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

const int MAX_X = 1e6;
vector<int> ans(MAX_X+1, 1);
int t;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 2; i <= MAX_X; i++) {
        for (int j = i; j <= MAX_X; j += i) {
            ans[j]++;
        } 
    }

    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
    cout << endl;

    return 0;
}
