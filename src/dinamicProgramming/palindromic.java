package dinamicProgramming;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class palindromic {
	static HashMap<String,Integer> memo = new HashMap<>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String read = br.readLine();
			bw.write(longestPalindromic(read)+"\n");
		}
		bw.close();
	}
	
	
	static boolean isPalindromic(String x) {
		boolean isPal = true;
		for (int i = 0; i < x.length()/2 && isPal; i++) {
			isPal = x.charAt(i) == x.charAt(x.length() - 1 - i);
		}
		return isPal;
	}
	
	static int longestPalindromic (String x) {
		if(memo.containsKey(x))return memo.get(x);
		if (isPalindromic(x)) return x.length();
		else {
			int max = -1;
			for (int i = 0; i < x.length(); i++) {
				max = Math.max(max, longestPalindromic(x.substring(0, i) + x.substring(i + 1, x.length())));
			}
			memo.put(x,max);
			return max;
		}
	}
}