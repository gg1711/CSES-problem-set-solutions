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

int dp[502][502];

int memo(int a, int b){
	// cout<<a<<" "<<b<<endl;
	if(a==b) return 0;

	if(a==1 || b==1) return max(a,b) - 1;
	if(dp[a][b]!=-1) return dp[a][b];
	int ans=inf;

	for(ll i=1;i+i<=a;i++)
		ans = min(ans,1 + memo(i,b) + memo(a-i,b));
	for(ll i=1;i+i<=b;i++)
		ans = min(ans,1 + memo(a,i) + memo(a,b-i));
	return dp[a][b] = ans;
}	

//topDown
void solve2(){
	int a,b;
	cin>>a>>b;
	// dp.assign(a+1, veci(b+1,-1));
	memset(dp,-1,sizeof(dp));
	int ans = memo(a,b);

	// for(auto i:dp){
	// 	print(i);
	// }

	cout<<ans<<endl;
}


//bottomUp
void solve(){
	ll a,b;
	cin>>a>>b;

	vector<vecll>dp(a+1, vecll(b+1,0));

	for(ll i=1;i<=b;i++)
		dp[1][i] = i-1;

	for(ll i=1;i<=a;i++)
		dp[i][1] = i-1;

	for(ll i=1;i<=min(a,b);i++)
		dp[i][i]=0;

	for(ll i=2;i<=a;i++){
		for(ll j=2;j<=b;j++){
			ll ans=inf;
			if(i==j) continue;
			for(ll val=1;val+val<=i;val++)
				ans = min(ans, 1+dp[val][j]+dp[i-val][j]);
			for(ll val=1;val+val<=j;val++)
				ans = min(ans, 1+dp[i][val]+dp[i][j-val]);
			dp[i][j]=ans;
		}
	}
	// for(auto i:dp){
	// 	print(i);
	// }

	cout<<dp[a][b]<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}