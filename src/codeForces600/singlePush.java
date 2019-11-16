package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class singlePush {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < T; cas++){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer token = new StringTokenizer(br.readLine());
            StringTokenizer token2 = new StringTokenizer(br.readLine());
            boolean canDifferent = true;
            boolean changing = false;
            int diff = 0;
            boolean pos = true;
            for (int i = 0; i < n; i++){
                int first = Integer.parseInt(token.nextToken());
                int second = Integer.parseInt(token2.nextToken());
                int actDiff = second-first;
                if (actDiff > 0){
                    if (!canDifferent){
                        pos = false;
                        break;
                    }
                    if (changing){
                        if (actDiff != diff){
                            pos = false;
                            break;
                        }
                        continue;
                    }
                    diff = actDiff;
                    changing = true;
                } else if (actDiff < 0){
                    pos = false;
                    break;
                } else {
                    if (changing)
                        canDifferent = false;
                    changing = false;
                }
            }
            bw.write(pos ? "YES\n" : "NO\n");
        }

        bw.close();
    }
}