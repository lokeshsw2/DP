#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int lcs(string x, string y, int m, int n) {
	// base case
	if(n == 0 || m == 0) {
		return 0;
	}
	if(t[m][n] != -1) {
		return t[m][n];
	}
	// choice diagram logic
	if(x[m-1] == y[n-1]) {
		return t[m][n] = 1 + lcs(x, y, m-1, n-1);
	} else {
		return t[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
	}
}

int main() {
	// string x, y;
	// cin >> x;
	// cin >> y;
	memset(t, -1, sizeof(t));
	string x = "abxdcs";
	string y = "abc";
	cout << lcs(x, y, x.length(), y.length());
}