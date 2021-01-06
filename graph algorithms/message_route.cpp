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
const int N = 2e5 + 5;
ll n,m;
vector<int>g[N];
bool vis[N];
int par[N];

void bfs(){
	queue<int>q;
	q.push(1);
	memset(par,-1,sizeof(par));
	
	par[1]=0;
	vis[1]=1;
	int level=1;
	while(!q.empty() && vis[n]==0){
		int sze=sz(q);
		level++;

		for(int i=0;i<sze;i++){
			int u=q.front();
			q.pop();
			for(int v:g[u]){
				if(!vis[v]){
					vis[v]=1;
					par[v]=u;
					q.push(v);
				}
			}
		}
	}

	if(vis[n]!=0){
		cout<<level<<endl;
		vector<int>res;
		int p=n;
		while(p!=0){
			res.pb(p);
			p=par[p];
		}
		reverse(all(res));
		for(int i:res)
			cout<<i<<" ";
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}

	
}
void solve(){
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(vis,0,sizeof(vis));
	bfs();
}

int main(){
	FAST
	solve();
	return 0;
}