#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>
#define vvc vector<vector<char>> 
#define vc vector<char>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

bool isValid(int r, int c, int n) {
    return (r>=0 && r<n && c>=0 && c<n);
}

int findNumPaths(int row, int col, vvc &grid, int n, vvi &dp) {
    if(row==n-1 && col==n-1) return 1;
    if(!isValid(row, col, n) || grid[row][col] == '*') return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int numPaths = 0;
    numPaths = (findNumPaths(row+1, col, grid, n, dp) + findNumPaths(row, col+1, grid, n, dp))%mod;

    return dp[row][col] = numPaths%mod;
}

void coderAnsh(vvc &grid, int n) {
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*') {
        cout << 0;
        return;
    }

    vvi dp(n+1, vi(n+1, -1));
    cout << findNumPaths(0, 0, grid, n, dp);
    return;
}

int main() {
    int n;
    cin >> n;

    vvc grid(n, vc(n));
    f(i, 0, n){
        f(j, 0, n) {
            cin >> grid[i][j];
        }
    }

    coderAnsh(grid, n);
    return 0;
}