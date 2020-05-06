// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

string get_val(string s, size_t i, char stop) {
    string res = "";
    while (i < s.length() && s[i] != stop) {
        res += s[i];
        i++;
    }
    return res;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string,ld> bank;
    bank["000"] = INFINITY;
    vector<tuple<ll, string, string, ld> > transactions;
    
    int n; cin >> n;
    string garbage;
    for (int i = 0; i < n; i++) {
        cin >> garbage >> garbage >> garbage >> garbage >> garbage >> garbage;
        int t; cin >> t;
        getline(cin, garbage);
        for (int j = 0; j < t; j++) {
            string in;
            getline(cin, in);
            size_t ti, oi, di, ai, bad = string::npos;
            ti = in.find("TransactionId: ");
            oi = in.find("Origin: ");
            di = in.find("Destination: ");
            ai = in.find("Amount: B");
            if (ti != bad && oi != bad && di != bad && ai != bad) {
                ll id;
                ld amount;
                string dest, src;
                ti += 15;
                oi += 8;
                ai += 9;
                di += 13;
                id = stoll(get_val(in, ti, ';'));
                src = get_val(in, oi, ';');
                dest = get_val(in, di, ';');
                amount = stold(get_val(in, ai, ';')); 
                transactions.push_back(make_tuple(id, src, dest, amount));
            }
        }
    }

    sort(transactions.begin(), transactions.end());

    int streak = 1;
    int i;
    for (i = 1; i < transactions.size(); i++) {
        if (get<0>(transactions[i-1]) == get<0>(transactions[i])) {
            streak++;
        } else {
            if (streak == n) {
                ld a = get<3>(transactions[i-1]);
                if (bank[get<1>(transactions[i-1])] - a >= 0) {
                    bank[get<1>(transactions[i-1])] -= a;
                    bank[get<2>(transactions[i-1])] += a;
                }
            }
            streak = 1;
        }
    }
    if (streak == n) {
        ld a = get<3>(transactions[i-1]);
        if (bank[get<1>(transactions[i-1])] - a >= 0) {
            bank[get<1>(transactions[i-1])] -= a;
            bank[get<2>(transactions[i-1])] += a;
        }
    }

    cin >> garbage >> garbage >> garbage >> garbage;
    cout << "B" << setprecision(2) << fixed << bank[garbage] << endl;

    return 0;
}
