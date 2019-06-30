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
        b[i] = ((a[m]+d) + 364-(a[10]+27)) % 365;
    }
    sort(b.begin(), b.end());
    int r = 0, m = 0;
    for (int j = 1; j < n; j++) {
        if (b[j]-b[j-1]-1 > m) { 
            m = b[j]-b[j-1]-1;
            r = b[j]-1;
        }
    }
    if (b[0]-
    while (m
    return 0;
}
