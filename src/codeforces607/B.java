package codeforces607;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * A
 */
public class B {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < T; cas++){
            StringTokenizer token = new StringTokenizer(br.readLine());
            char [] s = token.nextToken().toCharArray();
            char [] c = token.nextToken().toCharArray();
            int minChar [] = new int [s.length];
            char min = 'Z' + 10;
            for (int i = s.length - 1; i >= 0; i--){
                if (s[i] < min){
                    minChar [i] = i;
                    min = s[i];
                }
                else
                    minChar[i] = minChar[i+1];
            }
            for (int i = 0; i < s.length; i++){
                char minAct = s[minChar[i]];
                if (minAct < s[i]){
                    s[minChar[i]] = s[i];
                    s[i] = minAct;
                    break;
                }
            }

            if ((new String(s)).compareTo(new String(c)) < 0){
                bw.write((new String(s)) + "\n");
            } else {
                bw.write("---\n");
            }
            
        }
        bw.close();
    }
    
}