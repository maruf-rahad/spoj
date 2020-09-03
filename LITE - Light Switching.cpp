#include<bits/stdc++.h>
using namespace std;

#define mx 100005
struct segment
{
    int sum,prop;
};
segment tree[mx*4];

void zero(int n)
{
    for(int i = 0 ; i<=n*4+3 ; i++)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
    }
}

void update(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].sum = (e-b+1)-tree[node].sum;
        tree[node].prop+=1;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    if(tree[node].prop%2==0)
    {
        tree[node].sum = tree[left].sum+tree[right].sum;
    }
    else{
        tree[node].sum = (e-b+1)-(tree[left].sum+tree[right].sum);
    }
}
int query(int node,int b,int e,int i,int j,int carry)
{
    if(b>j||e<i)
        return 0;

    if(b>=i&&e<=j)
    {
        if(carry%2==0)
        {
            return tree[node].sum;
        }
        else{
            return ((e-b+1)-tree[node].sum);
        }
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int r1 = query(left,b,mid,i,j,carry+tree[node].prop);
    int r2 = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return r1+r2;
}
int main()
{
    int n,m,i,j,a,b,x,y,mark;

    scanf("%d %d",&n,&m);

    zero(n);

    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&mark,&a,&b);

        if(mark==0)
        {
            update(1,1,n,a,b);
          /*  for(j=1;j<=m;j++)
            {
                printf("%d %d  %d\n",j,tree[j].prop,tree[j].sum);
            }*/
        }
        else{
            x = query(1,1,n,a,b,0);
            printf("%d\n",x);
        }
    }


































return 0;
}
