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
#define tiiii tuple<int,int,int,int>

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

ll dfs(int node, ll minFlow, vi &vis, vector<vector<tiiii>> &adj, int n) {
    if(node == n) return minFlow;

    vis[node] = true;
    for(auto &t : adj[node]) {
        int nbrNode = get<0>(t);
        int &wt = get<1>(t);
        int ind = get<2>(t);

        if(wt > 0 && !vis[nbrNode]) {
            ll flow = dfs(nbrNode, min(minFlow, (ll)wt), vis, adj, n);

            if(flow > 0) {
                wt-=flow;
                get<1>(adj[nbrNode][ind])+=flow;
                return flow;
            }
        }
    }

    return 0;
}

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    // create the adjacency list of the graph taking edges in both directions with uniuqe ids to backtrack later
    vector<vector<tiiii>> adj(n+1);
    f(i, 1, m+1) {
        int a, b;
        cin >> a >> b;

        int sz1 = adj[a].size();
        int sz2 = adj[b].size();

        adj[a].pb({b, 1, sz2, i+1});
        adj[b].pb({a, 0, sz1, -i-1});
    }

    // get the maxFlow;
    vi vis(n+1, 0);
    ll maxFlow = 0ll;
    while(true) {
        fill(vis.begin(), vis.end(), 0);
        ll currFlow = dfs(1, inf, vis, adj, n);

        maxFlow+=currFlow;

        if(currFlow == 0) break;
    }

    cout << maxFlow << '\n';

    unordered_map<int,bool> vis2;
    f(i, 0, maxFlow) {
        vi path = {1};
        int node = 1;

        while(node != n) {
            for(auto &t : adj[node]) {
                int nbrNode = get<0>(t);
                int wt = get<1>(t);
                int ind = get<2>(t);
                int id = get<3>(t);

                if(wt == 0 && id > 0 && !vis2[id]) {
                    path.pb(nbrNode);
                    node = nbrNode;
                    vis2[id] = true;
                    break;
                }
            }
        }

        cout << path.size() << '\n';
        for(auto &room : path) {
            cout << room << " ";
        }
        cout << '\n';
    }
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    coderAnsh();
    return 0;
}