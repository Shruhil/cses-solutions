#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

int calNumWays(int n, int x, vi &coins, vi &dp) {
    if(x == 0) return 1;
    if(x < 0) return 0;

    if(dp[x] != -1) {
        return dp[x];
    }

    int numWays = 0;
    f(i, 0, n) {
        int currWays = calNumWays(n, x - coins[i], coins, dp);
        numWays = (numWays + currWays)%mod;
    }

    return dp[x] = numWays%mod;
}

void coderAnsh(int n, int x, vi &coins) {
    vi dp(x+1, -1);
    cout << calNumWays(n, x, coins, dp);
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