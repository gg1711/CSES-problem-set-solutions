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
#define size(a)	(int)a.size()

int K = 8;

bool valid(vector<string>&board, int r, int c){
	if(board[r][c]!='.') return 0;
	
	//check straight column
	for(int i=0;i<r;i++)
		if(board[i][c]=='Q') return 0;

	//check left diagonal
	for(int step=1;step<=min(r,c);step++){
		if(board[r-step][c-step]=='Q')
			return 0;
	}

	//check right diagonal
	for(int step=1;step<=min(r,K-c-1);step++){
		if(board[r-step][c+step]=='Q')
			return 0;
	}

	return 1;
}

void generate(vector<string>&board, int &total, int r){
	if(r<0)
		return;
	if(r==K) {
		total++;
		return;
	}
	for(int c=0;c<K;c++){
		if(valid(board,r,c)){
			board[r][c]='Q';
			generate(board, total, r+1);
			board[r][c]='.';
		}
	}
	return;
}


void solve(){
	vector<string>board(K);
	for(int i=0;i<K;i++)
		cin>>board[i];
	int total=0;
	generate(board, total, 0);
	cout<<total<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}