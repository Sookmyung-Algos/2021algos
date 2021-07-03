import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            int n = sc.nextInt();
            int arr[][] = new int[n+2][n+2];
            boolean d[][] = new boolean[n+2][n+2];
            List<int[]> list = new ArrayList<>();
            for (int i = 0; i <= n + 1; i++){
                list.add(new int[]{sc.nextInt(), sc.nextInt()});
            }

            for (int i = 0; i <= n + 1; i++)
                for (int j = 0; j <= n + 1; j++) {
                    int p1[] = list.get(i);
                    int p2[] = list.get(j);
                    arr[i][j] = Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
                    if (arr[i][j] <= 50 * 20)
                        d[i][j] = true;
                }


            for (int k = 0; k <= n + 1; k++)
                for (int i = 0; i <= n + 1; i++)
                    for (int j = 0; j <= n + 1; j++)
                        if (d[i][k] & d[k][j])
                            d[i][j] = true;
            System.out.println(d[0][n + 1] ? "happy" : "sad");
        }
    }
}
