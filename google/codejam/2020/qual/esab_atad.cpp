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

int T, n;

void compliment(vector<char>& b) {
    for (auto& x : b) {
        x = x=='0'?'1':'0';
    }
    return;
}

/* void print(vector<char>& b) { */
/*     for (auto& x : b) { */
/*         cerr << x; */
/*     } */
/*     cerr << endl; */
/*     return; */
/* } */

char solve() {
    //cerr << "TEST: " << T << endl;
    vector<char> b(n, 'A');
    int num_queries = 0, same = -1, diff = -1;
    for (int i = 1; i <= n/2; i++) {
        cout << i << endl;
        fflush(stdout);
        cin >> b[i-1];
        cout << n-i+1 << endl;
        fflush(stdout);
        cin >> b[n-i];
        num_queries += 2;
        if (b[i-1] == b[n-i]) {
            same = i;
        } else {
            diff = i;
        }
        // observation: need 2 queries to check what happened
        if (num_queries % 10 == 0) {
            // If haven't seen same and diff thing yet, then just need to check
            // if something happened (reversed and complimented do same thing)
            /* print(b); */
            if (same == -1 || diff == -1) {
                char x;
                cout << i << endl;
                fflush(stdout);
                cin >> x;
                if (x != b[i-1]) {
                    compliment(b);
                }
                // preserve evenness of queries
                cout << i << endl;
                fflush(stdout);
                cin >> x;
            // Else there is a same pair and diff pair. Need to check specifically what happened
            } else {
                char x;
                // First, check if compliment happened
                cout << same << endl;
                fflush(stdout);
                cin >> x;
                if (x != b[same-1]) {
                    compliment(b);
                    // Now need to check if both happened
                    cout << diff << endl;
                    fflush(stdout);
                    cin >> x;
                    /* //cerr << "COM: " << x << " " << b[diff] << endl; */
                    if (x != b[diff-1]) {
                        reverse(b.begin(), b.end());
                    }
                } else {
                    // Now need to check if just reverse happened
                    cout << diff << endl;
                    fflush(stdout);
                    cin >> x;
                    /* //cerr << "NOC: " << x << " " << b[diff] << endl; */
                    if (x != b[diff-1]) {
                        reverse(b.begin(), b.end());
                    }
                    // else nothing happened
                }
            }
            num_queries += 2;
        }
    }
    // Now, print
    string p = "";
    for (int i = 0; i < n; i++) {
        p += b[i];
    }
    /* cerr << p << endl; */
    cout << p << endl;
    fflush(stdout);
    char ans;
    cin >> ans;
    return ans;
}
        

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> T >> n;
    while (T--) {
        char x = solve();
        if (x == 'N') {
            break;
        }
    }

    return 0;
}
