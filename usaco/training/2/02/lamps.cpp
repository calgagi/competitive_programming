/*
ID: calgagi1
LANG: C++
TASK: lamps
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

vector<int> on, off;
set<string> ans;

void check(string s) {
    for (auto& b : on) {
        if (s[b] != '1') {
            return;
        }
    }
    for (auto& b : off) {
        if (s[b] != '0') {
            return;
        }
    }
    ans.insert(s);
    return;
} 

string button1(string s) {
    for (auto& c : s) {
        c = c == '1' ? '0' : '1';
    }
    return s;
}

string button2(string s) {
    for (int i = 0; i < (int) s.length(); i += 2) {
        s[i] = s[i] == '1' ? '0' : '1';
    }
    return s;
}

string button3(string s) {
    for (int i = 1; i < (int) s.length(); i += 2) {
        s[i] = s[i] == '1' ? '0' : '1';
    }
    return s;
}

string button4(string s) {
    for (int i = 0; i < (int) s.length(); i += 3) {
        s[i] = s[i] == '1' ? '0' : '1';
    }
    return s;
}

void dfs(string s, int cur) {
    if (cur == 0) {
        check(s);
        return;
    }   
    dfs(button1(s), cur-1);
    dfs(button2(s), cur-1);
    dfs(button3(s), cur-1);
    dfs(button4(s), cur-1);
    return;
} 

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("lamps.in", "r", stdin), *OUT = freopen("lamps.out", "w", stdout); 

    int n, c;
    cin >> n >> c;
    
    string s = "";
    for (int i = 0; i < n; i++) {
        s.push_back('1');
    }

    int x;
    while (1) {
        cin >> x;
        if (x == -1) {
            break;
        }
        x--;
        on.push_back(x);
    }
    while (1) {
        cin >> x;
        if (x == -1) {
            break;
        }
        x--;
        off.push_back(x);
    }

    dfs(s, min(c, 8));
    
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (string x : ans) {
            cout << x << endl;
        }
    }

    return 0;
}
