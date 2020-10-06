#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[], int i, int j) {
	if(i >= j) {
		return 0;
	}
	int ans = INT_MAX;
	int temp;
	for(int k = i; k <= j-1; k++) {
		temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
		ans = min(ans, temp);
	}

	return ans;
}

int main() {
	int arr[] = {40, 20, 30, 10, 30};
	int i = 1;
	int j = 4;
	cout << mcm(arr, i, j);
}