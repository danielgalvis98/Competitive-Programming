package codeforces601;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * fridge
 */
public class fridge {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < T; cas++){
            StringTokenizer token = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(token.nextToken());
            int m = Integer.parseInt(token.nextToken());
            token = new StringTokenizer(br.readLine());
            int minNeeded =  n;
            if (m < n || n == 2){
                bw.write("-1\n");
                continue;
            }

            int [] weights = new int [n];

            int ans = 0;
            for (int i = 0; i < n; i++){
                ans += Integer.parseInt(token.nextToken());
            }
            ans *= 2;
            bw.write(ans + "\n");
            for (int i = 2; i <= n; i++){
                bw.write(i + " " + (i-1) + "\n");
            }
            bw.write(1 + " " + (n) + "\n");
        }
        bw.close();
    }
}

class coso implements Comparable<coso>{
    int peso;
    int index;

    coso(int peso, int index){
        this.peso = peso;
        this.index = index;
    }
    @Override
    public int compareTo(coso o) {
        return peso - o.peso;
    }

}