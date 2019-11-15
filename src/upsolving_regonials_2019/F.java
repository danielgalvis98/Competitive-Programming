package upsolving_regonials_2019;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class F {

	static long modulo = 1000000007;
	
	static long [] [] dp;
	static long [] [] dp2;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer token = new StringTokenizer(br.readLine());
		int S = Integer.parseInt(token.nextToken());
		int B = Integer.parseInt(token.nextToken());
		B -= S;
		dp = new long [S + 5] [B + 5];
		dp2 = new long[S + 5] [B + 5];
		for (int i = 0; i <= B; i++) {
			dp [1][i] = 1;
			dp2 [1][i] = 1;
		}
		
		for (int i = 2; i <= S; i++) {
			for (int j = 0; j <= B; j++) {
				int min = Math.min(i, j);
				long result = ((((i+1)*dp[min][j - min]) % modulo - (dp2[min][j - min]) + modulo)) % modulo;
				if (j == 0)
					result = 1;
				dp[i][j] = (dp[i-1][j+1] + result) % modulo;
				dp2[i][j] = (dp2[i-1][j+1] + (i*result) % modulo) % modulo;
			}
		}
		bw.write(dp[S][B] + "\n");
		bw.close();
	}

}
