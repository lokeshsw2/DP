//knapsack variation | subset sum 
#include<bits/stdc++.h>
using namespace std;

bool t[100][100];

bool subsetSum(int arr[], int n, int sum) {
    // base condn
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum + 1; j++) {
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
        for(int j = 1; j < sum+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j]; 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

bool equalSumPartiton(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if(sum % 2 == 1) {
        return false;
    } else {
        return subsetSum(arr, n, sum / 2);
    }
}

int main() {
    int n = 3;
    int arr[] = {5, 5, 10};
    cout << equalSumPartiton(arr, n);
}