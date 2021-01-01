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

#define job pair<ll,pll>

ll dp[2*100005];

ll memo(vector<job> &arr,ll idx){
	// cout<<idx<<endl;
	if(idx<0 ) return 0;
	if(dp[idx]!=-1) return dp[idx];
	job j = {arr[idx].S.F-1,{inf, inf}};
	ll new_idx = lower_bound(arr.begin(), arr.end(),j) - arr.begin();
	new_idx--;

	ll a = arr[idx].S.S + memo(arr,new_idx);
	ll b = memo(arr,idx-1);

	return dp[idx] = max(a,b);
}

//topDown
void solve2(){
	ll n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	vector<job>arr(n);
	for(ll idx=0;idx<n;idx++){
		cin>>arr[idx].S.F>>arr[idx].F>>arr[idx].S.S;
	}
	sort(all(arr));

	ll ans = memo(arr,n-1);
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