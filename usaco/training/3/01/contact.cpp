/*
ID: calgagi1
LANG: C++
TASK: contact
*/
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

const int MAX_L = 12;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    
    string input = "", cur;
    while (cin >> cur) {
        input += cur;
    }

    map<string, int> cnt;

    for (int length = a; length <= b; length++) {
        string cur = input.substr(0, length);
        if (cur.length() < length) {
            break;
        }
        cnt[cur]++;
        for (int i = length; i < (int) input.length(); i++) {
            cur.erase(cur.begin());
            cur.push_back(input[i]);
            cnt[cur]++;
        }
    } 

    vector<pair<string,int>> cnts(cnt.begin(), cnt.end());
    
    sort(cnts.begin(), cnts.end(), [&](const pair<string,int>& a, const pair<string,int>& b) {
        if (a.s == b.s) {
            if (a.f.length() == b.f.length()) {
                return a.f < b.f;
            }
            return a.f.length() < b.f.length();
        }
        return a.s > b.s; 
    });

    int m = cnts.size();
    for (int i = 0, counter = 0; i < m && counter < n; counter++) {
        cout << cnts[i].s;
        int j;
        for (j = i; j < m && counter < n && cnts[i].s == cnts[j].s; j++) {
            if ((j-i) % 6 == 0) {
                cout << endl;
            } 
            else {
                cout << " ";
            }
            cout << cnts[j].f;
        }
        cout << endl;
        i = j;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("contact.in", "r", stdin), *OUT = freopen("contact.out", "w", stdout); 

    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
