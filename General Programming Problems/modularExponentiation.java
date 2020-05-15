import java.io.IOException;
import java.util.Scanner;
class modularExponentiation{
    static  long mod = (long) (1e9+7);
    public static void main(String args[])throws IOException{
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0){
            long a= sc.nextLong();
            long b= sc.nextLong();
            System.out.println(expn(a,b,mod));
        }
    }
    static long expn(long x , long n , long m){
        if(n==1)
            return (int) (x%m);
        else if(n==0)
            return  1;
        else if(n%2==0) {
            long y= expn(x, n / 2, m);
            return ((y*y) % m);
        }
        else
            return  ((expn(x,1,m)*expn(x,n-1,m))%m);
    }
}