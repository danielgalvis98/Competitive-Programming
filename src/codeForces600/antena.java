package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class antena {
    private static List<lamp> lamps = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(token.nextToken());
        int m = Integer.parseInt(token.nextToken());
        for (int i = 0; i < n; i++) {
            token = new StringTokenizer(br.readLine());
            int center = Integer.parseInt(token.nextToken());
            int radio = Integer.parseInt(token.nextToken());
            int left = center - radio;
            int right = center + radio;
            lamps.add(new lamp(left, right, center));
        }

        int [] dp = new int [m + 1];
        dp [m] = 0;
        for (int i = m - 1; i >= 0; i--){
            dp[i] = m - i;
            for (lamp theLamp : lamps){
                if ( i+1 >= theLamp.left && i+1 <= theLamp.right){
                    dp [i] = dp [i+1];
                    break;
                }
                if (i < theLamp.left){
                    int toComplete = theLamp.left - i - 1;
                    dp [i] = Math.min(dp[i], toComplete + dp[Math.min(m, theLamp.right + toComplete)]);
                }
            }
        }
        bw.write(dp[0] + "\n");
        bw.close();
    }
}

class lamp {
    int left;
    int right;
    int center;

    lamp(int a, int b, int c) {
        left = a;
        right = b;
        center = c;
    }
}