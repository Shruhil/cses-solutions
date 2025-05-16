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

void coderAnsh(int n, vi &coins) {
    int maxSum = accumulate(coins.begin(), coins.end(), 0);
    vvi dp(n+1, vi(maxSum + 1, 0));
    dp[0][0] = 1;

    f(numCoins, 1, n+1) {
        fe(sum, 0, maxSum) {
            dp[numCoins][sum] = dp[numCoins-1][sum];

            int leftSum = sum - coins[numCoins-1];
            if(leftSum >= 0 && dp[numCoins-1][leftSum]) {
                dp[numCoins][sum] = true;
            }
        }
    }

    vi possible;
    f(sum, 1, maxSum+1) {
        if(dp[n][sum]) {
            possible.pb(sum);
        }
    }

    cout << possible.size() << endl;
    f(i, 0, possible.size()) {
        cout << possible[i] << " ";
    }

    return;
}

int main() {
    int n;
    cin >> n;
    
    vi coins(n);
    f(i, 0, n) cin >> coins[i];

    coderAnsh(n, coins);
}