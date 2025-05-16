
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define ll long long 

#define vi vector<int> 
#define vvi vector<vector<int>>

#define f(i, s, e) for(int i=s; i<e; i+=1)
#define fe(i, s, e) for(int i=s; i<=e; i+=1)
#define rf(i, e, s) for(int i=e; i>=s; i-=1)

#define pb push_back;


int minimumDifference(vector<int>& nums, int n) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n/2 + 1, vector<int>(totalSum + 1)));
      
}

int main() {
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    vi arr(n);
    cout << "Enter the elements of the array" << endl;

    f(i,0,n) {
        cin >> arr[i];
    }

    cout << "The minimum difference partition of the array is : " <<  minimumDifference(arr, n) << endl;
    return 0;
}