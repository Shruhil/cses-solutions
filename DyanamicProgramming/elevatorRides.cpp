#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pii pair<int,int>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

#define pb push_back

int calMinRides(int n, vi &weights, int W) {
    vector<ll> wt(1 << n, 0ll);

    f(X, 0, 1 << n) {
        f(i, 0, n) {
            if(X & (1 << i)) {
                wt[X] += static_cast<ll>(weights[i]);
            }
        }
    }
    
    vector<ll> dp(1 << n, 1e9);
    dp[0] = 0ll;

    f(X, 1, 1 << n) {
        for(int x = X; x > 0; x = (x-1) & X) {
            if(wt[x] <= W) {
                dp[X] = min(dp[X], 1 + dp[X-x]);
            }
        }
    }

    return dp[(1 << n) - 1];
}

void coderAnsh(int n, vi &weights, int x) {
    // naive approach - O(3^n)
    // cout << calMinRides(n, weights, x);

    // optimised approach - O(n*2^n)
    vector<pii> dp(1 << n);
    dp[0] = {1, 0};

    f(X, 1, 1 << n) {
        dp[X] = {21, 0};

        f(i, 0, n) {
            if(X & (1 << i)) {
                int rides = dp[X ^ (1 << i)].first;
                int wt = dp[X ^ (1 << i)].second;

                if(wt + weights[i] > x) {
                    rides+=1;
                    wt = min(wt, weights[i]);
                }

                else wt+=weights[i];

                dp[X] = min(dp[X], {rides, wt});
            }
        }
    }

    cout << dp[(1 << n) - 1].first;
    return;
}


int main() {
    int n, x;
    cin >> n >> x;

    vi weights(n);
    f(i, 0, n) {
        cin >> weights[i];
    }

    coderAnsh(n, weights, x);
    return 0;
}
