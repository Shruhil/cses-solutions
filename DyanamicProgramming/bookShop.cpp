#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

int calMaxPages(int curr, int n, int money, vi &price, vi &pages, vvi &dp) {
    if(money == 0) return 0;
    if(curr == n) return 0;
    if(money < 0) return -1e9;

    if(dp[curr][money] != -1) return dp[curr][money];

    int buy = 0, notBuy = 0;
    notBuy = calMaxPages(curr+1, n, money, price, pages, dp);

    if(money >= price[curr]) {
        buy = pages[curr] + calMaxPages(curr+1, n, money-price[curr], price, pages, dp);
    }

    return dp[curr][money] = max(buy, notBuy);
}

int calMaxPages(int n, int x, vi &price, vi &pages) {
    vvi dp(n+1, vi(x+1, 0));
    
    rf(i, n-1, 0) {
        fe(money, 1, x) {
            int buy = 0, notBuy = 0;
            notBuy = dp[i+1][money];
            
            if(money >= price[i]) buy = pages[i] + dp[i+1][money - price[i]];

            dp[i][money] = max(buy, notBuy);
        }
    }

    return dp[0][x];
}

void coderAnsh(int n, int x, vi &price, vi &pages) {
    if(x==0) {
        cout << 0;
        return;
    }

    if(n==1) {
        cout << (x>=price[0] ? pages[0] : 0);
        return;
    }

    // vvi dp(n+1, vi(x+1, -1));
    cout << calMaxPages(n, x, price, pages);
    return;
}

int main() {
    int n, x;
    cin >> n >> x;

    vi price(n), pages(n);

    f(i,0,n) {
        cin >> price[i];
    }

    f(i, 0, n) {
        cin >> pages[i];
    }

    coderAnsh(n, x, price, pages);
    return 0;
}