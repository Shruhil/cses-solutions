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

int calMinSteps(int i, int j, int n, int m, string s1, string s2, vvi &dp) {
    if(i==n && j==m) return 0;
    if(i==n && j < m) return (m-j);
    if(i<n && j==m) return (n-i);

    if(dp[i][j] != -1) return dp[i][j];

    int minOp = 1e9;
    if(s1[i] == s2[j]) {
        minOp = calMinSteps(i+1, j+1, n, m, s1, s2, dp);
    }

    else {
        int add = 0, del = 0, rep = 0;

        add = 1 + calMinSteps(i, j+1, n, m, s1, s2, dp);
        del = 1 + calMinSteps(i+1, j, n, m, s1, s2, dp);
        rep = 1 + calMinSteps(i+1, j+1, n, m, s1, s2, dp);

        minOp = min(minOp, min(add, min(del, rep)));
    }

    return dp[i][j] = minOp;
}

int calMinSteps(string s1, string s2, int n, int m) {
    vvi dp(n+1, vi(m+1, 0));
    
    f(i, 0, n) dp[i][m] = n-i;
    f(j, 0, m) dp[n][j] = (m-j);

    rf(i, n-1, 0) {
        rf(j, m-1, 0) {
            int minOp = 1e9;
            if(s1[i] == s2[j]) {
                minOp = dp[i+1][j+1];
            }

            else {
                int add = 0, del = 0, rep = 0;

                add = 1 + dp[i][j+1];
                del = 1 + dp[i+1][j];
                rep = 1 + dp[i+1][j+1];

                minOp = min(minOp, min(add, min(del, rep)));
            }

            dp[i][j] = minOp;
        }
    }

    return dp[0][0];
}

void coderAnsh(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // vvi dp(n+1, vi(m+1, -1));
    cout << calMinSteps(s1, s2, n, m);
    return;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    coderAnsh(s1, s2);
    return 0;
}