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
#define sz(a)	(int)(a).size()

ll inf = 1e10;

int dp[105][100005];

ll memo(veci &a, ll val, ll idx){

	if(idx==0)
		return (a[idx]==0 || a[idx]==val)?1:0;
	
	if(a[idx]!=0 && val!=a[idx]) return 0;

	if(dp[val][idx]!=-1) return dp[val][idx];
	ll cnt=0;

	cnt+=memo(a,val-1,idx-1);
	cnt+=memo(a,val,idx-1);
	cnt+=memo(a,val+1,idx-1);

	return dp[val][idx] = cnt%mod;
}

//topDown TLE
void solve2(){
	ll n,m;
	cin>>n>>m;
	veci a(n);
	for(auto &val:a) cin>>val;
	memset(dp,-1,sizeof(dp));
	ll ans=0;
	if(a[n-1]==0){
		for(ll val=1;val<=m;val++)
			ans+=memo(a,val,n-1);
	}
	else{
		ans+=memo(a,a[n-1],n-1);
	}
	cout<<ans<<endl;

	
}


//bottomUp
void solve(){
	ll n,m;
	cin>>n>>m;
	vecll a(n);
	for(auto &val:a) cin>>val;

	vector<vecll> dp(m+1,vecll(n+1,0));
	
	// for(ll idx=0;idx<n;idx++)
	// 	dp[a[idx]][idx] = 1;
	if(a[0]==0){
		for(ll val=1;val<=m;val++){
			dp[val][0]=1;
		}
	}
	else
		dp[a[0]][0]=1;

	for(ll idx=1;idx<n;idx++){
		if(a[idx]!=0){
			ll val = a[idx];
			dp[val][idx] += dp[val-1][idx-1];
			dp[val][idx] += dp[val][idx-1];
			if(val<m) dp[val][idx] += dp[val+1][idx-1];
			dp[val][idx]%=mod;
		}
		else{
			for(ll val=1;val<=m;val++){
				dp[val][idx] += dp[val-1][idx-1];
				dp[val][idx] += dp[val][idx-1];
				if(val<m) dp[val][idx] += dp[val+1][idx-1];
				dp[val][idx]%=mod;
			}
		}
	}
	// for(auto &i:dp){
	// 	print(i);
	// }
	ll ans=0;
	if(a[n-1]==0){
		for(ll val=1;val<=m;val++)
			ans+=dp[val][n-1];
	}
	else
		ans+=dp[a[n-1]][n-1]; 

	cout<<ans%mod<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}