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

void dfs(int node, vvi &adj, vi &vis, stack<int> &st) {
    vis[node] = true;

    for(auto &nbr : adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, adj, vis, st);
        }
    }

    st.push(node);
}

void revDfs(int node, vvi &adj, vi &vis, int scc, vi &comp) {
    vis[node] = true;
    comp[node] = scc;

    for(auto &nbr : adj[node]) {
        if(!vis[nbr]) {
            revDfs(nbr, adj, vis, scc, comp);
        }
    }
}

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    vvi adj1(2*m+5), adj2(2*m+5);
    f(i, 0, n) {
        char x, y;
        int a, b;

        cin >> x >> a >> y >> b;

        if(x == '-') a = 2*m - a + 1;
        if(y == '-') b = 2*m - b + 1;
        
        adj1[2*m-a+1].pb(b), adj1[2*m-b+1].pb(a);
        adj2[a].pb(2*m-b+1), adj2[b].pb(2*m-a+1);
    }

    stack<int> st;
    vi vis(2*m+5, 0);
    f(i, 1, 2*m+1) {
        if(!vis[i]) {
            dfs(i, adj1, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    
    int scc = 1;
    vi comp(2*m+5);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            revDfs(node, adj2, vis, scc, comp);
            scc+=1;
        }
    }

    vi boolVal(2*m+5);
    f(i, 1, m+1) {
        int i_comp = 2*m-i+1;

        if(comp[i] == comp[i_comp]) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }

        boolVal[i] = (comp[i] > comp[i_comp] ? 1 : 0);
    }

    f(i, 1, m+1) {
        if(boolVal[i]) {
            cout << '+' << " ";
        }

        else cout << '-' << " ";
    }

    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    coderAnsh();
    return 0;
}