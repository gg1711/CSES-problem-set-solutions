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

vector<veci> dp;

ll memo(veci &price, veci &pages, ll val, ll idx){
	if(val < 0) return -inf;
	if(idx>=size(price)) return 0;
	if(dp[val][idx]!=-1) return dp[val][idx];
	return dp[val][idx] = max(memo(price, pages, val,idx+1),pages[idx] +  memo(price, pages, val - price[idx], idx+1));
}

//topDown
void solve2(){
	ll n, x;
	cin>>n>>x;

	veci price(n), pages(n);

	for(auto &i:price) cin>>i;
	for(auto &i:pages) cin>>i;

	dp.assign(x+2,veci(n+2,-1));

	cout<<memo(price, pages,x,0)<<endl;;
}


//bottomUp
void solve(){
	ll n, x;
	cin>>n>>x;

	vecll price(n), pages(n);

	for(auto &i:price) cin>>i;
	for(auto &i:pages) cin>>i;

	vecll dp(x+1,0);
	
	for(ll idx=0;idx<n;idx++){
		for(ll val=x;val>0;val--){
			if(val >= price[idx])
				dp[val] = max(dp[val], dp[val - price[idx]] + pages[idx]);
		}
		// cout<<idx<<": ";print(dp);
	}
	
	cout<<*max_element(all(dp))<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}