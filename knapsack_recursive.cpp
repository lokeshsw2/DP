#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n) {
    //base condn
    if(wt == 0 || n == 0) {
        return 0;
    }
    
    //logic
    if(wt[n-1] <= w) {
        int ans = max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
        return ans;
    } else if(wt[n-1] > w) {
        return knapsack(wt, val, w, n-1);
    }
    
    return -1;
}

int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    cout << knapsack(wt, val, w, 4);
}