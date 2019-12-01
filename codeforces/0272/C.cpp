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
    ull s[n+1];
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, h; cin >> w >> h;
        s[1] = max(s[w], s[1]);
        cout << s[1] << endl;
        s[1] += h;   
    }
        
        

    return 0;
}
