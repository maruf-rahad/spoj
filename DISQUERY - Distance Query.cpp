#include<bits/stdc++.h>
using namespace std;
#define mx 100010
vector<pair<int,int> >G[mx];
int level[mx];
int parent[mx];
int visited[mx];

struct node
{
    int maxi;
    int mini;
    int par;
};
node sparse[mx][21];
void zero(int n,int m)
{
    for(int i=0; i<=n+5; i++)
    {
        G[i].clear();
        visited[i] = 0;
        level[i] = 0;
        parent[i] = 0;
        for(int j=0; j<=m+2; j++)
        {
            sparse[i][j].par = -1;
            sparse[i][j].maxi = -1;
            sparse[i][j].mini = 1e8;
        }
    }
}

void bfs(int u)
{
    visited[u] = 1;
    parent[u] = -1;
    queue<int>q;

    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i].first;
            int c = G[u][i].second;
            if(visited[v]==0)
            {
                visited[v] = 1;
                parent[v] = u;
                level[v] = level[u]+1;
                sparse[v][0].maxi = c;
                sparse[v][0].mini = c;
                sparse[v][0].par = u;
                q.push(v);
            }
        }
    }
}

void lca_init(int n)
{
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1].par!=-1&&sparse[sparse[i][j-1].par][j-1].par!=-1)
            {
                sparse[i][j].par = sparse[sparse[i][j-1].par][j-1].par;
                sparse[i][j].maxi = max(sparse[i][j-1].maxi,sparse[sparse[i][j-1].par][j-1].maxi);
                sparse[i][j].mini = min(sparse[i][j-1].mini,sparse[sparse[i][j-1].par][j-1].mini);
            }
        }
    }
}

void lca_query(int p,int q)
{
    if(level[p]<level[q])
    {
        int temp = p;
        p = q;
        q = temp;
    }

    int log = 1;

    while(1)
    {
        if((1<<log)>level[p])break;
        log++;
    }
    int mxxx = -1;
    int mnnn = 1e9;
    for(int i=log;i>=0;i--)
    {
        if(level[p] - (1<<i) >=level[q])
        {
            mxxx = max(mxxx,sparse[p][i].maxi);
            mnnn = min(mnnn,sparse[p][i].mini);
            p = sparse[p][i].par;
        }
    }
  //  printf("%d %d %d %d\n",mxxx,mnnn,p,q);
    if(p==q)
    {
        printf("%d %d\n",mnnn,mxxx);
        return;
    }

    for(int i=log;i>=0;i--)
    {
        if(sparse[p][i].par!=-1&&sparse[p][i].par!=sparse[q][i].par)
        {
         //   printf("%d \n",i);
            mxxx = max(mxxx,max(sparse[p][i].maxi,sparse[q][i].maxi));
            mnnn = min(mnnn,min(sparse[p][i].mini,sparse[q][i].mini));
             p = sparse[p][i].par;
             q = sparse[q][i].par;
        }
    }
    mxxx = max(mxxx,max(sparse[p][0].maxi,sparse[q][0].maxi));
    mnnn = min(mnnn,min(sparse[p][0].mini,sparse[q][0].mini));
    printf("%d %d\n",mnnn,mxxx);

}
int main()
{
    int t,n,m,a,b,c,i,j,x,y;

    scanf("%d",&n);

        m = log2(n)+1;
        zero(n,m);
        for(i=1; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }

        bfs(1);

        lca_init(n);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            lca_query(a,b);
        }














    return 0;
}
