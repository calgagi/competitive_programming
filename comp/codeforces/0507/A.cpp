// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int b;
	int n, k; cin >> n >> k;
	vector< vector<int> > r(101);
	for (int i = 0; i < n; i++) {
		cin >> b; r[b].push_back(i+1);
	}
	vector<int> x;
	for (int i = 0; i < r.size(); i++) {
		while (r[i].size() && k-i >= 0) {
			x.push_back(r[i][0]);
			r[i].erase(r[i].begin());
			k -= i;	
		}
	}
	cout << x.size() << endl;
	for (int i = 0; i < x.size(); i++) cout << x[i] << " ";

	return 0;
}
