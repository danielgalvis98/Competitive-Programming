package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class sweets {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        long [] acum = new long[n];
        int [] sweets = new int [n];
        tokenizer = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++){
            sweets[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(sweets);
        bw.write(sweets[0] + "");
        long acumu = sweets[0];
        acum[0] = acumu;
        for (int i = 1; i < m; i++){
            acumu += sweets[i];
            acum[i] = sweets[i];
            bw.write(" " + acumu);
        }
        for (int i = m; i < n; i++){
            acum[i] = sweets[i] + acum[i - m]; 
            acumu += acum[i];
            bw.write(" " + acumu);
        }
        bw.write("\n");

        bw.close();
    }
}