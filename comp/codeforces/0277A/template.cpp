// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, l; cin >> n >> l;
	vector<set<int> > b(n+1);
	vector<set<int> > s(l+1);
	set<int> visit;
	int d = 0;
	for (int i = 1; i < n+1; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int y; cin >> y;
			s[y].insert(i);
			b[i].insert(y);
		}
		if (x == 0) d++; 
		visit.insert(i);
	}
	if (d == n) {
		cout << n << endl;
		return 0;
	}
	vector<set<int> > g(n+1);
	for (int i = 0; i < n+1; i++) {
		for (auto it = b[i].begin(); it != b[i].end(); ++it) {
			for (auto it2 = s[*it].begin(); it2 != s[*it].end(); ++it2)
				g[i].insert(*it2);
		}
	}
			
	int c = 0;
	while (!visit.empty()) {
		queue<int> st;
		st.push(*(visit.begin()));
		while (!st.empty()) {
			int x = st.front();
			st.pop();
			if (visit.find(x) == visit.end()) continue;
			visit.erase(visit.find(x));
			for (auto it = g[x].begin(); it != g[x].end(); ++it) {
				st.push(*it);
			}
		}
		c++;
	}
	cout << c-1 << endl;	

	return 0;
}
