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

ll dp[1000005][2];

void preprocess() {
    dp[1][0] = dp[1][1] = 1;

    f(level, 2, 1000006) {
        dp[level][0] = (1LL * dp[level-1][1] + 4 * 1LL* dp[level-1][0]) % mod;
        dp[level][1] =  (2 * 1LL* dp[level-1][1] + 1LL * dp[level-1][0]) % mod;
    }
}

void coderAnsh() {
    int n;
    cin >> n;

    ll numTowers = (dp[n][0]);
    numTowers+=(dp[n][1]);
    numTowers %= mod;

    cout << numTowers;
    return;
}

int main() {
    preprocess();

    int t;
    cin >> t;

    while(t--){
        coderAnsh();
        cout << endl;
    }

    return 0;
}