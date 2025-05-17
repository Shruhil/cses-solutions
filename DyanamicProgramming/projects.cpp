#include <bits/stdc++.h>
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
    vi startDate(n), endDate(n), profit(n);
    map<int,int> compress;

    f(i, 0, n) {
        cin >> startDate[i] >> endDate[i] >> profit[i];
        endDate[i]++;
        compress[startDate[i]];
        compress[endDate[i]];
    }

    int coords = 0;
    for(auto &it : compress){ 
        it.second = coords++;
    }

    vector<vector<pair<int,ll>>> projects(coords);

    f(i, 0, n) {
        projects[compress[endDate[i]]].pb({compress[startDate[i]], static_cast<ll>(profit[i])});
    }

    vector<ll> dp(coords, 0);

    f(i, 0, coords) {
        if(i > 0) dp[i] = dp[i-1];

        for(auto &p : projects[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }

    cout << dp[coords-1];
    return;
}

int main() {
    int n;
    cin >> n;

    coderAnsh(n);
    return 0;
}
