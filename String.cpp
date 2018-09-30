#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,a[26]={0},m=0,i;
	string s;
	cin>>n;
	cin>>s;
	for(i=0;i<n;i++)
	{
		a[s[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(m<a[i])
			m=a[i];
	}
	cout<<n-m<<"\n";
	return 0;
}