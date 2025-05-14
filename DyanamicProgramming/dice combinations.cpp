#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)


ll calculateWays(int sum, vector<ll> &dp) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;

    if (dp[sum] != -1) return dp[sum];

    ll numWays = 0;
    for (int i = 1; i <= 6; i++) {
        numWays = (numWays + calculateWays(sum - i, dp)) % mod;
    }

    return dp[sum] = numWays;
}

void coderAnsh(int n) {
    vector<ll> dp(n + 1, -1);
    cout << calculateWays(n, dp);
    return;
}

int main() {
    int n;
    cin >> n;
    coderAnsh(n);
    return 0;
}
