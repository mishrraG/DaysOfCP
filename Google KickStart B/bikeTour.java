import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class kick {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        int c=1;
        while(t-->0){
            int n=Integer.parseInt(br.readLine());
            int a[]=new int[n];
            String s = br.readLine();
            String x[]=s.split(" ");
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(x[i]);
            }
            int max=a[0];
            int count=0;
            for(int i=1;i<n-1;i++){
                if(a[i]>a[i-1] && a[i]>a[i+1])
                {
                    count+=1;
                }
            }
            System.out.println("Case #"+c++ +": "+count);
        }
    }
}
