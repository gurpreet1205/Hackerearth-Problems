#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j,k,l,a[1000001]={0},m=0,c;
	cin>>n;
	string s[n];
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<n;i++)
	{
		l=s[i].length();
		m=max(m,l);
		for(j=0;j<l;j++)
		{
			if(s[i][j]=='1')
				a[j]=1;
		}
	}
	c=0;
	for(i=0;i<m;i++)
	{
		if(a[i]==1)
			c++;
	}
	if(c%2==0)
		cout<<"B\n";
	else
		cout<<"A\n";
	cout<<c<<"\n";
	return 0;
}