/*
ID: calgagi1
LANG: C++
TASK: preface
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

vector<pair<string,int>> nums = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, 
    {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4},
    {"I", 1}};

vector<char> numerals = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

string to_roman(int x) {
    string ans = "";
    for (pair<string,int>& n : nums) {
        while (x >= n.s) {
            ans += n.f;
            x -= n.s;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("preface.in", "r", stdin), *OUT = freopen("preface.out", "w", stdout); 

    int n;
    cin >> n;

    map<char,int> ans;
    for (int i = 1; i <= n; i++) {
        string r = to_roman(i);
        for (char c : r) {
            ans[c]++;
        }
    }

    for (int i = 6; i >= 0; i--) {
        if (ans[numerals[i]]) {
            for (int j = 0; j <= i; j++) {
                cout << numerals[j] << " " << ans[numerals[j]] << endl;
            }
            break;
        }
    }


    return 0;
}
