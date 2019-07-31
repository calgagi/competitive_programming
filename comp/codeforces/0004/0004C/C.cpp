// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	string s;
	unordered_map<string, int> db;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (db.find(s) == db.end()) {
			cout << "OK" << endl;
			db[s]++;
		} else {
			string t = s + to_string(db[s]);
			cout << t << endl;
			db[t]++;
			db[s]++;
		}	
	}

	return 0;
}
