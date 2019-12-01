// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string throwaway; char d;
    int a[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int m, o;
        cin >> throwaway >> m >> d >> o;
        b[i] = a[m]+o; 
    }
    sort(b.begin(), b.end());
    int oct27 = a[10] + 28;
//    cout << oct27 << endl;
    // Find first after
    int f = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] > oct27) { 
            f = i;
            break; 
        }
    }
    if (f == -1) f = 0;
    int x = -9999999;
    int r = 1;
    for (int i = 0; i < n; i++) {
        int index = (i + f) % n;
        int prev = (i + f - 1) % n;
        // cout << prev << " - " << index << endl;
        int diff;
        if (prev < 0) {
            prev = n-1;
            diff = (365-b[prev]) + b[index];
        } else diff = b[index] - b[prev];
 //       cout << b[prev] << " - " << b[index] << ": " << diff << endl;
        if (diff > x) {
            x = diff;
            r = b[index]-1;
        }
    }
    int i = 0;
    if (r == 0) r = 365;
    while (a[i] < r && i < 13) i++;
    if (i-1 < 10) cout << "0";
    cout << i-1 << "-";
    if (r - a[i-1] < 10) cout << "0";
    cout << r - a[i-1] << endl;
    return 0;
}
