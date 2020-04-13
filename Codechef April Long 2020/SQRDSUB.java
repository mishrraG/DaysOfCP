//Question Link : https://www.codechef.com/APRIL20B/problems/SQRDSUB
import java.io.*;
import java.util.Scanner;

class SQRDSUB {
    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        int t=sc.nextInt();
        while(t-->0){
            int l=sc.nextInt();
            long[] arr=new long[l];
            for(int i=0;i<l;i++){
                arr[i]=sc.nextInt();
            }
            long n=0l;
            n=(long)l;
            for(int i=0;i<n;i++){
                if(arr[i]%4==0){
                    arr[i]=4;
                }
                else if(arr[i]%2==0){
                    arr[i]=2;
                }
            }
            long count=0;
            int i1=0;
            long n1=0l;
            int i2=0;
            if(arr[0]==2){
                n1=0;
                i1=0;
            }
            else if(arr[0]==4){
                n1=0;
                i1=0;
                count+=n;
            }
            else{
                int p=0;
                while(p!=n && arr[p]!=2 && arr[p]!=4){
                    p++;
                }

                i1=p;
                n1=p;
                if(p!=n && arr[p]==4){
                    count+=(n-p)*(p+1);
                }
            }
            count+=(n1*(n1+1))/2;
            if(i1!=n && arr[i1]==4) {
                n1 = 0;
            }
            for(int i=i1+1;i<n;){
                i2=i;
//               System.out.println(count);
                while(i2<n && arr[i2]!=2 && arr[i2]!=4){
                    i2++;
                }
                if(i2==n){
                    break;
                }
                count+=((long)(i2-i1-1)*(i2-i1))/2;
                if(arr[i1]==2 && arr[i2]==2){
                    if(n1!=0)
                        count+=(n-i2)*(1+n1);
                    else count+=(n-i2);
                    n1=i2-i1-1;
                }
                else if(arr[i1]==2 && arr[i2]==4){
                    if(n1==0 && (i2-i1-1)==0)
                        count+=(n-i2)*2;
                    else if(n1==0 && (i2-i1-1)!=0)
                        count+=(n-i2)*(2+(i2-i1-1));
                    else if(n1!=0 && (i2-i1-1)!=0)
                        count+=(n-i2)*(2+n1+(i2-i1-1));
                    else count+=(n-i2)*(2+n1);
                    n1=0;
                }
                else if(arr[i1]==4 && arr[i2]==4){
                    if(i2-i1-1!=0)
                        count+=(n-i2)*(1+i2-i1-1);
                    else count+=n-i2;
                    n1=0;

                }
                else if(arr[i1]==4 && arr[i2]==2)
                    n1=i2-i1-1;
                i1=i2;
                i=i1+1;
            }
            count+=((n-i1-1)*(n-i1))/2;
            bw.append(count+"\n");
        }
        bw.close();
    }
}