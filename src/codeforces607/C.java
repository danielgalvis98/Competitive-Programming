package codeforces607;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * A
 */
public class C {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < t; cas++){
            int x = Integer.parseInt(br.readLine());
            StringBuilder builder = new StringBuilder(br.readLine());
            long totLength = builder.length();
            int l = 1;
            while (builder.length() < x){
                String r = builder.substring(l);
                String left = builder.substring(0,l);
                int times = Integer.parseInt(left);
                for (int i = 0; i < times-1; i++)
                    builder.append(r.substring(0, Math.min(r.length(), x - builder.length())));
                l++;
            }
            l = 1;
            while (l <= x){
                int left = Integer.parseInt(builder.substring(0,l));
                totLength += ((left-1)*(totLength - l)) % 1000000007;
                l++;
            }
            bw.write(totLength + "\n");

        }
        bw.close();
    }
    
}