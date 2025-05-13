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

int cntNumArrays(vi &arr, int n, int m) {
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    if(arr[0] != 0) {
        dp[0][arr[0]] = 1;
    }

    else {
        fe(i, 0, m) {
            dp[0][i] = 1;
        }
    }

    f(ind, 1, n) {
        if(arr[ind] != 0) {
            dp[ind][arr[ind]] += (dp[ind-1][arr[ind]]);
            if(arr[ind] - 1 > 0) dp[ind][arr[ind]] += dp[ind-1][arr[ind] - 1];
            if(arr[ind] + 1 <= m) dp[ind][arr[ind]] += dp[ind-1][arr[ind] + 1];

            dp[ind][arr[ind]] %= mod;
        }

        else 
            fe(val, 1, m) {
                dp[ind][val] += dp[ind-1][val];
                if(val - 1 > 0) dp[ind][val] += dp[ind-1][val-1]; 
                if(val + 1 <= m) dp[ind][val] += dp[ind-1][val+1];

                dp[ind][val] %= mod;
            }
    }

    ll numWays = 0;
    fe(val, 1, m) {
        numWays += (dp[n-1][val]);
        numWays %= mod;
    }

    return numWays;
}

void coderAnsh(vi &arr, int n, int m) {
    cout << cntNumArrays(arr, n, m);
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    f(i, 0, n) {
        cin >> arr[i];
    }

    coderAnsh(arr, n, m);
    return 0;
}
