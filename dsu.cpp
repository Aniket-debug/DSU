int par[100001];
int ran[100001];

void makeset(int n){
    for (int i=0;i<=n;i++){
        par[i]=i;
        ran[i]=0;
    }
}

int find(int nd){
    if (nd==par[nd])return nd;
    return  par[nd]=find(par[nd]);
}

void unin(int u,int v){
    u=find(u);
    v=find(v);
    if (ran[u]<ran[v])
        par[u]=v;
    else if (ran[u]>ran[v])
        par[v]=u;
    else{
        par[v]=u;
        ran[u]++;
    }
}
