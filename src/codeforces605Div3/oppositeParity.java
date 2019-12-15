package codeforces605Div3;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
/**
 * oppositeParity
 */
public class oppositeParity {

    static int [] memo;
    static int [] arr;
    static int n;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr= new int [n];
        memo = new int [n];
        StringTokenizer token = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(token.nextToken());
            memo[i] = -2;
        }

        int ans = solve(0);
        bw.write(ans + "");
        for (int i = 1; i < n; i++){
            bw.write(" " + solve(i));
        }
        bw.write("\n");
        bw.close();
    }

    static int solve (int index){
        if (memo[index] != -2)
            return memo[index];
        int elem = arr[index];
        boolean pair = elem % 2 == 0;
        int nextIndex = index + elem;
        int op1 = -1;
        if (nextIndex < n && nextIndex > 0){
            int nextElem = arr[nextIndex];
            boolean pair2 = nextElem % 2 == 0;
            if (pair ^ pair2){
                op1 = 1;
            } else {
                op1 = solve(nextIndex);
                if (op1 != -1) op1++;
            }
        }
        int op2 = -1;
        int pastIndex = index - elem;
        if (pastIndex >= 0){
            int lastElem = arr[pastIndex];
            boolean pair2 = lastElem % 2 == 0;
            if (pair ^ pair2){
                op2 = 1;
            } else { 
                op2 = solve(pastIndex);
                if (op2 != -1) op2++;
            }
        }
        
        int ans;
        if (op1 == -1)
            ans = op2;
        else if (op2 == -1)
            ans = op1;
        else
            ans = Math.min(op1, op2);
        return memo[index] = ans;
    }
    
}