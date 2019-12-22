package codeForcesGlobal6;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
/**
 * B
 */
public class B {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        StringTokenizer token = new StringTokenizer(br.readLine());
        for (int i = 0; i < t; i++){
            long elem = Long.parseLong(token.nextToken());
            int mod =(int) (elem % 14);
            if (elem > 14 && mod > 0 && mod < 7)
                bw.write("YES\n");
            else
                bw.write("NO\n");
        }

        
        bw.close();
    }
}