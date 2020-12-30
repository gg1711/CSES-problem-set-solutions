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

const ll N = (505*505)/2;

ll dp[N][505];

ll memo(ll reqSum,ll sum,ll idx, ll &n){
	// cout<<sum<<" "<<idx<<endl;
	if(sum==reqSum) return 1;
	if(idx > n || sum>reqSum) return 0;
	if(dp[sum][idx]!=-1) return dp[sum][idx];
	return dp[sum][idx] = (memo(reqSum, sum+idx, idx+1,n) + memo(reqSum, sum,idx+1,n))%mod;
}

ll power(ll a, ll n){
	if(n==1)
		return a;
	ll ans = power(a,n/2)%mod;
	ans=(ans*ans)%mod;

	if(n%2) ans = ans*a;
	return ans%mod;
}

//topDown
void solve2(){
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=i;
	memset(dp,-1,sizeof(dp));
	if(sum%2)
		cout<<0<<endl;
	else{
		ll ans = memo(sum/2,0,1,n);
		ans = (ans * power(2,mod-2))%mod;
		cout<<ans<<endl;
	}
}

//bottomUp
void solve(){
	
}

int main(){
	FAST
	solve2();
	return 0;
}