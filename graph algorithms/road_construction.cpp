#include<bits/stdc++.h>
using namespace std;

vector<int>par,sze,rnk;
int n,m,maxSize=1,cnt;


int find_set(int x){
	if(par[x]==x)return x;
	return par[x]=find_set(par[x]);
}

void merge(int x, int y){
	int a=find_set(x);
	int b=find_set(y);
	if(a!=b){
		if(rnk[a]<rnk[b])
			swap(a,b);
		par[b]=a;
		cnt--;
		sze[a]+=sze[b];
		if(rnk[a]==rnk[b])rnk[a]++;
		maxSize=max(maxSize,sze[a]);
	}
}

int main(){
	cin>>n>>m;
	int a,b;
	par.assign(n+1,0);
	sze.assign(n+1,1);
	rnk.assign(n+1,1);
	cnt=n;
	for(int i=1;i<=n;i++)
		par[i]=i;

	for(int i=0;i<m;i++){
		cin>>a>>b;
		merge(a,b);
		cout<<cnt<<" "<<maxSize<<"\n";
	}
}