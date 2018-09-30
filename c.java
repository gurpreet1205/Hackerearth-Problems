import java.io.*;
import java.util.*;
class c
{
	public static Vector[] vec = new Vector[100001];
	public static int[] h=new int[100000];
	public static int p=0,q=0,max=0;
	public static void rec(int x,int y){
		int i,j,a,b,flag=0,pp=p,qq=q;
		qq=qq+h[x-1];
			if(pp<qq)
				pp=qq;
			if(qq<0)
				qq=0;
		for(i=0;i<vec[x].size();i++){
			a=(int)(vec[x].get(i));
			if(a!=y){
				p=pp;
				q=qq;
				rec(a,x);
				flag=1;
			}
		}
		if(flag!=1&&max<pp)
			max=pp;
		
	}
	public static void main(String args[])throws IOException
	{
		int i,j,t,n,m;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t-->0){
			n=sc.nextInt();
			for(i=0;i<n;i++){
				h[i]=sc.nextInt();
			}
			m=sc.nextInt();
			int[] u=new int[m];
			int[] v=new int[m];
			int[] a=new int[m];
			for(i=0;i<m;i++)
				u[i]=sc.nextInt();
			for(i=0;i<m;i++)
				v[i]=sc.nextInt();
			for(i=0;i<100001;i++)
				vec[i] = new Vector();
			for(i=0;i<m;i++){
				vec[u[i]].add(v[i]);
				vec[v[i]].add(u[i]);
			}
			rec(1,0);
			System.out.println(max);
		}
	}
}