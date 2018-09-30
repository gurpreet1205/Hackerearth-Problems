#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,d,m,x,a,b,y,z,c,dd,months;
	cin>>t;
	while(t--)
	{
		cin>>d>>a>>m>>b>>x;
		y=x-d;
		if(y<=0)
			cout<<0<<"\n";
		else
		{
			z=a*m+b;
			dd=y/z;
			y=y-dd*z;
			months=dd*(m+1);
			if(y==0)
				cout<<months<<"\n";
			else
			{
				dd=y/a;
				y=y-dd*a;
				months+=dd;
				if(y==0)
					cout<<months<<"\n";
				else
					cout<<months+1<<"\n";
			}
		}
	}
	return 0;
}