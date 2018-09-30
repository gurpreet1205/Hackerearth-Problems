#include<bits/stdc++.h>
using namespace std;
struct node{
	long long int key,s;
	double value;
};
void mergesort(struct node *a,long long int n)
{
    struct node b[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x);
    mergesort(a+x,n-x);
    long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i].value>a[j].value||(a[i].value==a[j].value&&a[j].s>a[i].s))
        {
            b[k]=a[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
    }
}
int main()
{
	long long int i,j=0,k,n,q,flag=0;
	double x,y,z,a,m,l,yy,start,end;
	cin>>n>>m>>l>>a;
	double p[n],h[n];
	long long int c[n];
	for(i=0;i<n;i++)
		cin>>p[i]>>h[i];
	struct node var[2*n+1];
	for(i=0;i<n;i++)
	{
		x=h[i]/a;
		var[j].value=p[i]-x;
		var[j].key=i;
		var[j++].s=0;
		var[j].value=p[i]+x;
		var[j].key=i;
		var[j++].s=1;
	}
	mergesort(var,2*n);
	//for(i=0;i<2*n;i++)
	//	cout<<var[i].value<<" "<<var[i].key<<" "<<var[i].s<<"\n";
	if(var[0].value<0||var[2*n-1].value>l)
		cout<<"No\n";
	else
	{
		map <long long int,struct node> mymap;
		map <long long int,struct node>::iterator it;
		x=0;
		for(i=0;i<2*n;i++)
		{
			if(var[i].s==1)
			{
				it=mymap.find(var[i].key);
				mymap.erase(it);
				if(mymap.size()==0)
				{
					end=var[i].value;
					y=(start+end)/2.0;
					z=(y-start)*a;
					//cout<<z<<" "<<y<<" "<<i<<"\n";
					if(z>m)
					{
						flag=1;
						break;
					}
					x=0;
				}
			}
			else
			{
				if(x==0)
				{
					start=var[i].value;
					x=1;
				}
				mymap.insert(pair <long long int,struct node> (var[i].key,var[i]));
			}
		}
		if(flag==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}