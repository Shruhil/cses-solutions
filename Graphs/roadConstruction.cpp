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
typedef unsigned long long int  uint64;

string dir = "LURD";
const ll inf = 1e18;

class DisjointSet {
private:
    vi size, parent;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);

        f(i, 0, n) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int a, int b) {
        int par_a = findUPar(a);
        int par_b = findUPar(b);

        if(par_a == par_b) return;

        if(size[par_a] >= size[par_b]) {
            size[par_a] += size[par_b];
            parent[par_b] = par_a;
        }

        else {
            size[par_b] += size[par_a];
            parent[par_a] = par_b;
        }
    }   

    int getSize(int node) {
        return size[node];
    }
};

void coderAnsh() {
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n+1);
    int numComp = n;
    int maxSize = 1;

    f(i, 0, m) {
        int a, b;
        cin >> a >> b;

        if(ds.findUPar(a) == ds.findUPar(b)) {
            cout << numComp << " ";
            cout << maxSize << '\n';
            continue;
        }
        
        ds.unionBySize(a, b);
        numComp-=1;
        maxSize = max(maxSize, max(ds.getSize(ds.findUPar(a)), ds.getSize(ds.findUPar(b))));

        cout << numComp << " ";
        cout << maxSize << '\n';
    }

    return;
}   

int main() {
    coderAnsh();
    return 0;
}