#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

#define pb push_back

void generateNextMasks(int row, int next_mask, int currMask, int n, vi &nextMasks) {
    if(row == n+1) {
        nextMasks.pb(next_mask);
        return;
    }

    if(currMask & (1 << row)) {
        generateNextMasks(row+1, next_mask, currMask, n, nextMasks);
    }

    if(row != n) {
        if(((currMask & (1 << row)) == 0) && ((currMask & (1 << (row + 1))) == 0)) {
            generateNextMasks(row+2, next_mask, currMask, n, nextMasks);
        }
    }

    if((currMask & (1 << row)) == 0) {
        generateNextMasks(row+1, next_mask + (1 << row), currMask, n, nextMasks);
    }
}

int calWaysToConGrid(int col, int mask, int n, int m, vector<vector<int>> &dp) {
    if(col == m+1) {
        return mask == 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];

    vector<int> nextMasks;
    generateNextMasks(1, 0, mask, n, nextMasks);

    int numWays = 0;
    for(auto &nm : nextMasks) {
        numWays += calWaysToConGrid(col+1, nm, n, m, dp);
        numWays %= mod;
    }

    nextMasks.clear();
    return dp[col][mask] = numWays;
}

void coderAnsh(int n, int m) {
    vector<vector<int>> dp(m+2, vector<int>((1 << n+2), -1));
    cout << calWaysToConGrid(1, 0, n, m, dp);    
}

int main() {
    int n, m;
    cin >> n >> m;

    coderAnsh(n, m);
    return 0;
}