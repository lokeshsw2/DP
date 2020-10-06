#include<bits/stdc++.h>
using namespace std;
int t[100][10000];
int solve(vector<int> coins, int amount, int n) {
    //recursive TLE
    // if(n == 0) return INT_MAX-1;
    // if(amount == 0) return 0;
    // if(t[n][amount] != -1) {
    //     return t[n][amount];
    // }
    // if(coins[n-1] <= amount) {
    //     return t[n][amount] = min(1 + solve(coins, amount - coins[n-1], n), solve(coins, amount, n-1));
    // } else {
    //     return t[n][amount] = solve(coins, amount, n-1);
    // }
    //Iterative runs well
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < amount+1; j++) {
            if(j == 0) {
                t[i][j] = 0;
            }
            if(i == 0) {
                t[i][j] = INT_MAX - 1;
            }
        }
    }
    
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < amount+1; j++) {
            
            if(coins[i-1] <= j) {
                t[i][j] = min(1 + t[i][j - coins[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }   
        }
    }
    return t[n][amount];
}

int main() {
	vector<int> coins = {368,305,204,88,148,423,296,125,346};
	int amount = 7163;
	cout << solve(coins, amount, coins.size());
}

// coins: [368,305,204,88,148,423,296,125,346]
// amouont: 7163
// ans: 18

// coins: [1, 2, 5]
// amount: 11
// ans: 3

// coins: [2]
// amount: 3
// ans: -1