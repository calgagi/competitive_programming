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

void go(vector<int>& s) {
    for (auto& i : s) {
        cout << i << " ";
    }
    cout << endl;

    return;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans1, ans2;
    for (int i = 0; i < k-1; i++) {
        ans1.push_back(1);
        ans2.push_back(2);
    }

    ans1.push_back(n-(k-1));
    ans2.push_back(n-(k-1)*2);

    bool f1 = 1, f2 = 1;
    for (auto& i : ans1) {
        if (!(i & 1) || i <= 0) {
            f1 = 0;
            break;
        }
    }

    for (auto& i : ans2) {
        if ((i & 1) || i <= 0) {
            f2 = 0;
            break;
        }
    }

    if (f1 || f2) {
        cout << "YES" << endl;
        if (f1) {
            go(ans1);
        } else {
            go(ans2);
        }
    } else {
        cout << "NO" << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
