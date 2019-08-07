// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

ull factorial(int x) {
    ull t = 1;
    for (int i = 1; i <= x; i++) {
        t *= i;
    }
    return t;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ull> f(3);
    f[2] = 1;


    int n; cin >> n; 
    for (int t = 0; t < n; t++) {
        ull x; cin >> x;
        while (f.back() < x) {
            f.push_back((factorial(f.size()+1))/(2*f[f.size()-2]));
        }
        int numE = f.size()-1;
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
        for (int i = 0; i < numE; i++)
            cout << '3';
        for (int i = 0; i < numS; i++)
            cout << '7';
        cout << endl;
    }

    return 0;
}
