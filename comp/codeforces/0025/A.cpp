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
    int even_idx = 0, odd_idx = 0;
    int even_c = 0, odd_c = 0;
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        if (j % 2) {
            odd_c++;
            odd_idx = i+1;
        } else {
            even_c++;
            even_idx = i+1;
        }
    }
    if (odd_c == 1)
        cout << odd_idx << endl;
    else
        cout << even_idx << endl;

    return 0;
}
