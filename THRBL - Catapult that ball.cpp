#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[50100];
ll sparse[50050][18];
ll n;

ll powi(ll x,ll y)
{
    ll sum = 1;
    for(ll i=1; i<=y; i++)
    {
        sum=sum*x;
    }
    return sum;
}
void process()
{
    for(ll i=0;i<n;i++)
    {
        sparse[i][0] = i;
    }

    for(ll j=1;powi(2,j)<n;j++)
    {
        for(ll i=0;i+powi(2,j)-1<n;i++)
        {
            if(ara[sparse[i][j-1]]>ara[sparse[i+powi(2,j-1)][j-1]])
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

ll query(ll low,ll high)
{
    ll l = high-low+1;
    ll k = log2(l);

    return max(ara[sparse[low][k]],ara[sparse[low+l-powi(2,k)][k]]);
}
int main()
{
    ll m,a,b,i,j,x,y,sum=0;

    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&ara[i]);
    }
    process();
    for(i=1; i<=m; i++)
    {
        scanf("%lld %lld",&a,&b);

        int x = query(a-1,b-2);
        if(x==ara[a-1])
        {
            sum++;
        }

    }
    printf("%lld\n",sum);












    return 0;
}
