//unbounded knapsacks
#include<bits/stdc++.h>
using namespace std;


int t[100][100]; 
int knapsack(int length[], int price[], int len, int n) {
    //base condition in recursion = Initialization in top down
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < len+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }
    
    //logic
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < len+1; j++) {
            if(length[i-1] <= j) {
                // i-1 --> i
                // can reprocess an item
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    //ans
    return t[n][len];
}

int main() {
    int n = 4;
    int length[] = {1, 2, 3, 4};
    int price[] = {5, 6, 8, 8};
    int len = 4;
    cout << knapsack(length, price, len, n) << endl;
}