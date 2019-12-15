package codeforces605Div3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
/**
 * brokenKeyboard
 */
public class brokenKeyboard {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(token.nextToken());
        int k = Integer.parseInt(token.nextToken());
        Set<Character> available = new HashSet<>();
        String word = br.readLine();
        token = new StringTokenizer(br.readLine());
        while (k != 0){
            available.add(token.nextToken().charAt(0));
            k--;
        }
        long partSum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++){
            char act = word.charAt(i);
            if (available.contains(act))
                partSum++;
            else {
                ans += ((partSum)*(partSum + 1)) / 2;
                partSum = 0;
            }
        }
        ans += ((partSum)*(partSum + 1)) / 2;
        bw.write(ans + "\n");
        bw.close();
    }
}