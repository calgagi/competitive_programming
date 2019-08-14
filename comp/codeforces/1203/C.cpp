// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;


long gcd(long a, long b) { 
        if (a == 0) 
                    return b; 
            return gcd(b % a, a); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    vector<long> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    long g = input[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, input[i]);
    }
    long r = 0;
    for (long i = 1; i <= sqrt(g); i++) {
        if (g % i == 0) {
            if (g / i == i) 
                r++;
            else
                r += 2;
        }
    }
    ld sr = sqrt(g);
    if (sr - floor(sr) == 0) r++; 
    cout << r << endl;  
    


    return 0;
}
