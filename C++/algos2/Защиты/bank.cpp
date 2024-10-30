#include <iostream>
#include<stdio.h>
#include<vector>
#include<memory.h>
using namespace std;
int a,b,i,n,m,c=0,p;
vector<int> g[100];
vector<int> ans;
vector<int> vis;
vector<int> colors;
int  dfs(int v, int color){colors[v]=color; if (color==1){ans.push_back(v);}
for(int j=0;j<g[v].size();j++){
    int r=g[v][j];
    if (colors[v]==colors[r]){c=1;}
    if (vis[r]==0){vis[r]=1;if (color==1){dfs(r,2);}else{dfs(r,1);}}
}
return 0;
}
int main()
{    cin>>n>>m;
    vis.assign(n,0);
colors.assign(n,0);
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    for(i=0;i<n;i++){
        if (vis[i]==0){vis[i]=1;dfs(i,1);}
    }
    if (c==1){cout<<"NO";}
    else{cout<<"YES";cout<<endl;for(i=0;i<ans.size();i++){cout<<ans[i]+1<<" ";}}
    return 0;}
