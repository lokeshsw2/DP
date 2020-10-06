//knapsack variation | subset sum variation
#include<bits/stdc++.h>
using namespace std;

int t[100][100];

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
    int sum = 11;
    int n = 5;
    int arr[] = {4, 4, 3, 8, 10};
    cout << subsetSum(arr, n, sum) << endl;
}