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

    string s, t;
    cin >> s >> t;
    int r = 0;
    int c = 0;
    int x = s.find(t, c);
    while (x != -1) {
        r = max(r, x);
        r = max(r, (int)(s.length()-t.length()-x));
        c = x+1;
        x = s.find(t, c);
    }
    cout << r << endl;  

    return 0;
}
