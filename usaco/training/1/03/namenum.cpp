/*
ID: calgagi1
LANG: C++
TASK: namenum
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

vector<string> mp;

bool is_valid(const string& srch, const string& cand) {
    if (srch.size() != cand.size()) 
        return false;

    for (int i = 0; i < (int) srch.size(); i++) {
        if (mp[srch[i]-'0'].find(cand[i]) == string::npos) {
            return false;
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("namenum.in", "r", stdin), *OUT = freopen("namenum.out", "w", stdout); 
    fstream dict;
    dict.open("dict.txt", fstream::in);

    mp = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

    string in, srch;
    cin >> srch;
    vector<string> ans;
    while (true) {
        dict >> in;
        if (dict.fail()) break;
        if (is_valid(srch, in)) {
            ans.push_back(in);
        }
    }

    if ((int) ans.size() == 0) {
        cout << "NONE" << endl;
    } else {
        for (auto& s : ans) {
            cout << s << endl;
        }
    }

    return 0;
}
