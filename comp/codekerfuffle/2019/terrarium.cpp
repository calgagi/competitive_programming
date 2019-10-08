// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

ll get_val() {
    string garbage;
    cin >> garbage >> garbage;
    garbage.pop_back();
    return stoll(garbage);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string garbage;

    ll o2 = get_val(); 
    cin >> garbage;
    ll co2 = get_val(), bamboo = get_val(), bluegrass = get_val(), snipes = get_val(), beetles = get_val(), wait;
    cin >> garbage >> wait;

    int slow = 1;
    for (int i = 1; i <= wait; i++) {
        beetles -= min(beetles, 10 * snipes);
        if (i % 3 == 0) bamboo -= min(bamboo, snipes);
        ll t = min(o2, 20 * snipes);
        o2 -= t;
        co2 += t;
        bamboo -= min(bamboo, beetles / 300);
        if (bamboo < 10 * bluegrass) {
            slow = 1;
            bamboo *= 2;
        } else if (slow % 2 == 0) {
            slow++;
            bamboo *= 2;
        } else {
            slow++;
        }
        t = min(co2, bamboo * 15);
        co2 -= t;
        o2 += t;
    }
    cout << "O2: " << o2 << "; CO2: " << co2 << ";" << endl;


    return 0;
}
