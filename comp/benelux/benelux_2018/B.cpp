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
        b[i] = (a[m]+d) - (a[10]+27)
    }
    sort(b.begin(), b.end());    
    return 0;
}
