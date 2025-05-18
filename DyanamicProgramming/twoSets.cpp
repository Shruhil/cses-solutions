#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

#define pb push_back;

int calWaysToTarget(int target, int curr, vvi &dp, int n) {
    // base cases
    if(target == 0) return 1;
    if(curr > n) {
        return target == 0;
    }

    // check if alraedy solve subproblem
    if(dp[curr][target] != -1) return (dp[curr][target]) % mod;

    // either take the current or not take the current
    int take = 0, notTake = 0;
    notTake = (calWaysToTarget(target, curr+1, dp, n)) % mod;
    if(target >= curr) {
        take = (calWaysToTarget(target-curr, curr+1, dp, n)) % mod;
    }

    // returb the answer for the cuirrent subproblem
    return dp[curr][target] = (take + notTake);
}

void coderAnsh(int n) {
    int sum = (n*(n+1)) / 2;

    if(sum & 1) {
        cout << 0;
        return;
    }

    int target = (sum) / 2;

    vvi dp(n+2, vi(target+1, -1));
    cout << (calWaysToTarget(target, 1, dp, n) / 2) % mod;
    return;
}

int main() {
    int n;
    cin >> n;

    coderAnsh(n);
    return 0;
}