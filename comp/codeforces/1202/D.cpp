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
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n; 
        int num3 = 2;
        while (num3 * (num3+1) / 2 <= n) num3++;
        n -= (num3 * (num3-1)/2);
        cout << "133";
        for (int i = 0; i < n; i++) cout << "7";
        for (int i = 0; i < num3-2; i++) cout << "3";
        cout << "7" << endl;
    }

    return 0;
}
