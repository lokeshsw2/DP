//knapsack | subset sum | count subset with given sum
//It is same as target sum
#include<bits/stdc++.h>
using namespace std;

int t[21][1001];

int subsetSum(int arr[], int n, int sum) {
    // base condn
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum + 1; j++) {
            if(i == 0) {
                t[i][j] = 0;
            }
            
            if(j == 0) {
                t[i][j] = 1;
            }
        }
    }
    
    //logic
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j]; 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main() {
    int diff = 1;
    int n = 4;
    int arr[] = {1, 1, 2, 3};
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if((diff + sum) % 2 == 1) {
        cout << "0";
        return 0;
    }
    int s1 = (diff + sum) / 2;
    cout << subsetSum(arr, n, s1) << endl;
}