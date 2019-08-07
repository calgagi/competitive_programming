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

    ull r[10][10];
    vector<unordered_map<int, int> > c(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 5; j++) {
           c[i][(j*i) % 10] = j;
        }
    }

        
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            




            r[i][j] = a;
            r[j][i] = a;
        }
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << r[i][j] << " ";
        cout << endl;
    }
    return 0;
}
