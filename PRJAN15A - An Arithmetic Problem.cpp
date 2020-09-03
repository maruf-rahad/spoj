#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,c,d,i,j,x,y,t,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("Case %d: ",++k);
        if(b-a!=c-b)
        {
            printf("Error\n");
        }
        else printf("%d\n",(b-a)*(d-1)+a);
    }













return 0;
}
