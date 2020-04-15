//Question Link : https://www.spoj.com/problems/AMR11E/
import java.util.*;
public class LuckyNum
{
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int p=0;p<t;p++)
        {
            int N=sc.nextInt();
            int counter=0;
            int k=30; //first lucky number
            while(counter!=N)
            {
                //Sieve of Eratosthenes implementation
                boolean[]arr=new boolean[k+1];
                Arrays.fill(arr,true);
                arr[0]=arr[1]=false;
                for(int i=2;i<=Math.sqrt(k);i++)
                {
                    if(arr[i]==true)
                        for(int j=i*i;j<arr.length;j+=i)
                        {
                            arr[j]=false;
                        }
                }
                //Now that we have all the prime numbers in an array of primes , we start calculating lucky numbers
                int count=0;
                for(int q=2;q<arr.length;q++)
                {
                    if(arr[q]==true)
                        if(k%q==0)
                            ++count;
                }
                if(count>=3)
                {
                    ++counter;
                    if(counter==N)
                        break;
                }
                ++k;
            }
            System.out.println(k);
        }
    }
}