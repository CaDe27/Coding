#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
#define f(i,c,d) for(int i=c;i<d;i++)
#define debug(a) cout << #a:  << a << endl;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define INF 0x3f3f3f3f
#define pii pair<int,int> 
#define ll long long
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N = 1e4+5;
vector<int> g[N];
int vis[N],match[N],cnt=1;
bool dfs(int x){
	for(auto it:g[x]){
		if(vis[it]==cnt) continue;
		vis[it]=cnt;
		if(!match[it]||dfs(match[it])){
			match[it]=x;
			return true;
		}
	}
	return false;
}
int main(){
	int n,m;
	n=read(),m=read();
	int k,x;
	f(i,1,n+1){
		k=read();
		while(k--) x=read(),g[i].push_back(x);
	}
	int ans=0;
	f(i,1,n+1){
		if(dfs(i)) ans++;
		cnt++;
	}
	cout<<m-ans<<endl;
	return 0;
}