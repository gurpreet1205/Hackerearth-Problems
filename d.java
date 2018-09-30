import java.io.*;
import java.util.*;
class d
{
	public static void main(String args[])throws IOException
	{
		int i,j=0,m,r=0,c=0,k;
		String s,ss;
		String[] str=new String[10];
		Scanner sc=new Scanner(System.in);
		s=sc.next();
		for(i=0;i<10;i++){
			str[i]="";
		}
		for(i=0;i<s.length();i++){
			if(s.charAt(i)==','){
				j++;
			}
			else
				str[j]=str[j]+s.charAt(i);
		}
		j++;
		m=j;
		double d[][]=new double[m][m];
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				d[i][j]=0;
			}
		}
		sc.nextLine();
		for(i=0;i<m-1;i++){
			String str1="",str2="";
			ss=sc.nextLine();
			j=0;
			while(ss.charAt(j)!=' '){
				str1=str1+ss.charAt(j);
				j++;
			}
			for(k=0;k<m;k++){
				if(str1.equals(str[k])){
					r=k;
					break;
				}
			}
			
			j=j+3;
			int num=0;
			while(ss.charAt(j)!=' '){
				num=num*10+(int)(ss.charAt(j)-'0');
				j++;
			}
			j++;
			for(;j<ss.length();j++){
				str2=str2+ss.charAt(j);
			}
			for(k=0;k<m;k++){
				if(str2.equals(str[k])){
					c=k;
					break;
				}
			}
			d[r][c]=num;
			d[c][r]=1.0/num;
		}
		d[0][0]=1;
		c=0;
		for(i=0;i<m;i++){
			if(d[0][i]==0)
				c++;
		}
		while(c>0){
			for(i=1;i<m;i++){
				if(d[0][i]!=0){
					for(j=0;j<m;j++){
						if(d[i][j]!=0){
							if(d[0][j]==0){
								d[0][j]=d[0][i]*d[i][j];
								c--;
							}
						}
					}	
				}
			}
		}
		double min=10000000;
		for(i=0;i<m;i++){
			if(min>d[0][i])
				min=d[0][i];
		}
		double x=1.0/min;
		int[] y=new int[m];
		int[] z=new int[m];
		for(i=0;i<m;i++){
			y[i]=(int)(d[0][i]*x);
			z[i]=i;
		}
		int temp;
		for(i=0;i<m;i++){
			for(j=0;j<m-1;j++){
				if(y[j]>y[j+1]){
					temp=y[j];
					y[j]=y[j+1];
					y[j+1]=temp;
					temp=z[j];
					z[j]=z[j+1];
					z[j+1]=temp;
				}
			}
		}
		for(i=0;i<m;i++){
			System.out.print(y[i]);
			System.out.print(str[z[i]]);
			if(i!=m-1)
				System.out.print(" = ");
		}
	}
}