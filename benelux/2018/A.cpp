// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, c; cin >> n >> c;
    vector<long long> a(n); 
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    int r = 1;
    for (r = 1; r < n; r++)
        if (a[r-1] + a[r] > c) break;
    cout << r << endl;

    return 0;
}
