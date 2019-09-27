// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;
    
    vector<int> s(n*k);
    for (int i = 0; i < n*k; i++) cin >> s[i];

    sort(s.begin(), s.end());

    int e = n-1;
    if (s[e] - s[0] > l) {
        cout << "0" << endl;
        return 0;
    }
    while (e < s.size() && s[e] - s[0] <= l) e++;

    ll r = 0, j = 0;
    for (int i = 0; i < n; i++) {
        r += s[i];
        ll m = j;
        while (j <= e - (n-i) && j-m < k) j++; 
    } 
    cout << r << endl;
    return 0;
}
