// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	unordered_map<int, long long> s({{0, 1000000}, {4,0}, {8,0}, {15,0}, {16,0}, {23,0}, {42,0}});
	unordered_map<int, int> k({{4,0}, {8,4}, {15,8}, {16,15}, {23,16}, {42,23}});
	unordered_map<int, int> b({{4,1}, {8,2}, {15,3}, {16,4}, {23,5}, {42,6}});
	int n; cin >> n;
	int r = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (s[k[x]] == 0) {
			r++;
		} else {
			s[k[x]]--;
			if (x == 42) {
				s[42]--;
			}
			s[x]++;
		}
	}	   
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it->first != 0) {
			r+=it->second*b[it->first];
		}
	}
	cout << r << endl;
	return 0;
}
