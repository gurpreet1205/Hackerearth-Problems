#include<bits/stdc++.h>
using namespace std;
void mergesort(string *a,long long int n,long long int *c)
{
    long long int e[n];
    string b[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c);
    mergesort(a+x,n-x,c+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i].compare(a[j])>0)
        {
            b[k]=a[j];
            e[k]=c[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            e[k]=c[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            e[k]=c[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            e[k]=c[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=e[i];
    }
}
void mergesort(long long int *a,long long int n,long long int *c,string *d)
{
    long long int b[n],e[n];
    string f[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,d);
    mergesort(a+x,n-x,c+x,d+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]<a[j]||(a[i]==a[j]&&c[i]>c[j]))
        {
            b[k]=a[j];
            e[k]=c[j];
            f[k]=d[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            e[k]=c[i];
            f[k]=d[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            e[k]=c[j];
            f[k]=d[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            e[k]=c[i];
            f[k]=d[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=e[i];
        d[i]=f[i];
    }
}
int main()
{
	long long int n,i,j,k,c;
	cin>>n;
	string s[n];
	string str[n];
	long long int t[n],tt[n],ts[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i]>>t[i];
	}
	mergesort(s,n,t);
	//for(i=0;i<n;i++)
	//	cout<<s[i]<<" "<<t[i]<<"\n";
	str[0]=s[0],ts[0]=1,tt[0]=t[0];
	j=0;
	for(i=0;i<n-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			//cout<<s[i]<<" "<<s[i+1]<<"\n";
			str[++j]=s[i+1];
			ts[j]=1;
			tt[j]=t[i+1];
		}
		else
		{
			ts[j]++;
			tt[j]+=t[i+1];
		}
	}
	//for(i=0;i<j+1;i++)
	//	cout<<str[i]<<" "<<ts[i]<<" "<<tt[i]<<"\n";
	mergesort(ts,j+1,tt,str);
	for(i=0;i<j+1;i++)
		cout<<i+1<<" "<<str[i]<<"\n";
	return 0;
}