import java.util.*;
class MULTHREE
{
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(;t>0;t--)
        {
            long k=sc.nextLong();
            int d0=sc.nextInt();
            int d1=sc.nextInt();
            int s=(d0+d1);
            int three=s%10;
            if(k==2)
            {
                if(s%3==0)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
            else
            {
                long freq=(k-3)/4;
                int rem=(int)((k-3)-freq*4);
                int cycle=(2*three)%10+(4*three)%10+(8*three)%10+(6*three)%10;
                int remsum=0,temp=2;
                for(int i=0;i<rem;i++,temp*=2)
                    remsum+=(temp*three)%10;
                long fin=(s+three+freq*cycle*1l+remsum);
                if(fin%3==0)
                    System.out.println("YES");
                else
                    System.out.println("NO");


            }
        }
    }
}