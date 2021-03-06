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
unordered_set<ll>g[N];
set<pll>edges;
vecll vis,deg,res;

ll cnt=0;

void dfs(ll u){
	// cout<<u<<endl;
	while(sz(g[u])>0){
		ll v=*g[u].begin();
		cnt++;
		g[u].erase(v);
		g[v].erase(u);
		dfs(v);
	}
	res.pb(u);
}

void solve(){
	cin>>n>>m;
	deg.assign(n+1,0);
	vis.assign(n+1,0);
	ll a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		deg[a]++;deg[b]++;
		g[a].insert(b);
		g[b].insert(a);
	}
	// print(deg);
	for(int i=1;i<=n;i++){
		if(deg[i]%2!=0){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	dfs(1);
	if(cnt!=m){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	for(ll i:res)
		cout<<i<<" ";
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