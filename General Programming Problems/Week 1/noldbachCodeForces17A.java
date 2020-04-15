// Question Link : http://codeforces.com/problemset/problem/17/A
import java.util.Arrays;
import java.util.Scanner;

public class NoldBach {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            int n=sc.nextInt();
            int k=sc.nextInt();
            boolean[]arr=new boolean[n+1];
            Arrays.fill(arr,true);
            arr[0]=arr[1]=false;
            for(int i=2;i<=Math.sqrt(n);i++)
            {
                if(arr[i]==true)
                    for(int j=i*i;j<arr.length;j+=i)
                    {
                        arr[j]=false;
                    }
            }
            for(int i=2;i<n;i++){
                if (arr[i] && arr[n-i-1])
                    k--;
            }
            if(k<=0)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }