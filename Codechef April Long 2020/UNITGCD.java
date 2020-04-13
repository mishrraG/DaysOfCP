//Question Link : https://www.codechef.com/APRIL20B/problems/UNITGCD
import java.util.*;
class UnitGcd {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t= scan.nextInt();
        while(t-- >0){
            int n= scan.nextInt();
            StringBuffer str = new StringBuffer();
            if(n==1){
                str.append(1+"\n");
                str.append(1+" "+1+"\n");
            }
            else{
                str.append(n/2+"\n");
                if(n%2==0){
                    for(int i=1;i<n;i+=2)
                        str.append(2+" "+i+" "+(i+1)+"\n");
                }
                else{
                    str.append(3+" "+1+" "+2+" "+3+"\n");
                    for(int i=4;i<n;i+=2)
                        str.append(2+" "+i+" "+(i+1)+"\n");

                }
            }

            System.out.print(str);

        }
    }

}