#include<bits/stdc++.h>
using namespace std;
void mergesort(long long int *a,long long int n,long long int *c,long long int *e)
{
    long long int b[n],d[n],g[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,e);
    mergesort(a+x,n-x,c+x,e+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            g[k]=e[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            g[k]=e[i];
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
            g[k]=e[j];
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
            g[k]=e[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        e[i]=g[i];
    }
}
int main()
{
	long long int n,m,c,k,i,j;
	cin>>n>>m>>c>>k;
	long long int u[m],v[m],w[m],ru[c],rv[c];
	long long int a[n]={0};
	for(i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		a[u[i]-1]++;
		a[v[i]-1]++;
	}
	mergesort(w,m,u,v);
	for(i=0,j=0;i<m&&j<c;i++)
	{
		if(a[u[i]]>1&&a[v[i]]>1)
		{
			ru[j]=u[i];
			rv[j]=v[i];
			a[u[i]-1]--;
			a[v[i]-1]--;
			j++;
		}
	}
	for(i=0;i<c;i++)
		cout<<ru[i]<<" "<<rv[i]<<"\n";
	return 0;
}