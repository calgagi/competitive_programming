// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define x first
#define y second
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll wax, way, wbx, wby;
    cin >> wax >> way >> wbx >> wby;
    ll bax[2], bay[2], bbx[2], bby[2];
    for (int i = 0; i < 2; i++)
        cin >> bax[i] >> bay[i] >> bbx[i] >> bby[i];
    ll warea = (wbx - wax) * (wby - way);
  
    // Find black white overlap
    ll wb[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        if (bbx[i] < wax || bax[i] > wbx)
            continue;
        if (bby[i] < way || bay[i] > wby)
            continue;
        wb[i] = (max(bax[i], wax)-min(bbx[i], wbx)) * (max(bay[i], way)-min(bby[i], wby));
    }
    // Find black black overlap
    ll bb = 0;
    if ((bbx[0] < bax[1] || bax[0] > bbx[1]) || 
        (bby[0] < bay[1] || bay[0] > bby[1]))
        bb = 0;
    else {
        bb = (max(bax[0], bax[1])-min(bbx[0], bbx[1])) * (max(bay[0], bay[1])-min(bby[0], bby[1]));
    }
    if (wb[0] + wb[1] - bb != warea)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
