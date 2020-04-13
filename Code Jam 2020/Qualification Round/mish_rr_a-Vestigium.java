import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Solution {
   static Scanner sc =new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int n=sc.nextInt();
        int c=1;
        while (c<=n) {
            exec(c);
            c++;
        }
    }
    static void exec(int c) throws IOException {
        int p=sc.nextInt();
        int arr[][]=new int[p][p];
        int s=0;
        for(int i=0;i<p;i++)
        {
            for (int j=0;j<p;j++)
            {
                arr[i][j]=sc.nextInt();
                if(i==j)
                    s+=arr[i][j];
            }
        }
        int cr=0;
        Integer temp[] = new Integer[p];
        for (int i=0;i<p;i++)
        {
            for (int j=0;j<p;j++) {
                temp[j] = arr[i][j];
            }
            if (areDistinct(temp)==false)
                cr++;
        }
        int cc=0;
        for (int i=0;i<p;i++)
        {
            for (int j=0;j<p;j++) {
                temp[j] = arr[j][i];
            }
            if (!areDistinct(temp))
                cc++;
        }
        System.out.println("Case #"+c+": "+s+" "+cr+" "+cc);

    }
    public static boolean areDistinct(Integer arr[])
    {
        // Put all array elements in a HashSet
        Set<Integer> s =
                new HashSet<Integer>(Arrays.asList(arr));

        // If all elements are distinct, size of
        // HashSet should be same array.
        return (s.size() == arr.length);
    }
}
