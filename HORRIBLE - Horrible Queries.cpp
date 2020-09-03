#include<bits/stdc++.h>
using namespace std;

#define mx 100005

#define ll long long

struct segment
{
    ll sum,prop;
};
segment tree[mx*4];

void zero(ll n)
{
    for(ll i=0; i<=4*n+3; i++)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
    }
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(b>j||e<i)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }

    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum = tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;

}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    if(b>j||e<i)
        return 0;

        if(b>=i&&e<=j)
        {
            return tree[node].sum+(e-b+1)*carry;
        }
        ll left = node*2;
        ll right = node*2+1;

        ll mid = (b+e)/2;

        ll r1 = query(left,b,mid,i,j,carry+tree[node].prop);
        ll r2 = query(right,mid+1,e,i,j,carry+tree[node].prop);

        return r1+r2;


}
int main()
{
    //freopen("output.txt","w",stdout);
    ll n,m,i,j,a,b,y,t,mark,x,k=0;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        zero(n);

        for(i=1; i<=m; i++)
        {
            scanf("%lld",&mark);

            if(mark==0)
            {
                scanf("%lld %lld %lld",&a,&b,&x);
                update(1,1,n,a,b,x);

            }
            else
            {
                scanf("%lld %lld",&a,&b);
              ll total =  query(1,1,n,a,b,0);
               printf("%lld\n",total);
            }

        }



    }









    return 0;
}
