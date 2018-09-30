#include<bits/stdc++.h>
using namespace std;
string s,d,x[20];
vector<pair<long long int,long long int> > v[20];
long long int ss,dd,visited[20]={0},z=0,c[100]={0};
vector<string> vec[100];
void dfs(long long int y)
{
    if(visited[y]==1)
        return;
    if(y==dd)
    {
        vec[z].push_back(x[y]);
        z++;
        vec[z]=vec[z-1];
        c[z]=c[z-1];
        return;
    }
    vec[z].push_back(x[y]);
    visited[y]=1;
    long long int i,l=v[y].size();
    for(i=0;i<l;i++)
    {
        c[z]=c[z]+v[y][i].second;
        dfs(v[y][i].first);
        c[z]=c[z]-v[y][i].second;
        vec[z].pop_back();
    }
}
int main()
{
    long long int n,i=0,j,w,temp,k;
    string U,V;
    vector<string> vs;
    cin>>s>>d;
    while(cin>>U>>V>>w;)
    {
        for(j=0;j<i;j++)
        {
            if(x[j]==U)
                break;
        }
        if(j==i)
        {
            x[i++]=U;
        }
        for(k=0;k<i;k++)
        {
            if(x[k]==V)
                break;
        }
        if(k==i)
        {
            x[i++]=V;
        }
        v[j].push_back(make_pair(k,w));
    }
    for(j=0;j<i;j++)
    {
        if(x[j]==s)
            ss=j;
        if(x[j]==d)
            dd=j;
    }
    dfs(ss);
    for(i=0;i<z;i++)
    {
        for(j=0;j<z-1;j++)
        {
            if(c[j]>c[j+1])
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
                vs=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=vs;
            }
            else if(c[j]==c[j+1])
            {
                if(vec[j].size()>vec[j+1].size())
                {
                    temp=c[j];
                    c[j]=c[j+1];
                    c[j+1]=temp;
                    vs=vec[j];
                    vec[j]=vec[j+1];
                    vec[j+1]=vs;
                }
                else if(vec[j].size()==vec[j+1].size())
                {
                    for(k=0;k<vec[j].size();k++)
                    {
                        if(vec[j][k]>vec[j+1][k])
                        {
                            temp=c[j];
                            c[j]=c[j+1];
                            c[j+1]=temp;
                            vs=vec[j];
                            vec[j]=vec[j+1];
                            vec[j+1]=vs;
                            break;
                        }
                        else if(vec[j][k]<vec[j+1][k])
                            break;
                    }
                }
            }
        }
    }
    for(i=0;i<z;i++)
    {
        for(j=0;j<vec[i].size();j++)
            cout<<vec[i][j]<<" ";
        cout<<c[i]<<"\n";
    }
    return 0;
}