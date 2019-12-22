package codeforces607;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * A
 */
public class A {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < T; cas++){
            String fras = br.readLine();
            if (fras.endsWith("po"))
                bw.write("FILIPINO\n");
            else if (fras.endsWith("desu") || fras.endsWith("masu"))
                bw.write("JAPANESE\n");
            else
                bw.write("KOREAN\n");
        }
        bw.close();
    }
    
}