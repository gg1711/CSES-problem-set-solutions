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

ll dp[5005][5005];

ll memo(vecll &a, ll left, ll right){
	if(left>right) return 0;

	if(dp[left][right]!=-1) return dp[left][right];

	ll c1 = a[left] + min(memo(a,left+2,right), memo(a, left+1,right-1));
	ll c2 = a[right] + min(memo(a,left+1,right-1), memo(a, left,right-2));

	return dp[left][right] = max(c1,c2);
}


//topDown
void solve2(){
	ll n;
	cin>>n;
	vecll a(n);
	memset(dp,-1,sizeof(dp));
	for(auto &val:a) cin>>val;
	ll ans = memo(a,0,sz(a)-1);	
	cout<<ans<<endl;
}

//bottomUp
void solve(){
	

}

int main(){
	FAST
	solve2();
	return 0;
}