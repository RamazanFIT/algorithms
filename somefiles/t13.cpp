#include<bits/stdc++.h>
using namespace std;

vector<int>a[100001];
bool used[100001];
int cenparent[100001],cendepth[100001],cendist[100001][20];
int sz[100001],mindist[100001];
void find_sz(int n,int parent=0) {
    sz[n]=1;
    for(int i:a[n]) {
        if(i==parent || used[i])continue;
        find_sz(i,n);
        sz[n]+=sz[i];
    }
}
int find_centroid(int n,int siz,int parent=0) {
    for(int i:a[n]) {
        if(used[i]==0 && i!=parent && sz[i]>siz/2)return find_centroid(i,siz,n);
    }
    return n;
}
void upd_cen(int n,int depth,int parent=0,int dep=0) {
    cendist[n][depth]=dep;
    for(int i:a[n]) {
        if(i==parent || used[i])continue;
        upd_cen(i,depth,n,dep+1);
    }
}
void dfs(int n,int depth=0,int parent=0) {
    find_sz(n);
    int c=find_centroid(n,sz[n]);
    upd_cen(c,depth);
    cendepth[c]=depth;
    cenparent[c]=parent;
    used[c]=1;
    for(int i:a[c]) {
        if(used[i]==0)dfs(i,depth+1,c);
    }
}
void upd(int n) {
    int cur=n;
    while(cur>0) {
        mindist[cur]=min(mindist[cur],cendist[n][cendepth[cur]]);
        cur=cenparent[cur];
    }
}
int ask(int n) {
    int cur=n;
    int ans=INT_MAX;
    while(cur>0) {
        ans=min(ans,mindist[cur]+cendist[n][cendepth[cur]]);
        cur=cenparent[cur];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<n;i++) {
        int x,y;cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)mindist[i]=400000;
    upd(1);
    for(int i=0;i<q;i++) {
        int x,y;cin>>x>>y;
        if(x==1) {
            upd(y);
        } else {
            cout<<ask(y)<<'\n';
        }
    }
    return 0;
}
