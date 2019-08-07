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

    ull* f = new ull[50];
    f[1] = f[0] = f[2] = 1;
    ull t = 1;
    for (int i = 2; i < 50; i++) {
        t *= i;
        f[i] = t / (2 * f[i-2]);
    }


    int n; cin >> n; 
    for (int t = 0; t < n; t++) {
        ull x; cin >> x;
        int numE = min((int)sqrt(x), 50);
        while (x % f[numE] != 0) {
            numE--;
        }
        x /= f[numE];
        int numS = 1;
        if (x != 1) {
            for (numS = sqrt(x); numS >= 1; numS--) {
                if (x % numS == 0)
                    break;
            }
        }
        int numO = x / numS;
        for (int i = 0; i < numO; i++)
            cout << '1';
        for (int i = 0; i < max(numE, 2); i++)
            cout << '3';
        for (int i = 0; i < numS; i++)
            cout << '7';
        cout << endl;
    }

    return 0;
}
