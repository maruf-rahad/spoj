#include<bits/stdc++.h>
using namespace std;
set<char>st;
set<char> :: iterator it;
vector<int>v;
int main()
{
    int n,m,a,b,c,d,i,j,x,y,t,k=0;
        string s;
    scanf("%d",&t);
    while(t--)
    {
        st.clear();
        v.clear();

        cin>>s;
        for(i=0;i<s.size();i++)
        {
            st.insert(s[i]);
        }
        x = 0;
        for(it = st.begin();it!=st.end();it++)
        {
            x+=*it;
        }
      while(x!=0)
      {
          a = x%2;
          v.push_back(a);
          x/=2;
      }
      printf("#%d : ",++k);
      for(i=v.size()-1;i>=0;i--)
      {
          printf("%d",v[i]);
      }
      printf("\n");

    }













return 0;
}
