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

void coderAnsh(int n) {
    vi dp;

    f(i, 0, n) {
        int x;
        cin >> x;

        auto lb = lower_bound(dp.begin(), dp.end(), x);

        if(lb == dp.end()) {
            dp.pb(x);
        }

        else *lb = x;
    }

    cout << dp.size();
    return;
}

int main() {
    int n;
    cin >> n;

    coderAnsh(n);
    return 0;
}