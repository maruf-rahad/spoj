#include<bits/stdc++.h>
using namespace std;
int ara[100010];
int sparse[100010][17];
int n;

int powi(int x,int m)
{
    int sum = 1;
    for(int i=1;i<=m;i++)
    {
        sum = sum*x;
    }
    return sum;
}
void process()
{
    for(int i=0;i<n;i++)
    {
        sparse[i][0] = i;
    }

    for(int j=1;powi(2,j)<=n;j++)
    {
        for(int i=0;i+powi(2,j)-1<n;i++)
        {
            if(ara[sparse[i][j-1]]<ara[sparse[i+powi(2,j-1)][j-1]])
            {
                sparse[i][j] = sparse[i][j-1];
            }
            else
            {
                sparse[i][j] = sparse[i+powi(2,j-1)][j-1];
            }
        }
    }
}

int query(int low,int high)
{
    int l = high-low+1;
    int k = log2(l);

    return min(ara[sparse[low][k]],ara[sparse[low+l-powi(2,k)][k]]);
}
int main()
{
    int a,b,i,j,x,y,m;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    process();

    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&a,&b);

        printf("%d\n",query(a,b));

    }











return 0;
}
