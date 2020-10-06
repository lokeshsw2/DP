//mcm format variation
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isPalindrome(string s, int i, int j) {
	if(i >= j) {
		return true;
	}

	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

int solve(string s, int i, int j) {

	if(isPalindrome(s, i, j)) {
		return 0;
	}
	if(t[i][j] != -1) {
		return t[i][j];
	}
	int ans = INT_MAX;
	int temp;
	int left, right;
	for(int k = i; k <= j-1; k++) {
		if(t[i][k] != -1) {
			left = t[i][k];
		} else {
			left = solve(s, i, k);
		}

		if(t[k+1][j] != -1) {
			right = t[k+1][j];
		} else {
			right = solve(s, k+1, j);
		}
		temp = left + right + 1;
		ans = min(ans, temp);
	}

	return t[i][j] = ans;
}

int main() {
	string s = "nitik";
	int i = 0;
	int j = s.length() - 1;
	memset(t, -1, sizeof(t));
	cout << solve(s, i, j);
}