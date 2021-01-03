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
char g[1005][1005];
int vis[1005][1005];
ll n,m;

char getChar(pii p){
	int r=p.F,c=p.S;
	int val=vis[r][c];
	int r1=val/m,c1=val%m;

	if(r1==(r+1)) return 'U';
	if(r1==(r-1)) return 'D';
	if(c1==(c+1)) return 'L';
	if(c1==(c-1)) return 'R';

	return 'E';
}

void solve(){
	cin>>n>>m;
	memset(vis,-1,sizeof(vis));
	pii s,e;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='A') s={i,j};
			if(g[i][j]=='B') e={i,j};
	}

	queue<pii>q;
	q.push(s);
	vis[s.F][s.S]=1;
	int level=0;
	bool flag=0;
	vector<veci>path = {{0,1},{1,0},{0,-1},{-1,0}};
	while(!q.empty() && flag==0){
		level++;
		int sze=sz(q);

		for(int i=0;i<sze && flag==0;i++){
			int r=q.front().F;
			int c=q.front().S;
			// cout<<r<<" "<<c<<endl;
			q.pop();
			for(auto p:path){
				int r1=r+p[0],c1=c+p[1];
				if(r1>=n || c1>=m || r1<0 || c1<0 || vis[r1][c1]!=-1 || g[r1][c1]=='#') continue;
				vis[r1][c1]=(r*m+c);
				q.push({r1,c1});
				if(e.F==r1 && e.S==c1){
					cout<<"YES"<<endl;
					cout<<level<<endl;
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==0){
		cout<<"NO"<<endl;
	}
	else{
		string ans="";
		pii p=e;
		while(p!=s){
			ans+=getChar(p);
			int val=vis[p.F][p.S];
			p={val/m,val%m};
		}
		reverse(all(ans));
		cout<<ans<<endl;
	}

}

int main(){
	FAST
	solve();
	return 0;
}