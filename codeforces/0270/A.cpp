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
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int ea = 180-a;
        if (360 % ea == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}
