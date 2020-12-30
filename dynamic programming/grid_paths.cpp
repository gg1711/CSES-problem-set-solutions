#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll	long long int
#define ld   long double
#define pii  pair<int,int>
#define pll pair<ll,ll>
#define veci vector<int>
#define vecll vector<ll>
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define size(a)	(int)a.size()

ll inf = 1e10;

ll dp[1005][1005];

ll paths(vector<string>&grid, ll r,ll c){
	if(r>=size(grid) || c>=size(grid) || r<0 || c<0) return 0;
	
	if(grid[r][c]=='*') return 0;

	if(r==size(grid)-1 && c==size(grid)-1)
		return 1;

	if(dp[r][c]!=-1) return dp[r][c];

	ll cnt=0;
	cnt+=paths(grid,r+1,c);
	cnt%=mod;
	cnt+=paths(grid,r,c+1);	
	cnt%=mod;

	return dp[r][c] = cnt;
}

//topDown
void solve(){
	ll n;
	cin>>n;
	vector<string>grid(n);
	memset(dp,-1,sizeof(dp));
	for(auto &str:grid)
		cin>>str;

	cout<<paths(grid,0,0)<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}