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

vector<vector<tiii>> adj(1005);

ll dfs(int node, ll minFlow, vi &vis) {
    if(node == 1001) return minFlow;

    vis[node] = true;
    for(auto &t : adj[node]) {
        int nbrNode = get<0>(t);
        int &wt = get<1>(t);
        int &ind = get<2>(t);

        if(wt>=1 && !vis[nbrNode]) {
            ll currFlow = dfs(nbrNode, min(minFlow, (ll)wt), vis);

            if(currFlow > 0) {
                wt-=currFlow;
                get<1>(adj[nbrNode][ind]) += currFlow;
                return currFlow;
            }
        }
    }

    return 0ll;
}

void coderAnsh() {
    int n, m, k;
    cin >> n >> m >> k;
    
    // create edges between boys and girls
    f(i, 0, k) {
        int boy, girl;
        cin >> boy >> girl;

        int sz1 = adj[boy].size();
        int sz2 = adj[500+girl].size();

        adj[boy].pb({500+girl, 1, sz2});
        adj[500+girl].pb({boy, 0, sz1});
    }

    // creaye edges between source and boys and between girls and target
    int src = 0, target = 1001;
    f(i, 1, 501) {
        int sz1 = adj[i].size();
        int sz2 = adj[0].size();

        adj[i].pb({0, 0, sz2});
        adj[0].pb({i, 1, sz1});

        int sz3 = adj[500+i].size();
        int sz4 = adj[1001].size();
        
        adj[500+i].pb({1001, 1, sz4});
        adj[1001].pb({500+i, 0, sz3});
    }

    // get the maxFlow using ford fulkerson method;
    ll maxFlow = 0;
    vi vis(1005, 0);
    while(true) {
        fill(vis.begin(), vis.end(), 0);
        ll currFlow = dfs(0, inf, vis);

        maxFlow+=currFlow;

        if(currFlow == 0) break;
    }

    cout << maxFlow << '\n';

    // get the dabce pairs by checking which edges have been blocked
    vector<pii> dancePairs;
    f(i, 1, 501) {
        for(auto &t : adj[i]) {
            int &wt = get<1>(t);
            int girl = get<0>(t);

            if(girl > 500 && wt == 0) {
                dancePairs.pb({i, girl-500});
            }
        }
    }

    // print the dance pairs
    for(auto &p : dancePairs) {
        cout << p.first << " " << p.second << '\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    coderAnsh();
    return 0;
}