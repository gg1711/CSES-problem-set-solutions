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
const int N = 2e5 + 10;
const ll nodes = 1e5;
ll n,m;
vecll g1[N],g2[N];
ll vis[N],res[N];
vector<ll>order;

ll neg(ll a){
	if(a<nodes) return a+nodes;
	else return a-nodes;
}

void dfs1(ll u){
	vis[u]=1;
	for(ll v:g1[u])
		if(!vis[v]) dfs1(v);
	order.pb(u);
}

void dfs2(ll u, ll cnt){
	vis[u]=1;
	res[u]=cnt;
	// cout<<u<<" "<<cnt<<endl;
	for(ll v:g2[u])
		if(!vis[v])dfs2(v,cnt);
}

void solve(){
	cin>>m>>n;
	memset(vis,0,sizeof(vis));
	memset(res,0,sizeof(res));
	char sign;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>sign>>a;
		if(sign=='-') a = neg(a);
		cin>>sign>>b;
		if(sign=='-') b = neg(b);

		//form a V b --- ~a->b ^ ~b->a
		g1[neg(a)].pb(b);
		g1[neg(b)].pb(a);

		//constructing transpose for kosaraju algo
		g2[b].pb(neg(a));
		g2[a].pb(neg(b));
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=1)
			dfs1(i);
		if(vis[neg(i)]!=1)
			dfs1(neg(i));
	}
	memset(vis,0,sizeof(vis));
	reverse(all(order));
	// print(order);
	int cnt=0;
	for(ll i:order){
		if(vis[i]!=1){
			cnt++;
			dfs2(i,cnt);
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<res[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=1;i<=n;i++){
	// 	cout<<res[neg(i)]<<" ";
	// }
	// cout<<endl;
	vecll ans(n+1,0);

	for(int i=1;i<=n;i++){
		if(res[i]==res[neg(i)]){
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
		ans[i] = (res[i] < res[neg(i)])?0:1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1)
			cout<<'+'<<" ";
		else
			cout<<'-'<<" ";
	}
	cout<<endl;

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