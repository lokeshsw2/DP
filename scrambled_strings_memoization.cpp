//IMP mcm variation

#include<bits/stdc++.h>
using namespace std;

map<string, bool> m;

bool solve(string a, string b) {
	///base condition

	if(a.compare(b) == 0) {
		return true;
	}

	if(a.length() <= 1) {
		return false;
	}

	string key = a + " " + b;
	if(m.find(key) != m.end()) {
		return m[key];
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

	return m[key] = flag;
}

int main() {
	string a = "great";
	string b = "rgtae";
	m.clear();
	if(solve(a, b)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	// cout << endl;
	// for(auto p:m) {
	// 	cout << p.first << " - " << p.second << endl;
	// }
}