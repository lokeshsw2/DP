#include<bits/stdc++.h>
using namespace std;
//check if x is subsequence of y or nor
//can be solved using 2 pointer approach also	
// can be solves using lcs also
bool spm(string x, string y, int m, int n) {
	//base condn
	if(m == 0) {
		return true;
	}
	//
	if(n == 0) {
		return false;
	}

	//choice diagram logic
	if(x[m-1] == y[n-1]) {
		return spm(x, y, m-1, n-1);
	} else {
		return spm(x, y, m, n-1);
	}
}

int main() {
	string x, y;
	x = "axy";
	y = "adxcpy";
	int m = x.length();
	int n = y.length();
	if(spm(x, y, m, n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}