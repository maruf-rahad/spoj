#include<bits/stdc++.h>
using namespace std;
#define F            first
#define S            second
#define PB           push_back
#define MP           make_pair
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF9 2147483647
#define INF18 9223372036854775806
#define ll long long
#define ull unsigned long long
#define nn printf("\n")
#define no printf("NO\n")
#define yes printf("YES\n")
#define pp pair<int,int>
#define ppp pair<int,pp >
#define mapii map<int,int>
#define mapll map<ll,ll>
#define mapsi map<string,int>
#define mapss map<string,string>

char Uplowch(char ch)
{
    if(ch >= 'A' &&  ch <= 'Z')
        ch += 32;
    return ch;
}
char Lowupch(char ch)
{
    if(ch >= 'a' &&  ch <= 'z')
        ch -= 32;
    return ch;
}


int main()
{
    int t,n,m,a,b,i,j,x,y,mx,mn,sum,k=0,flag;

    string s,s2;
    vector<int>v;

    while(cin>>s>>s2)
    {


        n = s.size();
        m = s2.size();
        i = n-1;
        j = m-1;
        a = 0;
        b = 0;
        sum = 0;
        v.clear();
        while(i>=0||j>=0)
        {
            if(i<0)
            {
                a = 0;
            }
            else
            {
                a = s[i]-'0';
            }

            if(j<0)
            {
                b = 0;
            }
            else
            {
                b = s2[j]-'0';
            }
            i--;
            j--;


            v.push_back((a+b+sum)%10);
            sum = (a+b+sum)/10;
        }
        if(sum)
            v.push_back(sum);
        n = v.size();
        flag = 0;
        int flag2 = 0;
        for(i=n-1; i>=0; i--)
        {
            if(flag==0&&v[i]==0)
            {
                continue;
            }
            else{
                flag2 = 1;
                flag = 1;
                printf("%d",v[i]);
            }

        }
        if(flag2==0)
        {
            printf("0");
        }
        printf("\n");

    }

    return 0;
}
