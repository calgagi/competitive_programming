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

struct comp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    vector<int> people(m);
    map<int,int,comp> tickets;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tickets[a]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> people[i];
    }


    for (int i = 0; i < m; i++)  {
        auto w = tickets.lower_bound(people[i]);         
        if (w == tickets.end()) {
            cout << -1 << endl;
        } else {
            cout << w->first << endl;
            w->second--;
            if (w->second == 0) {
                tickets.erase(w);
            }
        }
    }
        

    return 0;
}
