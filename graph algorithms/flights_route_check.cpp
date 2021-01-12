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
vecll g1[N],g2[N];
vecll vis1,vis2;


void dfs(vecll g[],vecll &vis, ll u){
	vis[u]=1;
	for(int v:g[u])
		if(vis[v]!=1)dfs(g,vis,v);
	return;
}


void solve(){
	cin>>n>>m;
	ll a,b;
	vis1.assign(n+1,0);
	vis2.assign(n+1,0);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g1[a].pb(b);
		g2[b].pb(a);
	}

	dfs(g1,vis1,1);
	dfs(g2,vis2,1);

	for(int i=1;i<=n;i++){
		if(vis1[i]!=1){
			cout<<"NO\n"<<1<<" "<<i<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis2[i]!=1){
			cout<<"NO\n"<<i<<" "<<1<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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