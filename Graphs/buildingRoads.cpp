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
#define MOD 1000000007
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

// directional vectors
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

// typedefs
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void dfs(int node, vvi &adj, vector<bool> &vis) {
    vis[node] = true;

    for(auto &nbr:adj[node]) {
        if(vis[nbr]) continue;
        dfs(nbr, adj, vis);
    }
}

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    vvi adj(n+1);
    f(i, 0, m) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<bool> vis(n+1, false);
    vi roots;
    int numConn = 0;

    f(i, 1, n+1) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            numConn+=1;
            roots.pb(i);
        }
    }

    if(numConn == 1) {
        cout << 0;
        return;
    }

    cout << numConn-1 << endl;
    f(i, 0, roots.size() - 1) {
        cout << roots[i] << " " << roots[i+1] << endl; 
    }

    return;
}

int main() {
    coderAnsh();
    return 0;
}
