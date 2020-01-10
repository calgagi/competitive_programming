// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    long long x; cin >> x;

    long long m = sqrt(x);

    long long ans1 = 1, ans2 = x;
    for (long long i = 2; i <= m; i++) {
        if (x % i == 0 && lcm(i, x/i) == x && max(ans1, ans2) > max(i, x/i)) {
            ans1 = i;
            ans2 = x/i;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
