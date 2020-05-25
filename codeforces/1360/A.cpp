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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int s1 = min(max(a+a,b), max(b+b,a));
        cout << s1*s1 << endl;

    }
    
    return 0;
}
