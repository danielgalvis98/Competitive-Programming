package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class ClassyNumbers {
	
	static int [][][] memo;
	static String numb;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int limit = 19; 
		
		int T = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < T; i++) {
			String [] limits = br.readLine().split(" ");
			long num = Long.parseLong(limits[0])-1;
			numb = num + "";
			StringBuilder build = new StringBuilder();
			long zeroes = limit - numb.length();
			for (int j = 0; j < zeroes; j++) {
				build.append('0');
			}
			numb = build.toString() + numb;
			memo = new int [19][2][4];
			
			int result1 = solve(0, false, 3);
			
			numb = limits[1];
			build = new StringBuilder();
			zeroes = limit - numb.length();
			for (int j = 0; j < zeroes; j++) {
				build.append('0');
			}
			numb = build.toString() + numb;
			memo = new int [19][2][4];

			int result2 = solve(0, false, 3);
			
			bw.write(result2 - result1 + "\n");
		}
		bw.close();

	}
	
	
	static int solve (int dIndex, boolean solved, int remaining) {
		if (dIndex > 18) return 1;
		int resultMemo = memo[dIndex][solved ? 1 : 0][remaining]; 
		if (resultMemo != 0) return resultMemo;
		int max = solved ? 9 : numb.charAt(dIndex) - '0';
		if (remaining == 0) {
			max = 0;
		}
		for (int i = 0; i <= max; i++) {
			resultMemo += solve(dIndex+1, solved || i < max, i == 0? remaining : remaining - 1);
		}
		
		
		return memo[dIndex][solved ? 1 : 0][remaining] = resultMemo;
	}

}
