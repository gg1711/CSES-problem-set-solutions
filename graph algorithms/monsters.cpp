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
const int N = 1e6 + 5;
ll n,m;

char g[1005][1005];
int vis[1005][1005];
int dis[1005][1005];
pii par[1005][1005];

vector<pii> src,dest;

char getChar(pii p, pii s){
	int r=s.F,c=s.S;
	int r1=p.F,c1=p.S;

	if(r1==(r+1)) return 'U';
	if(r1==(r-1)) return 'D';
	if(c1==(c+1)) return 'L';
	if(c1==(c-1)) return 'R';

	return 'E';
}

void solve(){
	cin>>n>>m;
	pii men;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='M'|| g[i][j]=='A') src.pb({i,j});
			if((j==m-1 || j==0 || i==0 || i==n-1) && g[i][j]!='#')
				dest.pb({i,j});
			if(g[i][j]=='A') men = {i,j};
		}

	memset(vis,0,sizeof(vis));
	memset(par,-1,sizeof(par));
	memset(dis,-1,sizeof(dis));

	queue<pii>q;
	
	for(auto p:src){
		if(p!=men){
			vis[p.F][p.S]=2;
			dis[p.F][p.S]=0;		
			q.push(p);
		}
	}

	vis[men.F][men.S]=1;
	dis[men.F][men.S]=0;
	q.push(men);

	vector<pii>paths = {{0,1},{0,-1},{1,0},{-1,0}};
	int level=0;
	while(!q.empty()){
		level++;
		int sze=sz(q);

		for(int i=0;i<sze;i++){
			pii pp=q.front();
			int r=pp.F,c=pp.S;
			q.pop();
			for(auto p : paths){
				int r1=r+p.F, c1=c+p.S;
				if(r1<0 || c1<0 || r1>=n || c1>=m || vis[r1][c1]!=0 || g[r1][c1]=='#') continue;
				else{
					dis[r1][c1]=1+dis[r][c];
					vis[r1][c1]=vis[r][c];
					par[r1][c1]={r,c};
					q.push({r1,c1});
				}
			}
		}
	}
	// cout<<"src"<<endl;
	// for(auto p:src)
	// 	cout<<p.F<<" "<<p.S<<endl;
	// cout<<"dest"<<endl;
	// for(auto p:dest)
	// 	cout<<p.F<<" "<<p.S<<endl;

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<vis[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }



	pii final= {-1,-1};
	for(auto p:dest){
		if(vis[p.F][p.S]==1){
			final=p;
			break;
		}
	}
	if(final.F==-1){
		cout<<"NO"<<endl;
		return;
	}
	
	cout<<"YES"<<endl;
	cout<<dis[final.F][final.S]<<endl;

	if(par[final.F][final.S]==pii{-1,-1}) return;
	string res="";

	do{
		res+=getChar(par[final.F][final.S], final);
		final = par[final.F][final.S];
	}
	while(final!=men);
	reverse(all(res));

	cout<<res<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}