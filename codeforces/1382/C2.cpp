/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> ansA, ansB;
    if (a[0] != '0') {
        ansA.push_back(0);
    } 
    if (b[0] != '0') {
        ansB.push_back(0);
    }
    a[0] = b[0] = '0';

    bool flipA = 0, flipB = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            ansA.push_back(i-1);
            flipA = !flipA;
        }
        if (b[i] != b[i-1]) {
            ansB.push_back(i-1);
            flipB = !flipB;
        }
    }

    if (flipA != flipB) {
        ansB.push_back(n-1);
    }

    cout << ansA.size() + ansB.size() << " ";
    for (int i = 0; i < (int) ansA.size(); i++) {
        cout << ansA[i]+1 << " ";
    }
    for (int i = ansB.size()-1; i >= 0; i--) {
        cout << ansB[i]+1 << " ";
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
