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
const ll N=1e6+5;
ll dp[N];

ll recur(ll n){
	if(n==0) return 1;
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n];
	ll sum=0;
	for(int i=1;i<=6;i++)
		sum += recur(n-i);
	return dp[n] = sum%mod;
}
//topDown
void solve(){
	ll n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<recur(n)<<endl;
}

//BottomUp
void solve2(){
	ll n;
	cin>>n;

	vecll dp(n+1,0);
	dp[0]=1;
	for(ll val=1;val<=n;val++){
		for(ll i=1;i<=6;i++){
			if(val-i>=0)
				dp[val] +=dp[val-i];
		}
		dp[val]%=mod;
	}
	cout<<dp[n]<<endl;
}

int main(){
	FAST;
	solve2();
	return 0;
}