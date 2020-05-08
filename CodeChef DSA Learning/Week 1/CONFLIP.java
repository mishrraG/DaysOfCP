import java.lang.*;
import java.io.*;
class CONFLIP
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T > 0){
            int G = Integer.parseInt(br.readLine());
            while(G > 0){
                String[] str = br.readLine().split(" ");
                int N = Integer.parseInt(str[1]);
                if(N%2==0){
                    System.out.println(N/2);
                }else{
                    if(str[0].equals("1") && str[2].equals("1")){
                        System.out.println(N/2);
                    }else if(str[0].equals("1") && str[2].equals("2")){
                        System.out.println(N/2 + 1);
                    }else if(str[0].equals("2") && str[2].equals("1")){
                        System.out.println(N/2 + 1);
                    }else if(str[0].equals("2") && str[2].equals("2")){
                        System.out.println(N/2);
                    }
                }
                G--;
            }
            T--;
        }
    }
}