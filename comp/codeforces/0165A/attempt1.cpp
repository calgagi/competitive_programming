// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	int r = 0;
	int gx[2][2001];
	int gy[2][2001];
	memset(gx[0], -1001, 2001);
	memset(gx[1], 1001, 2001);
	memset(gy[0], -1001, 2001);
	memset(gy[1], 1001, 2001);
	int p[2][200];
	for (int i = 0; i < n; i++) {		
		cin >> p[0][i] >> p[1][i];
		
		gx[0][p[0][i]+1000] = max(gx[0][p[0][i]+1000], p[1][i]);
		gx[1][p[0][i]+1000] = min(gx[1][p[0][i]+1000], p[1][i]);
		
		gy[0][p[1][i]+1000] = max(gy[0][p[1][i]+1000], p[0][i]);
		gy[1][p[1][i]+1000] = min(gy[1][p[1][i]+1000], p[0][i]);
	}

	for (int i = 0; i < n; i++) {		
		if (gx[0][p[0][i]+1000] != p[1][i]
	     && gx[1][p[0][i]+1000] != p[1][i]
	     && gy[0][p[1][i]+1000] != p[0][i]
		 && gy[1][p[1][i]+1000] != p[0][i]) {
			r++;
			cout << p[0][i] << " " << p[1][i] << endl;
		}
	}
	cout << r << endl;
	return 0;
}
