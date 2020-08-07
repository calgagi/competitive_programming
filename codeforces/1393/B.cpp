/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    int n;
    cin >> n;
    const int MAX = 1e5;
    int cnt[MAX+1];
    memset(cnt, 0, sizeof(cnt));

    int above4 = 0, above2 = 0, above6 = 0, above8 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        if (cnt[a] == 2) {
            above2++;
        } else if (cnt[a] == 4) {
            above2--, above4++;
        } else if (cnt[a] == 6) {
            above4--, above6++;
        } else if (cnt[a] == 8) {
            above6--, above8++;
        }
    } 

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char event;
        cin >> event;
        int len;
        cin >> len;

        if (event == '-') {
            cnt[len]--;
            if (cnt[len] == 1) {
                above2--;
            } else if (cnt[len] == 3) {
                above4--, above2++;
            } else if (cnt[len] == 5) {
                above6--, above4++;
            } else if (cnt[len] == 7) {
                above8--, above6++;
            }
        } else if (event == '+') {
            cnt[len]++;
            if (cnt[len] == 2) {
                above2++;
            } else if (cnt[len] == 4) {
                above4++, above2--;
            } else if (cnt[len] == 6) {
                above6++, above4--;
            } else if (cnt[len] == 8) {
                above8++, above6--;
            }
        }
        
        if ((above8 >= 1) || (above6 >= 1 && above2 >= 1) || (above4 >= 1 && above2 >= 2) || (above4 + above6 >= 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        /* cout << above6 << " " << above4 << " " << above2 << endl; */
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
