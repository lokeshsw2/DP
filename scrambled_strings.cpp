#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b) {
	///base condition

	if(a.compare(b) == 0) {
		return true;
	}

	if(a.length() <= 1) {
		return false;
	}

	//loop
	bool case1, case2; // swapped and unswapped
	int n = a.length();
	bool flag = false;
	for(int i = 1; i <= n-1; i++) {
		case1 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i));
		case2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i));
		if(case1 || case2) {
			flag = true;
			break;
		}
	}

	return flag;
}

int main() {
	string a = "great";
	string b = "gratb";

	if(solve(a, b)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}