#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

int calculateMinCoins(int n, int x, vi &coins, vi &dp) {
    if(x == 0) return 0;
    if(x < 0) return 1e9;

    if(dp[x] != -1) {
        return dp[x];
    }

    int minCoins = 1e9;
    f(i, 0, n) {
        int currCoins = 1 + calculateMinCoins(n, x-coins[i], coins, dp);

        if(currCoins!=1e9) {
            minCoins = min(minCoins, currCoins);
        }
    }

    return dp[x] = minCoins;
}

void coderAnsh() {
    int n, x;
    cin >> n >> x;
    vi coins(n);

    f(i, 0, n) {
        cin >> coins[i];
    } 

    if(x == 0){
        cout << 0;
        return;
    }
    
    if(n == 1) {
        cout << (x >= coins[0] && x%coins[0]==0 ? x/n : -1);
        return;
    }

    vi dp(x+1, -1);
    int minCoins = calculateMinCoins(n, x, coins, dp);

    if(minCoins == 1e9) {
        cout << -1;
        return;
    }

    cout << minCoins;
    return;
}

int main() {
    coderAnsh();
    return 0;
}