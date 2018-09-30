#include<bits/stdc++.h>
using namespace std;
void mergesort(long long int *a,long long int n,long long int *c)
{
    long long int b[n],d[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c);
    mergesort(a+x,n-x,c+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
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
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
    }
}
int main()
{
    long long int s,x,n,i,j,k,a,c,z,flag=0;
    cin>>s>>x>>n;
    long long int t[n],y[n];
    double b;
    for(i=0;i<n;i++)
        cin>>t[i]>>y[i];
    mergesort(t,n,y);
    i=0,a=0,z=0;
    while(i<n)
    {
    	a=a+(t[i]-z-1)*x;
    	if(a>=s)
    	{
    		a=a-(t[i]-z-1)*x;
    		b=s-a;
    		if(i==0)
    			c=ceil(b/x);
    		else
    			c=t[i-1]+ceil(b/x);
    		break;
    	}
    	a=a+y[i];
    	if(a>=s)
    	{
    		flag=1;
    		break;
    	}
    	z=t[i];
    	i++;
    }
    if(i==n)
    {
    	b=s-a;
    	if(i==0)
    		c=ceil(b/x);
    	else
    		c=t[i-1]+ceil(b/x);
    }
    else
    {
    	if(flag==1)
    		c=t[i];
    }
    cout<<c<<"\n";
    return 0;
}