// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

bool compare(pair<int,int>& l, pair<int,int>& r) {
    return l.second > r.second;
}


const int MOD = 998244353;

int mul(int a, int b){
        return (a * 1LL * b) % MOD;
}


int sum(int a, int b){
        return (a + b) % MOD;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f[int(3e5)+99];
    f[0] = 1;

    int n; cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
        f[i+1] = mul(f[i], i+1);
    }
    int r = f[n];

    for (int c = 0; c < 2; ++c) {
        sort(v.begin(), v.end());
        int d = 1;
        for (int i = 0; i < n; i++) {
            int j = i+1;
            while (j < n && v[i].first == v[j].first) j++;
            d = mul(d, f[j-i]);
            i = j-1;   
        }
        r = sum(r, MOD - d);
        for (int i = 0; i < v.size(); i++) {
            swap(v[i].first, v[i].second);
        }
    }

    sort(v.begin(), v.end());
    int l = 0;
    int d = 1;
    while (l < n) {
        int r = l+1;
        while (r < n && v[l].first == v[r].first) r++;
        map<int,int> m;
        for (int i = l; i < r; i++) m[v[i].second]++;
        for (auto p : m) d = mul(d, f[p.second]);
        l = r;
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1].second > v[i].second)
           d = 0;
    }
    r = sum(r, d);
    cout << r << endl; 


    return 0;
}
