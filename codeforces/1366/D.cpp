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

const int MAX_A = 1e7;
vector<int> line1, line2;
vector<int> low_prime(MAX_A+1, 0);

vector<int> factor(int A) {
    set<int> ans;
    while (A != 1) {
        ans.insert(low_prime[A]);
        A /= low_prime[A];
    } 

    return vector<int>(ans.begin(), ans.end());
}

void go(int A) {
    vector<int> primes = factor(A);

    if (primes.size() == 1) {
        line1.push_back(-1);
        line2.push_back(-1);
    } else {
        line1.push_back(primes[0]);
        int line2_ans = 1;
        for (int i = 1; i < (int) primes.size(); i++) {
            line2_ans *= primes[i];
        }
        line2.push_back(line2_ans);
    }

    return;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        go(A[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << line1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << line2[i] << " ";
    }
    cout << endl;

    return;
}

void preprocess() {
    for (int i = 2; i <= MAX_A; i++) {
        if (low_prime[i] == 0) {
            low_prime[i] = i;
            for (int j = i+i; j <= MAX_A; j += i) {
                if (low_prime[j] == 0) {
                    low_prime[j] = i;
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    preprocess();
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
