#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j,k,m,x,y,z;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2!=0)
			cout<<"-1\n";
		else if(n%4==0)
		{
			x=n/4;
			cout<<x*x*x*x<<"\n";
		}
		else
		{
			long long int a[n];
			j=0,m=-1;
			for(i=1;i*i<=n;i++)
			{
				if(n%i==0)
				{
					a[j++]=i;
					a[j++]=n/i;
				}
			}
			sort(a,a+j,greater<int>());
			x=n/2;
			if(n%3==0)
			{
				y=n/3;
				z=n-(x+y);
				for(i=0;i<j;i++)
				{
					if(a[i]>=z)
						continue;
					if(a[i]+a[i]<z)
						break;
					for(k=i;k<j;k++)
					{
						if(a[i]+a[k]==z)
						{
							m=max(x*y*a[i]*a[k],m);
							//cout<<x<<" "<<y<<" "<<a[i]<<" "<<a[k]<<" "<<m<<"\n";
						}
						if(a[i]+a[k]<z)
							break;
					}
				}
			}
			if(n%5==0)
			{
				y=n/5;
				z=n-(x+y);
				for(i=0;i<j;i++)
				{
					if(a[i]>=z)
						continue;
					if(a[i]+a[i]<z)
						break;
					for(k=i;k<j;k++)
					{
						if(a[i]+a[k]==z)
						{
							m=max(x*y*a[i]*a[k],m);
							//cout<<x<<" "<<y<<" "<<a[i]<<" "<<a[k]<<" "<<m<<"\n";
						}
						if(a[i]+a[k]<z)
							break;
					}
				}
			}
			if(n%6==0)
			{
				y=n/6;
				m=max(x*y*y*y,m);
				//cout<<x<<" "<<y<<" "<<y<<" "<<y<<" "<<m<<"\n";
			}
			if(n%3==0)
			{
				x=n/3;
				z=n-(x+x);
				for(i=0;i<j;i++)
				{
					if(a[i]>=z)
						continue;
					if(a[i]+a[i]<z)
						break;
					for(k=i;k<j;k++)
					{
						if(a[i]+a[k]==z)
						{
							m=max(x*x*a[i]*a[k],m);
							//cout<<x<<" "<<x<<" "<<a[i]<<" "<<a[k]<<" "<<m<<"\n";
						}
						if(a[i]+a[k]<z)
							break;
					}
				}
			}
			cout<<m<<"\n";
		}
	}
	return 0;
}