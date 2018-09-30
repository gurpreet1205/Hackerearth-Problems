import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.Integer;

class TestClass {

    public static List list = new ArrayList();
    public static List l1 = new ArrayList();
    public static List l2 = new ArrayList();
    public static int maxfrequency=0,minfrequency=0,max=0,min=0;
    public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(tk.nextToken());
            if (type == 1) {
                int val = Integer.parseInt(tk.nextToken());
                add_to_list(val);
            }
            else if (type == 2) {
                int val = Integer.parseInt(tk.nextToken());
                remove_from_list(val);
            }
            else if (type == 3) {
                int ans = find_least_frequency();
                System.out.println(ans);
            }
            else if (type == 4){
                int ans = find_highest_frequency();
                System.out.println(ans);
            }
        }
    }
    public static void add_to_list(int val){
        int l = list.indexOf(val);
        if(l==-1){
            l1.add(0,val);
            l2.add(0,1);
            l=0;
        }
        else {
            l2.set(l,(int)(l2.get(l))+1);
        }
        list.add(0,val);
        /*int m = l2.get(l);
        if(m>maxfrequency){
            maxfrequency=m;
            min=l1.get(l);
        }
        if(m==maxfrequency){
            if(l1.get(l)<min){
                min=l1.get(l);
            }
        }
        if(m<minfrequency){
            minfrequency=m;
            max=l1.get(l);
        }
        if(m==minfrequency){
            if(l1.get(l)>max){
                max=l1.get(l);
            }
        }*/
        //Process queries of type 1 here

    }

    public static void remove_from_list(int val){
        int l = list.indexOf(val);
        if(l!=-1){
            list.remove(l);
            l=l1.indexOf(val);
            int x = (int)(l2.get(l));
            l2.set(l,x-1);
            /*if(x==maxfrequency&&min==val){
                maxfrequency-=1;
                int s = l2.size();
                for(int i=0;i<s;i++){
                    if(l2.get(i)>x)
                }
            }*/
        }
        //Process queries of type 2 here
    }

    public static int find_least_frequency(){
        if(list.size()==0){
            return -1;
        }
        else {
            int s = l2.size();
            for(int i=0;i<s;i++){
                int x = (int)(l2.get(i));
                if(x<minfrequency){
                    minfrequency=x;
                    max=(int)(l1.get(i));
                }
                if(x==minfrequency){
                    int m=(int)(l1.get(i));
                    if(max<m){
                        max=m;
                    }
                }
            }
            return minfrequency;
        }
        
        //Process queries of type 3 here
    }

    public static int find_highest_frequency(){
        if(list.size()==0){
            return -1;
        }
        int s = l2.size();
        for(int i=0;i<s;i++){
            int x = (int)(l2.get(i));
            if(x>maxfrequency){
                maxfrequency=x;
                min=(int)(l1.get(i));
            }
            if(x==maxfrequency){
                int m=(int)(l1.get(i));
                if(min>m){
                    min=m;
                }
            }
        }
        return maxfrequency;
        //Process queries of type 4 here
        
    }
}