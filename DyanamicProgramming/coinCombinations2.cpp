#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

int calculateDistinctWays(int curr, int n, int x, vi &coins, vvi &dp) {
    if(x == 0) return 1;
    if(x < 0) return 0;
    if(curr >= n) return x == 0;

    if(dp[curr][x] != -1) {
        return dp[curr][x];
    }

    int use = 0, notUse = 0;
    notUse = calculateDistinctWays(curr+1, n, x, coins, dp);
    if(x >= coins[curr]) use = calculateDistinctWays(curr, n, x-coins[curr], coins, dp);

    return dp[curr][x] = (use + notUse)%mod;
}

int calculateDistinctWays(int n, int x, vector<int> &coins){
    vvi dp(n+1, vi(x+1, 0));

    f(i, 0, n){
        dp[i][0] = 1;
    }

    rf(curr, n-1, 0) {
        fe(sum, 1, x) {
            int use = 0, notUse = 0;

            notUse = dp[curr+1][sum];
            if(sum >= coins[curr]) use = dp[curr][sum-coins[curr]];

            dp[curr][sum] = (use + notUse)%mod;
        }
    }

    return dp[0][x];
}

void coderAnsh(int n, int x, vi &coins) {
    // vvi dp(n+1, vi(x+1, -1));
    cout << calculateDistinctWays(n, x, coins);
    return;
}

int main() {
    int n, x;
    cin >> n >> x;

    vi coins(n);
    f(i, 0, n) {
        cin >> coins[i];
    }

    coderAnsh(n, x, coins);
    return 0;
}