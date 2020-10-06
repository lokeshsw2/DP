#include<bits/stdc++.h>
using namespace std;

int t[100][100];

string lcs(string x, string y, int m, int n) {
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
    string sub_seq = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            sub_seq.push_back(x[i-1]);
            i--;
            j--;
        } else {
            if(t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(sub_seq.begin(), sub_seq.end());
    
    return sub_seq;

}

int main() {
    // string x, y;
    // cin >> x;
    // cin >> y;
    string x = "abxdcs";
    string y = "abc";
    cout << lcs(x, y, x.length(), y.length());
}