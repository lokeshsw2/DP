#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int lps_min_deletions(string x, string y, int m, int n) {
     //top down
    // recursive base case = top down inititlization
    for(int i = 0; i < m+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }
        
    //choice diagram logic
    
    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(x[i-1] == y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    
    return m - t[m][n];

}

int main() {
    // string x, y;
    // cin >> x;
    // cin >> y;
    memset(t, -1, sizeof(t));
    string x = "aebcbda";
    string y = x;
    reverse(y.begin(), y.end());
    cout << lps_min_deletions(x, y, x.length(), y.length());
}