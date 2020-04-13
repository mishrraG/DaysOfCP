import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.*;

class CandidateCode {

    public static void main(String[] args) throws IOException {
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0){
            int N = sc.nextInt();
            int[] arr1 = new int[N];
            for(int i=0 ; i<N; i++)
                arr1[i] = sc.nextInt();
            int arr2[] = new int[N];
            for(int i=0 ; i<N ; i++)
                arr2[i] = sc.nextInt();
            Arrays.sort(arr1);
            Arrays.sort(arr2);
            int i=N-1;
            int j = N-1;
            int answer=0;
            while(i>=0 && j>=0) {
                if(arr1[i]>arr2[j]) {
                    answer++;
                    i--;
                    j--;
                }else {
                    j--;
                }
            }
            log.write(answer +"\n");
            log.flush();

            T--;
        }
        sc.close();

    }

}