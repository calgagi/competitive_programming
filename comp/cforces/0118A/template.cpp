// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	string s;
	cin >> s;
	char x[6] = { 'A', 'O', 'Y', 'E', 'U', 'I' };
	for (int i = 0; i < s.length(); i++) {
		bool c = true;
		for (auto j : x) { 
			if (toupper(s[i]) == j) {
				s.erase(s.begin()+i);
				i--;
				c = false;
				break;		
			}
		}
		s[i] = tolower(s[i]);
		if (c) { 
			s.insert(s.begin()+i, '.');
			i++;
		}

	}
	cout << s << endl;

	return 0;
}
