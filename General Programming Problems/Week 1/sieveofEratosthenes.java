import java.io.*;
import java.util.*;
class SieveOwn {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        br.close();
        boolean[] arr = new boolean[N + 1];
        Arrays.fill(arr, true);
        arr[0] = arr[1] = false;
        for (int i = 2; i <= Math.sqrt(N); i++) {
            if (arr[i])
                for (int j = i * i; j < arr.length; j += i) {
                    arr[j] = false;
                }
        }
        for (int q = 2; q < arr.length; q++) {
            if (arr[q]){
                System.out.println(q);
            }
        }
    }
}