#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
struct segment{
    int one,two,three,sum,prop;
};
segment tree[mx*4];

void zero(int n)
{
    for(int i=0;i<=(n*4)+3;i++)
    {
        tree[i].one = 0;
        tree[i].two = 0;
        tree[i].three = 0;
        tree[i].sum  = 0;
        tree[i].prop = 0;
    }
}

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].three = 1;
        tree[node].sum = 1;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].three = tree[left].three+tree[right].three;
}

void update(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].prop+=1;
        int x = tree[node].three;
        tree[node].three = tree[node].two;
        tree[node].two = tree[node].one;
        tree[node].one =  x;
        tree[node].sum = tree[node].three;
        return;
    }

   // printf("yes %d %d %d %d %d\n",node,b,e,i,j);
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    int x = tree[node].prop%3;

    if(x==0)
    {
        tree[node].sum = tree[left].sum+tree[right].sum;
        tree[node].three = tree[left].three+tree[right].three;
        tree[node].two = tree[left].two+tree[right].two;
        tree[node].one = tree[left].one+tree[right].one;
    }
    else if(x==1)
    {
        tree[node].sum = tree[left].two+tree[right].two;
        tree[node].three = tree[left].two+tree[right].two;
        tree[node].two = tree[left].one+tree[right].one;
        tree[node].one = tree[left].three+tree[right].three;
    }
    if(x==2)
    {
        tree[node].sum =  tree[left].one+tree[right].one;
        tree[node].three = tree[left].one + tree[right].one;
        tree[node].two = tree[left].three+tree[right].three;
        tree[node].one = tree[left].two + tree[right].two;
    }
}

int query(int node,int b,int e,int i,int j,int carry)
{
    if(b>j||e<i)
        return 0;
    if(b>=i&&e<=j)
    {
        int x = carry%3;
        if(x==0)
        {
            return tree[node].three;
        }
        else if(x==1)
        {
            return tree[node].two;
        }
        else if(x==2)
        {
            return tree[node].one;
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
    int n,a,b,i,j,x,y,t,m,k=0;

        scanf("%d %d",&n,&m);
        zero(n);

        zero(n);
        init(1,1,n);

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&x,&a,&b);
            if(x==0)
            {
                update(1,1,n,a+1,b+1);
            }
            else{

                x = query(1,1,n,a+1,b+1,0);
                printf("%d\n",x);
            }
        }
    return 0;
}
