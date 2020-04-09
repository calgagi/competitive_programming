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

int n;
const int MAX_N = 1e6;
vector<int> a, seen(MAX_N+1, 0);

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n;
    a.resize(n);
    for (auto& b : a) {
        cin >> b;
        for (int i = 1; i*i <= b; i++) {
            if (b % i == 0) {
                seen[b/i]++;
                if (i*i != b) {
                    seen[i]++;
                }
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= MAX_N; i++) {
        if (seen[i] > 1) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
