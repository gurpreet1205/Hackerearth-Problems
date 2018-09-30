#include<bits/stdc++.h>
using namespace std;
void mergesort(long long int *a,long long int n,long long int *c,string *s)
{
    long long int b[n],d[n];
    string e[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,s);
    mergesort(a+x,n-x,c+x,s+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]<a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=s[j];
            j++;
        }
        else if(a[i]==a[j]&&c[i]>c[j])
        {
        	b[k]=a[j];
            d[k]=c[j];
            e[k]=s[j];
            j++;
        }
        else if(a[i]==a[j]&&c[i]==c[j]&&s[i]<s[j])
        {
        	b[k]=a[j];
            d[k]=c[j];
            e[k]=s[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=s[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            d[k]=c[j];
            e[k]=s[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            d[k]=c[i];
            e[k]=s[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        s[i]=e[i];
    }
}
int main()
{
	long long int t,n,k,i,j,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n],b[n];
		string s[n];
		for(i=0;i<n;i++)
		{
			cin>>s[i]>>a[i]>>b[i];
		}
		cin>>k;
		mergesort(a,n,b,s);
		cout<<s[k-1]<<" "<<a[k-1]<<"\n";
	}
	return 0;
}