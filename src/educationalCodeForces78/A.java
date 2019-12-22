package educationalCodeForces78;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
/**
 * A
 */
public class A {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < t; cas++){
            int [] letters = new int [27];
            String origi = br.readLine();
            Set<Character> elems = new HashSet<>();
            for (char act: origi.toCharArray()){
                letters[act - 'a']++;
                elems.add(act);
            }

            int [] newStr = new int [27];
            String pass = br.readLine();

            boolean firstOne = false;
            for (char act: pass.toCharArray()){
                if (elems.contains(act)){
                    int e = act - 'a';
                    newStr[e]++;
                } else {
                    newStr = new int[27];
                }
            }
            boolean pos = true;

            bw.write(pos ? "YES\n" : "NO\n");
        }
        bw.close();
    }
}