//mcm format variation
#include<bits/stdc++.h>
using namespace std;

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
	int ans = INT_MAX;
	int temp;
	for(int k = i; k <= j-1; k++) {
		temp = solve(s, i, k) + solve(s, k+1, j) + 1;
		ans = min(ans, temp);
	}

	return ans;
}

int main() {
	string s = "nitik";
	int i = 0;
	int j = s.length() - 1;
	cout << solve(s, i, j);
}