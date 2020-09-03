#include<bits/stdc++.h>
using namespace std;
#define mx 10010
vector<pair<int,int> >G[mx];
int sparse[mx][18];
int level[mx];
int parent[mx];
int visited[mx];
int cost[mx];

void zero(int n,int m)
{
    for(int i=0;i<=n+5;i++)
    {
        G[i].clear();
        visited[i] = 0;
        parent[i] = 0;
        level[i] = 0;
        cost[i] = 0;
        for(int j=0;j<=m+2;j++)
        {
            sparse[i][j] = -1;
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
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i].first;
            int c = G[u][i].second;
            if(visited[v]==0)
            {
                visited[v] = 1;
                level[v]  = level[u]+1;
                parent[v] = u;
                cost[v] = cost[u]+c;
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
        if(1<<log>level[p])break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(level[p]-(1<<i)>=level[q])
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

int findd(int n,int p,int sum)
{
    if(sum==0)return p;
    int log = 1;
    while(1)
    {
        if(1<<log>level[p])break;
        log++;
    }
    for(int i=log;i>=0;i--)
    {
        if((1<<i)<=sum&&sum>0)
        {
            sum-=(1<<i);
            p = sparse[p][i];
        }
    }
    return p;
}
int main()
{
    int t,n,m,a,b,c,i,j,x,y;
    string s;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        x = log2(n)+1;
        zero(n,x);

        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        bfs(1);

        lca_init(n);

        while(cin>>s)
        {
            if(s=="DONE")break;
            if(s=="DIST")
            {
                scanf("%d %d",&a,&b);
                x = lca_query(n,a,b);
                printf("%d\n",cost[a]+cost[b]-2*cost[x]);
            }
            else if(s=="KTH")
            {
                scanf("%d %d %d",&a,&b,&c);
                x = lca_query(n,a,b);
                int dist = level[a]-level[x]+1;
                if(dist>=c)
                {
                    y = findd(n,a,c-1);
                    printf("%d\n",y);
                }
                else{
                    c = c-dist;
                    y = findd(n,b,level[b]-level[x]-c);
                    printf("%d\n",y);
                }
            }
        }
        printf("\n");
    }



/*
1
7
1 2 1
1 4 2
1 3 3
3 5 4
3 6 4
3 7 6

*/








return 0;
}
