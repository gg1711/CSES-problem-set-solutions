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

ll memo(string &s, string &t, ll m, ll n){
	if(m<0 && n<0) return 0;
	if(m<0 || n<0) return 1+max(m,n);

	if(dp[m][n]!=-1) return dp[m][n];

	if(s[m]==t[n]) return memo(s,t,m-1,n-1);

	return dp[m][n] = 1 + min({memo(s,t,m-1,n), memo(s,t,m,n-1), memo(s,t,m-1,n-1)});
}

//topDown
void solve2(){
	string s,t;
	cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	ll ans = memo(s,t,sz(s)-1,sz(t)-1);

	cout<<ans<<endl;

}


//bottomUp
void solve(){
	string s,t;
	cin>>s>>t;

	vector<vecll> dp(sz(s)+1,vecll(sz(t)+1,0));

	for(ll i=0;i<=sz(s);i++)
		dp[i][0] = i;

	for(ll j=0;j<sz(t);j++)
		dp[0][j] = j;

	for(ll i=1;i<=sz(s);i++){
		for(ll j=1;j<=sz(t);j++){
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
		}
	}

	cout<<dp[sz(s)][sz(t)]<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}