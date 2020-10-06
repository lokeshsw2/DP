//IMP
//MCM varification
#include<bits/stdc++.h>
using namespace std;


int solve(string s, int i, int j, bool isTrue) {
	// base condition
	if(i > j) {
		return 0;
	}
	if(i == j) {
		if(isTrue) {
			return s[i] == 'T';
		} else {
			return s[i] == 'F';
		}
	}

	//loop
	int ans = 0;
	int lt = 0, rt = 0, lf = 0, rf = 0;
	for(int k = i+1; k <= j-1; k+=2) {
		lt = solve(s, i, k-1, true);
		lf = solve(s, i, k-1, false);
		rt = solve(s, k+1, j, true);
		rf = solve(s, k+1, j, false);

		if(s[k] == '&') {
			if(isTrue) {
				ans += lt * rt;
			} else {
				ans = ans + lf * rt + lt * rf + lf * rf;
			}
		} else if(s[k] == '^') {
			if(isTrue) {
				ans = ans + lt * rf + lf * rt;
			} else {
				ans = ans + lf * rf + lt * rt;
			}
		} else if(s[k] == '|') {
			if(isTrue) {
				ans = ans + lt * rf + lf * rt + lt * rt;
			} else {
				ans = ans + lf * rf;
			}
		}
	}

	return ans;

}

int main() {
	string s = "T|F&T^F";
	cout << solve(s, 0, s.length() - 1, true);
}