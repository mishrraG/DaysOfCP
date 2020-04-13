import java.io.*;
import java.util.*;
public class CandidateCode {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
long min=0;
String ing = br.readLine();
int ingnumb=Integer.parseInt(ing);//no of ingredients
String  lines = br.readLine();    
String[] strs = lines.trim().split("\\s+");
long a[]=new long[strs.length];
for (int i = 0; i < strs.length; i++)//quantity of each to create a powerpuff girl
{
a[i] = Long.parseLong(strs[i]);
//System.out.println(a[i]);
}
String quant = br.readLine();
String[] strs1 = quant.trim().split("\\s+");
long b[]=new long[strs.length];
for (int i = 0; i < strs1.length; i++)//quanitity of each available
{
b[i] = Long.parseLong(strs1[i]);
//System.out.println(b[i]);
}
double tempdiv[]=new double[ingnumb];
for (int i=0;i<ingnumb;i++)
{
if(a[i]==0)
{
tempdiv[i]=0;
}
else
{
tempdiv[i]=b[i]/a[i];
}
}
Arrays.sort(tempdiv);
min=(long)tempdiv[0];
System.out.println(min);
}

   }