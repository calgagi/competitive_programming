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

    int r = 0;
    int n; cin >> n;
    stack<long> s;
    s.push(1);
    while (!s.empty()) {
        long t = s.top(); s.pop();
        if (t <= n) r++;
        else continue;
        t *= 10;
        s.push(t);
        t++;
        s.push(t);
    }
    cout << r << endl;

    return 0;
}
