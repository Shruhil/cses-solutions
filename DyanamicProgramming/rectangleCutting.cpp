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

int calMinCuts(int len, int wid) {
    vvi dp(len+1, vi(wid+1));

    f(l, 1, len+1) {
        f(w, 1, wid+1) {
            if(l == w) {
                dp[l][w] = 0;
            }

            else {
                dp[l][w] = 1e9;

                f(k, 1, l) {
                    dp[l][w] = min(dp[l][w], 1 + dp[l-k][w] + dp[k][w]);
                }

                f(k, 1, w) {
                    dp[l][w] = min(dp[l][w], 1 + dp[l][k] + dp[l][w-k]);
                }
            }
        }
    }

    return dp[len][wid];
}

void coderAnsh(int a, int b) {
    if(a == b) {
        cout << 0;
        return;
    }    

    cout << calMinCuts(a, b);
    return;
}

int main() {
    int a, b;
    cin >> a >> b;

    coderAnsh(a, b);
    return 0;
}