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

void coderAnsh(int n, vi &arr) {
    vector<vector<ll>> dp(n, vector<ll>(n, 0ll));
    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    rf(l, n-1, 0) {
        f(r, l, n) {
            if(l == r) {
                dp[l][r] = static_cast<ll>(arr[l]);
                continue;
            }

            dp[l][r] = max(static_cast<ll>(arr[l]) - dp[l+1][r], static_cast<ll>(arr[r]) - dp[l][r-1]);
        }
    }

    ll maxScore1 = (dp[0][n-1] + sum) / 2;
    cout << maxScore1;
    return;
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    f(i, 0, n) {
        cin >> arr[i];
    }

    coderAnsh(n, arr);
    return 0;
}