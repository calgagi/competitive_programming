// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    // Algorithm:
    // I had figured out that (n = i*p + (b_1 + b_2 + ... + b_i)
    // Then, this equates to n - i*p = (b_1 + b_2 + ... + b_i)
    // So, if there is an equal amount of set bits in x to i, then answer = i.
    // The part I missed:
    //  But, however, it turns out if there are less than the amount of set bits,
    //  then the "higher" bit powers can be expanded to 2 slightly lower bit powers. 
    //  This only works if there are enough bits to be expanded to lower bit powers
    //  though.
    // This rectifies this:
    //  Since the absolute minimum binary number is 1, then n - p*i must be 
    //  equal to at least i (because n-p*i = (1 + 1 + ... + 1)). If not, cannot work.


    long long n, p; cin >> n >> p;
    for (int i = 1; i < 50; i++) {
        long long x = n - (i * p); 
        int c = 0;
        for (int j = 0; j < 64; j++)
            c = c + (((1LL<<j) & x)?1:0);
        if (c <= i) {
            if (n >= 31*p + 31 && i > 31) continue;
            if (x < i) continue; 
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
