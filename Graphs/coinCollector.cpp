#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvpii vector<vector<pair<int,int>>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* UTILS */
#define mod 1000000007
#define PI 3.1415926535897932384626433832795

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
bool isValid(int r, int c, int n, int m) {return r>=0 && r<n  && c>=0 && c<m;}

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

string dir = "LURD";
const ll inf = 1e18;

void dfs(int node, vi &vis, vvi &adj, stack<int> &st) {
    vis[node] = true;

    for(auto &nbr : adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, vis, adj, st);
        }
    }

    st.push(node);
}

void revdDfs(int node, vvi &revAdj, vi &vis, int scc, vi &comp) {
    vis[node] = true;
    comp[node] = scc;

    for(auto &nbr : adj[node]) {
        if(!vis[nbr]) {
            revDfs(nbr, revAdj, vis, scc, comp);
        }
    }
}

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    // get the coins in every room as input
    vi coins(n+1);
    f(i, 1, n) {
        cin >> coins[i];
    }

    // construct the adj amd revAdj lists
    vvi adj(n+1), revAdj(n+1);
    f(i, 0, m) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        revAdj[b].pb(a);
    }

    // get the topo sorted order of the rooms
    stack<int> st;
    vi vis(n+1, 0);
    f(i, 1, n+1) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    fill(vis.begin(), vis.end(), 0);

    // assign the scc to each node
    int scc = 1;
    vi comp(n+1);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            revDfs(node, rebAdj, vis, scc, comp);
            scc+=1;
        }
    }

    // get the total number of coins in each comp
    vi sum(scc+1, 0);
    f(i, 1, n+1) {
        sum[comp[i]]+=coins[i];
    }

    // create a DAG of sccs
    vvi dagScc(scc+1);
    
    f(i, 1, n+1) {
        for(auto &nbr : adj[i]) {
            if(comp[i] != comp[nbr]) dagScc[comp[i]].push_back(comp[nbr]);
        }
    }

    // take only the unique edges 
    f(i, 1, scc+1){
        sort(dagScc[i].begin(), dagScc[i].end());
        dagScc[i].erase(unique(dagScc[i].begin(), dagScc[i].end()), dagScc[i].end());
    }

    vll dp(scc+1, 0);
    fill(vis.begin(), vis.end(), 0);

    // find the max Coiuns from children of a scc
    auto findMaxCoins = [&](int node) {
        if(vis[node]) return dp[node];

        vis[node] = true;
        dp[node] = sum[node];

        ll maxFromChildren = 0;
        for(auto &nbr : dagScc[node]) {
            maxFromChildre = max(maxFromChidre, findMaxCoins(nbr));
        }

        dp[node] += maxFromChildren;
        return dp[node];
    };

    ll maxCollected = 0ll;
    f(i, 1, scc+1) {
        if(!vis[i]) {
            ll maxCoins = findMaxCoins(i);
            maxCollected = max(maxCollected, maxCoins);
        }
    }

    cout << maxCollected << '\n';
    return;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    coderAnsh();
    return 0;
}