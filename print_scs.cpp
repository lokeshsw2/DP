#include<bits/stdc++.h>
using namespace std;

int t[100][100];

string scs(string x, string y, int m, int n) {
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
    //shortest common supersequence length
    int len = m + n - t[m][n];
    cout << "Length: " << len << endl;
    string super_sequence = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            super_sequence.push_back(x[i-1]);
            i--;
            j--;
        } else {
            if(t[i-1][j] > t[i][j-1]) {
                super_sequence.push_back(x[i-1]);
                i--;
            } else {
                super_sequence.push_back(y[j-1]);
                j--;
            }
        }
    }
    while(i > 0) {
        super_sequence.push_back(x[i-1]);
        i--;
    }
    while(j > 0) {
        super_sequence.push_back(y[j-1]);
        j--;
    }
    reverse(super_sequence.begin(), super_sequence.end());
    return super_sequence;
}

int main() {
	// string x, y;
	// cin >> x;
	// cin >> y;
	memset(t, -1, sizeof(t));
	string x = "aggtab";
	string y = "gxtxayb";
	cout << scs(x, y, x.length(), y.length());
}