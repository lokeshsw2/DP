#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int mcm(int arr[], int i, int j) {
	if(i >= j) {
		return 0;
	}
	if(t[i][j] != -1) {
		return t[i][j];
	}
	int ans = INT_MAX;
	int temp;
	for(int k = i; k <= j-1; k++) {
		temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
		ans = min(ans, temp);
	}

	return t[i][j] = ans;
}

int main() {
	int arr[] = {40, 20, 30, 10, 30};
	int i = 1;
	int j = 4;
	memset(t, -1, sizeof(t));
	cout << mcm(arr, i, j);
}