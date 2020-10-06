//Unbounded knapsack | Numbers if subsets with given sum 
// Note for no of choices and total ways add all choices.
#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int subsetSum(int coins[], int n, int sum) {
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
            if(coins[i-1] <= j) {
                t[i][j] = t[i][j - coins[i-1]] + t[i-1][j]; 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main() {
    int sum = 3;
    int n = 3;
    int coins[] = {1, 1, 2};
    cout << subsetSum(coins, n, sum) << endl;
}