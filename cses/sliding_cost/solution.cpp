/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    vector<int> first;
    for (int i = 0; i < K; i++) {
        first.push_back(A[i]);
    }

    sort(first.begin(), first.end());

    multiset<int> before, after;
    ll sum_before = 0, sum_after = 0;

    for (int i = 0; i < K/2; i++) {
        before.insert(first[i]);
        sum_before += first[i];
    }

    for (int i = K/2; i < K; i++) {
        after.insert(first[i]);
        sum_after += first[i];
    }

    int median = ((K & 1) ? *after.begin() : *--before.end());
    cout << ((median*(K/2)) - sum_before) + (sum_after - (median*((K+1)/2))) << " ";

    for (int i = K; i < N; i++) {
        if (A[i] < median) {
            before.insert(A[i]);
            sum_before += A[i];
        } else {
            after.insert(A[i]);
            sum_after += A[i];
        }

        if (before.find(A[i-K]) != before.end()) {
            auto to_delete = before.find(A[i-K]);
            before.erase(to_delete);
            sum_before -= A[i-K];
        } else {
            auto to_delete = after.find(A[i-K]);
            after.erase(to_delete);
            sum_after -= A[i-K];
        }

        while (after.size() != before.size() + (K & 1)) {
            if (after.size() < before.size() + (K & 1)) {
                auto move = --before.end();
                int val = *move;
                after.insert(val);
                before.erase(move);
                sum_after += val;
                sum_before -= val;
            } else {
                auto move = after.begin();
                int val = *move;
                before.insert(val);
                after.erase(move);
                sum_before += val;
                sum_after -= val;
            }
        }

        median = ((K & 1) ? *after.begin() : *--before.end());
        cout << ((median*(K/2)) - sum_before) + (sum_after - (median*((K+1)/2))) << " ";
    } 
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
