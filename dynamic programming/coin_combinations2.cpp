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
const ll N = 1e3+5;
ll dp[N][105];

ll memo(vecll &coin, ll val, ll idx){
	if(val==0) return 1; 
	if(val < 0 || idx == size(coin)) return 0;
	if(dp[val][idx]!=-1) return dp[val][idx];	
	ll cnt = 0;
	for(ll c=idx;c<size(coin);c++){
		cnt += memo(coin, val-coin[c], c);
		cnt%=mod;
	}
	return dp[val][idx] = cnt;
}
//topDown
void solve(){
	ll n,x;
	cin>>n>>x;

	vecll coin(n);
	for(ll &i:coin) cin>>i;
	memset(dp,-1,sizeof(dp));
	ll ans = memo(coin,x,0);

	cout<<ans<<endl;

}

//BottomUp
void solve2(){
	ll n,x;
	cin>>n>>x;

	vecll coin(n);
	for(ll &i:coin) cin>>i;

	//no of ways to form x
	vecll dp(x+1,0);

	dp[0]=1;

	for(ll val=1;val<=x;val++){
		ll cnt=0;
		for(ll c:coin){
			if(val >= c){
				cnt += dp[val-c];
				cnt%=mod;
			}
		}
		dp[val] = cnt%mod;
	}
	cout<<dp[x]<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}