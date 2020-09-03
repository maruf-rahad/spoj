#include<bits/stdc++.h>
using namespace std;
#define mx 1010
vector<int>G[1010];
int sparse[mx][15];
int level[1010];
int parent[1010];
int visited[1010];

void zero(int n,int m)
{
    for(int i=0;i<=n+5;i++)
    {
        G[i].clear();
        parent[i] = 0;
        visited[i] = 0;
        level[i] = 0;
        for(int j=0;j<=m+2;j++)
        {
            sparse[i][j] = -1;
        }
    }
}

void bfs(int u)
{
    parent[u] = -1;
    visited[u] = 1;

    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(visited[v]==0)
            {
                visited[v] = 1;
                level[v] = level[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void lca_init(int n)
{
    for(int i=1;i<=n;i++)
    {
        sparse[i][0] = parent[i];
    }

    for(int j=1;(1<<j) <=n; j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(sparse[i][j-1]!=-1)
            {
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
            }
        }
    }
}

int lca_query(int n,int p,int q)
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
        if(1<<log >level[p])break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(level[p] - (1<<i)>=level[q])
        {
            p = sparse[p][i];
        }
    }
    if(p==q)return p;

    for(int i=log;i>=0;i--)
    {
        if(sparse[p][i]!=-1&&sparse[p][i]!=sparse[q][i])
        {
            p = sparse[p][i];
            q = sparse[q][i];
        }
    }
    return parent[p];



}
int main()
{
    int t,n,m,a,b,i,j,x,y,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        x = log2(n)+1;
        zero(n,x);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&a);
                G[i].push_back(a);
                G[a].push_back(i);
            }
        }

        bfs(1);
        lca_init(n);
        scanf("%d",&m);
        printf("Case %d:\n",++k);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",lca_query(n,a,b));
        }
    }










return 0;
}
