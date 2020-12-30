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

int dp[100005][105];

ll memo(vecll &a, ll sum, ll idx){
	//will write later

}


//topDown
void solve2(){
	ll n;
	cin>>n;
	vecll a(n);
	ll sum=0;
	for(auto &val:a){ 
		cin>>val;
		sum+=val;
	}
	memset(dp,-1,sizeof(dp));
	memo(a,sum,n-1);
}


//bottomUp
void solve(){
	ll n;
	cin>>n;
	vecll a(n);
	ll sum=0;
	for(auto &val:a){ 
		cin>>val;
		sum+=val;
	}
	vector<bool> dp(sum+1,0);

	dp[0]=1;
	for(ll val:a){
		for(ll idx=sum;idx>=val;idx--){
			dp[idx] = dp[idx] | dp[idx-val];
		}
	}
	ll cnt=0;
	for(ll idx=1;idx<=sum;idx++) 
		if(dp[idx]) cnt++;
	cout<<cnt<<endl;
	for(ll idx=1;idx<=sum;idx++)
		if(dp[idx]) cout<<idx<<" ";

}

int main(){
	FAST;
	solve();
	return 0;
}