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

int calMinSteps(int n, vector<int> &dp) {
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(n < 0) return 1e9;

    if(dp[n] != -1) {
        return dp[n];
    }

    string num = to_string(n);
    int minSteps = 1e9;

    f(i, 0, num.size()) {
        if(num[i] == '0') continue;

        int dig = (num[i] - '0');
        int steps = 1 + calMinSteps(n - dig, dp);

        if(steps != 1e9) minSteps = min(minSteps, steps);
    }

    return dp[n] = minSteps;
}

int calMinSteps(int n) {
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    fe(num, 1, 9) dp[num] = 1;

    fe(i, 10, n) {
        string num = to_string(i);
        int minSteps = 1e9;

        f(j, 0, num.size()) {
            if(num[j] == '0') continue;

            int dig = num[j] - '0';
            int steps = 1 + dp[i - dig];

            minSteps = min(minSteps, steps);
        }

        dp[i] = minSteps;
    }

    return dp[n];
}

void coderAnsh(int n) {
    if(n<=9){
        cout << 1;
        return;
    }

    if(n == 10){
        cout << 2;
        return;
    }

    // vi dp(n+1, -1);
    int minSteps = calMinSteps(n);

    if(minSteps != 1e9) cout << minSteps;

    return;
}

int main() {
    int n;
    cin >> n;

    coderAnsh(n);
    return 0;
}