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
    int n; cin >> n;
    ull ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    pair<ull,ull> mnl[n];
    pair<ull,ull> mnr[n];
    mnl[0] = {ar[0], 1};
    mnr[n-1] = {ar[n-1], 1};
    ull a = ar[0], b, c;
    b = c = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (ar[i] < mnl[i-1].first) {
            mnl[i].first = ar[i];
            mnl[i].second = 1;
        } else if (ar[i] == mnl[i-1].first) {
            mnl[i].second = mnl[i-1].second+1;
            mnl[i].first = ar[i];
        } else {
            mnl[i] = mnl[i-1];
        }
        if (ar[n-i-1] < mnr[n-i].first) {
            mnr[n-i-1].first = ar[n-i-1];
            mnr[n-i-1].second = 1;
        } else if (ar[n-i-1] == mnr[n-i].first) {
            mnr[n-i-1].second = mnr[n-i].second+1;
            mnr[n-i-1].first = ar[n-i-1];
        } else {
            mnr[n-i-1] = mnr[n-i];
        }

        if (ar[i] < a) {
            c = b;
            b = a;
            a = ar[i];
        } else if (ar[i] < b) {
            c = b;
            b = ar[i];
        } else if (ar[i] < c) {
            c = ar[i];
        }
    }
    multiset<ull> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    ull r = 0;
    for (int i = 1; i < n-1; i++) {
        multiset<ull> x = {mnl[i-1].first, ar[i], mnr[i+1].first};
        if (s == x) {
            r = r + (mnl[i-1].second * mnr[i+1].second);
        }
    }
    cout << r << endl;
        

    return 0;
}
