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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ii> where(k), pass(k);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        where[i] = {a,b};
    } 
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        pass[i] = {a,b};
    }

    // O(min(k^2 log(k), 2nm))
    string ans = "";
    while (where.size()) {
        vector<ar<int,3>> dist((int) where.size());
        for (int i = 0; i < (int) where.size(); i++) {
            dist[i] = {0, pass[i].first-where[i].first, pass[i].second-where[i].second};
            dist[i][0] = abs(dist[i][1])+abs(dist[i][2]);
        }
        sort(dist.begin(), dist.end());
        int r = dist[0][1], c = dist[0][2];
        for (int i = 0; i < (int) where.size(); i++) {
            where[i].first += r;
            where[i].second += c;
            where[i].first = where[i].first>n?n:(where[i].first<1?1:where[i].first);
            where[i].second = where[i].second>m?m:(where[i].second<1?1:where[i].second);
            if (where[i].first == pass[i].first && where[i].second == pass[i].second) {
                where.erase(where.begin()+i);
                pass.erase(pass.begin()+i);
                i--;
            }
        }
        char a = r<0?'U':'D', b = c<0?'L':'R';
        for (int i = 0; i < abs(r); i++) {
            ans += a;
        }
        for (int i = 0; i < abs(c); i++) {
            ans += b;
        }
        if ((int) ans.length() > 2*m*n) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << ans.length() << endl << ans << endl; 

    return 0;
}
