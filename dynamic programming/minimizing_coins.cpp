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
const ll N = 1e6+5;
ll dp[N];

ll memo(vecll &coin, ll val){
	if(val < 0) return inf;

	if(val==0) return 0; 
	if(dp[val]!=-1) return dp[val];	
	ll cnt = inf;
	for(ll c:coin)
		cnt = min(cnt, 1+memo(coin, val-c));
	return dp[val] = cnt;
}
//topDown
void solve(){
	ll n,x;
	cin>>n>>x;

	vecll coin(n);
	for(ll &i:coin) cin>>i;
	memset(dp,-1,sizeof(dp));
	ll ans = memo(coin,x);

	if(ans==inf) ans=-1;
	cout<<ans<<endl;

}

//BottomUp
void solve2(){
	ll n,x;
	cin>>n>>x;

	vecll coin(n);
	for(ll &i:coin) cin>>i;

	vecll dp(x+1,inf);

	dp[0]=0;

	for(ll val=1;val<=x;val++){
		ll cnt=inf;
		for(ll c:coin){
			if(val >= c)
				cnt = min(cnt,1+dp[val-c]);
		}
		dp[val] = cnt;
	}
	if(dp[x]==inf) cout<<-1<<endl;
	else cout<<dp[x]<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}