    //standard dp
#include<bits/stdc++.h>
using namespace std;


int t[100][100];  //t[n+1][w+1] 
int knapsack(int wt[], int val[], int w, int n) {
    //base condn
    if(wt == 0 || n == 0) {
        return 0;
    }
    
    if(t[n][w] != -1) {
        // for repeat calls
        cout << n << " " << w << endl;
        return t[n][w];
    }
    
    //logic
    if(wt[n-1] <= w) {
        int ans = max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
        return t[n][w] = ans;
    } else if(wt[n-1] > w) {
        return t[n][w] = knapsack(wt, val, w, n-1);
    }
    
    return -1;
}

int main() {
    int n = 4;
    int wt[] = {1, 1, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    
    memset(t, -1, sizeof(t));
    cout << knapsack(wt, val, w, 4) << endl;
}