/*
ID: calgagi1
LANG: C++
TASK: zerosum
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

vector<string> ans;
int n;

int evaluate(string& x) {
    int res = 0;
    string cur = "";
    int sign = 1;

    for (char& c : x) {
        if (c == ' ') {
            continue;
        }
        if (c == '+' || c == '-') {
            res += stoi(cur) * sign;
            sign = c == '+' ? 1 : -1;
            cur = "";
        } else {
            cur += c;
        }
    }
                
    if (!cur.empty()) {
        res += stoi(cur) * sign;
    }

    return res;
}

void gen(string cur, int i) {
    if (i > n) {
        if (evaluate(cur) == 0) {
            ans.push_back(cur);
        }
        return;
    }

    char x = i + '0';
    gen(cur + " " + x, i+1);
    gen(cur + "+" + x, i+1);
    gen(cur + "-" + x, i+1);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("zerosum.in", "r", stdin), *OUT = freopen("zerosum.out", "w", stdout); 

    cin >> n;
    
    gen("1", 2);

    for (string& x : ans) {
        cout << x << endl;
    }

    return 0;
}
