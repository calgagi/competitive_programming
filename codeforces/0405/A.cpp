// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int c; cin >> c;
	vector<int> x(101,0);
	for (int i = 0; i < c; i++) {
		int t; cin >> t;
		x[t]++;
	}
	for (int i = 0; i < x.size(); i++) 
		if (x[i] != 0)
			for (int j = 0; j < x[i]; j++) cout << i << " ";
	cout << endl;


	return 0;
}
