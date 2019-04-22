package dinamicProgramming;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class MoveTheWater {
	static int [][][] memo1;
	static boolean [][][] memo2;
	static int c1;
	static int c2;
	static int c3;
	static int b1;
	static int b2;
	static int b3;
	
	public static void main(String[] args) throws IOException {
		memo1 = new int[151][151][151];
		memo2 = new boolean[152][152][152];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String [] x = br.readLine().split("\\s+");
		c1 = Integer.parseInt(x[0]);
		while (c1 != 0) {
			for (int i = 0; i < memo1.length; i++) {
				for (int j = 0; j < memo1.length; j++) {
					Arrays.fill(memo1[i][j], -1);
				}
			}
			c2 = Integer.parseInt(x[1]);
			c3 = Integer.parseInt(x[2]);
			int a1 = Integer.parseInt(x[3]);
			int a2 = Integer.parseInt(x[4]);
			int a3 = Integer.parseInt(x[5]);
			b1 = Integer.parseInt(x[6]);
			b2 = Integer.parseInt(x[7]);
			b3 = Integer.parseInt(x[8]);
			int sol = solve(a1, a2, a3);
			bw.write((sol == Integer.MAX_VALUE ? "-1" : sol) + "\n");
			x = br.readLine().split("\\s+");
			c1 = Integer.parseInt(x[0]);
		}
		
		bw.close();
		
	}
	
	static int solve (int a1, int a2, int a3) {
		if (memo2[a1][a2][a3]) return Integer.MAX_VALUE - 1;
		
		if (memo1[a1][a2][a3] != -1) return memo1[a1][a2][a3];
		
		if (a1 == b1 && a2 == b2 && a3 == b3) {
			return memo1[a1][a2][a3] = 0;
		}
		
		
		
		memo2[a1][a2][a3] = true;
		int op1 = solve(a1 - Math.min(a1, c2 - a2), a2 + Math.min(a1, c2 - a2), a3);
		int op2 = solve(a1, a2 - Math.min(a2, c3 - a3), a3 + Math.min(a2, c3 - a3));
		int op3 = solve(a1, a2 + Math.min(a3, c2 - a2), a3 - Math.min(a3, c2 - a2));
		int op4 = solve(a1 + Math.min(a2, c1 - a1), a2 - Math.min(a2, c1 - a1), a3);
		int op5 = solve(a1 - Math.min(a1, c3-a3), a2, a3 + Math.min(a1, c3-a3));
		int op6 = solve(a1 + Math.min(a3, c1 - a1), a2, a3 - Math.min(a3, c1 - a1));
		memo2[a1][a2][a3] = false;
		return memo1[a1][a2][a3] = Math.min(op1, Math.min(op2, Math.min(op3, Math.min(op4, Math.min(op5, op6))))) + 1;
		
	}
	
	
}
