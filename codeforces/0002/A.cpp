// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string name; int p;
    unordered_map<string, int> people;
    unordered_map<string, vector<pair<int, int> > > turns;
    for (int i = 0; i < n; i++) {
        cin >> name >> p;
        people[name] += p;
        turns[name].push_back({p, i});
    } 
    vector<string> w;
    int MAX = INT_MIN;
    for (auto it = people.begin(); it != people.end(); it++)
        MAX = max(it->second, MAX);
    for (auto it = people.begin(); it != people.end(); it++) 
        if (it->second == MAX) w.push_back(it->first);
    int first = INT_MAX;
    string r = "";
    for (string &s : w) {
        int total = 0;
        for (pair<int,int> &t : turns[s]) {
            total += t.first;
            if (total >= MAX && first > t.second) {
                first = t.second;
                r = s;
            }
        }
    }

    cout << r << endl;


    return 0;
}
