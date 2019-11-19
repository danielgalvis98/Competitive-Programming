package codeforces601;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * changing
 */
public class changing {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < T; cas++){
            StringTokenizer token = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());
            int dif = Math.abs(b - a);
            int acum = 0;
            acum += dif / 5;
            int newDif = dif - (acum*5);
            int newAcum = newDif / 2;;
            acum += newAcum;
            newDif -= newAcum * 2;
            acum += (newDif);
            bw.write(acum + "\n");
        }

        bw.close();
    }
    
}