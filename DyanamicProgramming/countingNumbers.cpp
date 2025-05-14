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

ll dp[20][10][2][2];

ll calNum(string s, int index, int prevDig, bool leadingZeroes, bool tight) {
    if(index == s.size()) {
        return 1ll;
    }

    if(prevDig!=-1 && dp[index][prevDig][leadingZeroes][tight] != -1) {
        return dp[index][prevDig][leadingZeroes][tight];
    }

    int lb = 0;
    int ub = (tight ? s[index] - '0' : 9);

    ll cntNum = 0ll;
    fe(dig, lb, ub) {
        if(prevDig == dig && dig != 0) continue;
        if(prevDig == dig && dig == 0 && leadingZeroes == 0) continue;

        cntNum = (cntNum + calNum(s, index+1, dig, leadingZeroes && dig == 0, tight && dig == ub));
    }

    return dp[index][prevDig][leadingZeroes][tight] = cntNum;
}

void coderAnsh(string a, string b) {
    int sz1 = a.size(), sz2 = b.size();

    memset(dp, -1, sizeof(dp));
    ll numInt = calNum(b, 0, -1, 1, 1);

    memset(dp, -1, sizeof(dp));
    numInt -= calNum(a, 0, -1, 1, 1);

    cout << numInt;
    return;
}

int main() {
    ll n, m;
    cin >> n >> m;

    string a = to_string(n-1);
    string b = to_string(m);

    coderAnsh(a, b);
    return 0;
}