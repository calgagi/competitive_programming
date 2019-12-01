// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	string n; cin >> n;
	int ni = atoi(n.c_str());
	if (ni % 2 == 1) {
		int r = n[n.length()-1]-'0';	   
		int c = n.length()-1;
		int m = -1;
		while (c > 0) {
			int x = (ni / (int) pow(10,c)) % 10;
			if (x % 2 == 0) {
				if (m == -1) m = c;
				if (r < x) { 
					cout << r << " " << x << endl;
					m = c; break; }
			}
			c--;
		}
		if (m == -1) {
			cout << -1 << endl; return 0;
		}
		cout << n[m] << endl;
		n[n.length()-1] = n[m];
		n[m] = (char) (r + '0');
		cout << n << endl;
	}	

	return 0;
}
