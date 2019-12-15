package codeforces605Div3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * threefriends
 */
public class threefriends {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int q = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < q; cas++){
            StringTokenizer token = new StringTokenizer(br.readLine());
            long a = Integer.parseInt(token.nextToken());
            long b = Integer.parseInt(token.nextToken());
            long c = Integer.parseInt(token.nextToken());

            long res = Math.abs(a - b) + Math.abs(b - c) + Math.abs(a - c);
            bw.write(Math.max(0, res - 4) + "\n");
        }
        bw.close();
    }
}