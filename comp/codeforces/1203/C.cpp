// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;


ull gcd(ull a, ull b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    vector<ull> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    ull g = input[0];
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
    cout << r << endl;  
    


    return 0;
}
