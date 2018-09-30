#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,a,b,x,y,n,c,c1;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		x=(b*n)/(a+b);
		y=n-x;
		c=a*x*x+b*y*y;
		if(x<n)
		{
			x=x+1;
			y=y-1;
			c1=a*x*x+b*y*y;
			if(c1<c)
				c=c1;
		}
		cout<<c<<"\n";
	}
	return 0;
}