#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,k,x,y,z;
    cin>>n;
    long long int a[n],s[n],c=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    s[0]=a[0];
    for(i=1;i<n;i++)
        s[i]=s[i-1]+a[i];
    for(i=0;i<n;i++)
    {
        if(i==0)
            x=0;
        else
            x=s[i-1];
        for(j=i;j<n;j++)
        {
            y=s[j]-x;
            z=pow(y,0.5);
            if(z*z==y)
                c++;
        }
    }
    cout<<c<<"\n";
    return 0;
}