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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    string g;
    getline(cin, g);
    n = stoi(g);
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);
        for (auto& c : x) {
            c = tolower(c);
            if (c == ' ') {
                c = '-';
            }
        }
        s.insert(x);
    }

    cout << s.size() << endl;
    /* for (auto& x : s) { */
    /*     cout << x << endl; */
    /* } */

    return 0;
}
