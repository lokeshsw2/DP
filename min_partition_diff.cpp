//subset_sum | equal_sum_partition
#include<bits/stdc++.h>
using namespace std;

bool t[100][100];

int subsetSum(int arr[], int n, int range) {
    // base condn
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < range + 1; j++) {
            if(i == 0) {
                t[i][j] = false;
            }
            
            if(j == 0) {
                t[i][j] = true;
            }
        }
    }
    
    //logic
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < range+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j]; 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    vector<int> v;
    for(int j = 1; j <= range / 2; j++) {
        if(t[n][j]) {
            v.push_back(j);
        }
    } 
    
    int ans = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        ans = min(ans, range - 2 * v[i]);
    }
    
    return ans;
}

int main() {
    int n = 4;
    int arr[] = {1, 2, 3, 7};
    int range = 0;
    for(int i = 0; i < n; i++) {
        range += arr[i];
    }
    cout << subsetSum(arr, n, range);
}