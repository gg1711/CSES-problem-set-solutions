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
vecll vis;

stack<ll>st;
vector<int>res;
void dfs(vecll g[],ll u, ll flag=0){
	vis[u]=1;	
	
	for(ll v:g[u])
		if(!vis[v])
			dfs(g,v,flag);

	if(flag==0) st.push(u);
	else res[u]=flag;
}

void solve(){
	cin>>n>>m;
	ll a,b;
	vis.assign(n+1,0);
	res.assign(n+1,0);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g1[a].pb(b);
		g2[b].pb(a);
	}
	for(int i=1;i<=n;i++)
		if(vis[i]!=1)
			dfs(g1,i,0);
	vis.assign(n+1,0);
	ll cnt=0;
	while(sz(st)!=0){
		ll u=st.top();
		// chk(u);
		st.pop();
		if(vis[u]!=1){
			cnt++;
			dfs(g2,u,cnt);
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		cout<<res[i]<<" ";
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