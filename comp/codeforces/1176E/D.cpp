// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m; cin >> n >> m;	   
		vector<vector<int> > g(n+1, vector<int>(n+1, 0));
		for (int j = 0; j < m; j++) {
			int r, c; cin >> r >> c;
			g[c][r] = 1;
			g[r][c] = 1;
		}
		vector<int> r(n+1, 0);
		stack<pair<int,bool> > q;
		q.push({1, false});
		set<int> seen;
		while (!q.empty()) {
			int v = q.top().first;
			bool p = q.top().second;
			q.pop();
			if (seen.find(v) != seen.end()) continue;
			if (p) r[v] = 1;
			seen.insert(v);
			for (int i = 1; i <= n; i++)
				if (g[v][i] == 1 && seen.find(i) == seen.end()) q.push({i, !p});
		}
		int z = 0, o = 0; 
		for (int i = 1; i < r.size(); i++) {
			if (r[i]) o++;
			else z++;
		}
		if (o < z) {
			cout << o << endl;
			for (int i = 1; i < r.size(); i++) 
				if (r[i]) cout << i << " ";
			cout << endl;
		} else {
			cout << z << endl;
			for (int i = 1; i < r.size(); i++) 
				if (!r[i]) cout << i << " ";
			cout << endl;
		}
	}

	return 0;
}
