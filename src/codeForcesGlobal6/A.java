package codeForcesGlobal6;

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

        int n = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < n; cas++){
            String numb = br.readLine();
            boolean hasZero=false;
            boolean pair=false;
            int sum=0;
            for (char a : numb.toCharArray()){
                int digit = a - '0';
                sum += digit;
                pair |= (hasZero&&digit==0) || (digit!=0 && digit%2==0);
                hasZero |= digit == 0;
            }
            if (hasZero && pair && sum%3==0)
                bw.write("red\n");
            else
                bw.write("cyan\n");

        }
        bw.close();
    }
}