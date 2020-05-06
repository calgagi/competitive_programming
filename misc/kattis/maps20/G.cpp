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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    string inst;
    cin >> inst;
    int n = inst.length();
    
    stack<int> s;
    int i = 0;
    string cur = "";
    while (i < n) {
        cur += inst[i];
        if (cur == "SS") {
            // push int
            cur = "";
            i++;
            int a = 0, m = inst[i]=='S'?1:-1;
            i++;
            int b = 1;
            while (i < n && inst[i] != 'N') {
                cur += inst[i];
                i++;
            }
            for (int j = cur.length()-1; j >= 0; j--) {
                a += (cur[j]=='T'?1:0)*b;
                b *= 2;
            }
            cur = "";
            s.push(a*m);
        } else if (cur == "SNS") {
            // copy
            cur = "";
            if (s.size()) {
                int a = s.top();
                s.push(a);
            } else {
                printf("Invalid copy operation\n");
            }
        } else if (cur == "SNT") {
            // swap
            cur = "";
            if (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a);
                s.push(b);
            } else {
                printf("Invalid swap operation\n");
            }
        } else if (cur == "SNN") {
            // remove
            cur = ""; 
            if (!s.size()) {
                printf("Invalid remove operation\n");
            } else {
                s.pop();
            }
        } else if (cur == "TSSS") {
            // add 
            cur = "";
            if (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            } else {
                printf("Invalid addition operation\n");
            }
        } else if (cur == "TSST") {
            // subtract
            cur = "";
            if (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            } else {
                printf("Invalid subtraction operation\n");
            }
        } else if (cur == "TSSN") {
            // product
            cur = "";
            if (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            } else {
                printf("Invalid multiplication operation\n");
            }
        } else if (cur == "TSTS") {
            // divide
            cur = "";
            if (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (a == 0) {
                    printf("Division by zero\n");
                    s.push(b);
                    s.push(a);
                } else {
                    s.push(b/a);
                }
            } else {
                printf("Invalid division operation\n");
            }
        } else if (cur == "TNST") {
            // print
            cur = "";
            if (s.size()) {
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid print operation\n");
            }
        }        
        i++;
    } 

    return 0;
}
