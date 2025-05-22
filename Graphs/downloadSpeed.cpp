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
#define tiii tuple<int,int,int>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* UTILS */
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
const ll inf = 1e18;

// mathematical functions
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

// directional movements
string dir = "LURD";
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int fx[]={-2, -2, -1, -1,  1,  1,  2,  2}; // knight movements
int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // knight movements

// typedefs
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

ll bin_exp(int a, int b) {
    if(b==0) return 1;

    ll ans = bin_exp(a, b/2);

    if(b & 1) {
        return ans*ans*a;
    }

    else return ans*ans;
}

ll dfs(int node, int n, vi &vis, vector<vector<tiii>> &adj, ll minFlow, int d) {
    if(node == n) return minFlow;
    vis[node] = 1;

    for(auto &t : adj[node]) {
        int nbrNode = get<0>(t);
        int &wt = get<1>(t);
        int idx = get<2>(t);
        
        if(wt >= d && !vis[nbrNode]) {
            ll flow = dfs(nbrNode, n, vis, adj, min(minFlow, (ll)wt), d);

            if(flow > 0) {
                wt -= flow;
                get<1>(adj[nbrNode][idx]) += flow;
                return flow;
            }
        }   
    }

    return 0;
}

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    // creating adj list and finding max edge weight
    vector<vector<tiii>> adj(n+1);
    int maxWt = 0;
    f(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        
        maxWt = max(maxWt, w); // get the max edge weight
        
        // index of where in the adjacency list of the other node will this node lie 
        adj[a].push_back({b, w, (int)adj[b].size()});
        adj[b].push_back({a, 0, (int)adj[a].size() - 1});
    }

    // get the nearest power of 2 to maxWt
    ll d = bin_exp(2, (int)log2(maxWt));

    // finding the max flow
    ll maxFlow = 0;
    vi vis(n+1, 0);

    while(d > 0) {
        while(true) {
            fill(vis.begin(), vis.end(), 0);
            int currFlow = dfs(1, n, vis, adj, inf, d);
            maxFlow += currFlow;

            if(currFlow == 0) break;
        }

        d >>= 1LL;
    }

    cout << maxFlow << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    coderAnsh();
    return 0;
}