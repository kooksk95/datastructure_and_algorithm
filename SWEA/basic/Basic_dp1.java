import java.lang.*;
import java.util.Scanner;

/*
    피보나치 수열을 (1)Naive (2)메모제이션 (3)DP로 작성하고 수행시간을 비교하라
    javac Solution1.java -encoding UTF8

   - 수행시간 측정을 위해 다음과 같이 time 명령어를 사용할 수 있습니다.
       time java Solution1
   - 일정 시간 초과시 프로그램을 강제 종료 시키기 위해 다음과 같이 timeout 명령어를 사용할 수 있습니다.
       timeout 0.5 java Solution1   // 0.5초 수행
       timeout 1 java Solution1     // 1초 수행
 */
class Basic_dp1 {

    static long memo[] = new long[20001];
    static long start;
    static long ans1, ans2, ans3;
    static double time1, time2, time3;

    public static void main(String[] args) throws Exception {

        System.out.print("Input : ");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();

        /* Problem 1-1 */
        start = System.currentTimeMillis();
        ans1 = 0; //fib1(num);
        time1 = (System.currentTimeMillis() - start) / 1000.;

        /* Problem 1-2 */
        start = System.currentTimeMillis();
        fib2(num);
        ans2 = memo[num];
        time2 = (System.currentTimeMillis() - start) / 1000.;

        /* Problem 1-3 */
        start = System.currentTimeMillis();
        ans3 = fib3(num);
        time3 = (System.currentTimeMillis() - start) / 1000.;

        System.out.println(ans1 + " " + ans2 + " " + ans3);
        System.out.println(time1 + " " + time2 + " " + time3);
    }


    public static long fib1(int n){
        if(n <= 2) return 1;
        return fib1(n-1) + fib1(n-2);
    }

    public static void fib2(int n){
        if(n<=2) {
            memo[n] = 1;
            return;
        }

        if(memo[n-2] == 0) fib2(n-2);
        if(memo[n-1] == 0) fib2(n-1);
        memo[n] = memo[n-1] + memo[n-2];
    }

    public static long fib3(int n){
        int arr[] = new int[n+1];
        arr[1] = 1;
        arr[2] = 1;
        for(int i = 3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }

}


