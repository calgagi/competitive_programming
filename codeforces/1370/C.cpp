/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const vector<string> w = {"Ashishgup", "FastestFinger"};

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << w[1] << endl;
    } else if (n == 2) {
        cout << w[0] << endl;
    } else if ((n & 1)) {
        cout << w[0] << endl;
    } else {
        // check for odd divisor
        bool ok = 0;
        for (int i = 3; i*i <= n; i++) {
            if (n % i == 0 && ((i & 1) || ((n/i) & 1))) {
                ok = 1;
                break;
            }
        }

        // if no odd divisor, A has to subtract 1, making it odd
        if (!ok) {
            cout << w[1] << endl;
            return;
        }
                
        // therefore, n is even with at least one odd divisor
        int count = 0;
        while (n % 2 == 0) {
            count++;
            n /= 2;
        }
        
        // Now, n is odd, call it m. If we divide n by m, then we get some number
        // 2^(count). This number is obviously not divisible by an odd number
        // since the prime factorization of 2^count is all 2's, which ensures there
        // are zero odd divisors.
        // If count >= 2, then we can divide by m and get a non-2 number 2^count, ensuring
        // failure for F. 
        if (count >= 2) {
            cout << w[0] << endl;
            return;
        }

        // However, if count = 1, then dividing by m makes F get 2, which ensures victory for F.
        // So, we need to figure out if m is prime. If m is prime, then F wins by above.
        // If m is not prime (i.e. m = xy), then we can divide n by the maximum odd divisor of m
        // (since odd * even = odd) (say x) and get n/x = 2y, and since 2y is even:
        // Case 1: y is odd: F divides by y, gets 2, A wins
        // Case 2: y is even: F has to subtract 1, making A win
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                cout << w[0] << endl;
                return;
            }
        }

        cout << w[1] << endl;
    }


    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
