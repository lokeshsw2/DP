//standard dp
#include<bits/stdc++.h>
using namespace std;


int t[5][8]; 
int knapsack(int wt[], int val[], int w, int n) {
    //base condition in recursion = Initialization in top down
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < w+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }
    
    //logic
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < w+1; j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][w-wt[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    //ans
    return t[n][w];
}

int main() {
    int n = 4;
    int wt[] = {1, 1, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    cout << knapsack(wt, val, w, 4) << endl;
}