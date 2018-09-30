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
	long long int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int s[n],e[n],a[n],x=-1,y,a1=0,a2=0;
		for(i=0;i<n;i++)
		{
			cin>>s[i]>>e[i];
			a[i]=0;
		}
		mergesort(e,n,s);
		j=1;
		while(true)
		{
			y=0;
			x=-1;
			for(i=0;i<n;i++)
			{
				if(s[i]>x&&a[i]==0)
				{
					a[i]=1;
					x=e[i];
					y++;
				}
			}
			if(y==0)
				break;
			if(j%2==0)
				a2=a2^y;
			else
				a1=a1^y;
			j++;
		}
		//cout<<a1<<" "<<a2<<"\n";
		if(a1>a2)
			cout<<"Alice\n";
		else if(a1<a2)
			cout<<"Bob\n";
		else
			cout<<"Tie\n";
	}
	return 0;
}