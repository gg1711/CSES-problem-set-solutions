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
int vis[N];
vector<int>res;

//using Kahls algo
void solve2(){
	cin>>n>>m;
	int a,b;
	vecll indegree(n+1,0);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].pb(b);
		indegree[b]++;
	}
	queue<ll>q;
	for(ll i=1;i<=n;i++)
		if(indegree[i]==0)q.push(i);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		res.pb(u);
		for(int v:g[u]){
			indegree[v]--;
			if(indegree[v]==0)
				q.push(v);
		}
	}
	// print(res);
	vecll cnt(n+1,0);
	vecll par(n+1,0);
	cnt[1]=1;
	for(int u:res){
		for(int v:g[u])
			if(cnt[u]!=0){
				cnt[v]+=cnt[u];
				cnt[v]%=mod;
			}
		// chk(u);
		// print(cnt);
	}
	cout<<cnt[n]<<endl;
}

int main(){
	FAST
	solve2();
	return 0;
}