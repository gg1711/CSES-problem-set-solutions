#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll	 long long int
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

ll inf = 1e18;
const int N = 2e5 + 5;
ll n,m;

vecll port;



void solve(){
	ll q;
	cin>>n>>q;
	memset(dp,-1,sizeof(dp));
	port.assign(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>port[i]; 

	for(int i=1;i<=n;i++)
		dp[i][0]=port[i];

	for(int bit=1;bit<31;bit++){
		for(int i=1;i<=n;i++)
			dp[i][bit]=dp[dp[i][bit-1]][bit-1];
	}
	
	ll x,k;
	while(q--){
		cin>>x>>k;
		query(x,k);
	}
}

int main(){
	FAST;
	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now(); 
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cerr << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	return 0;
}