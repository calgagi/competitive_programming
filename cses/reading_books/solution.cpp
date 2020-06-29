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

void solve() {
    int n;
    cin >> n;
    vector<int> books(n);
    for (int& book : books) {
        cin >> book;
    }

    sort(books.begin(), books.end(), greater<int>());

    ll left = 0, right = 0;
    int countl = 0, countr = 0;
    for (int i = 0; i < n; i++) {
        if (left <= right) {
            left += books[i];
            countl++;
        } else {
            right += books[i];
            countr++;
        }
    }

    if (countr == 1 || countl == 1) {
        cout << max(left, right)*2 << endl;
    } else {
        cout << left+right << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
