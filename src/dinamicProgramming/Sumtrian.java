package dinamicProgramming;

import java.util.Scanner;

class Sumtrian {
	static int [] memo;
	static int [] values; 

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int n = sc.nextInt();
			memo = new int [n*(n+1)/2];
			values = new int [n*(n+1)/2];
			for (int j = 0; j < n*(n+1)/2; j++) {
				values [j] = sc.nextInt();
			}
			solve(n);
			System.out.println(memo[0]);
		}

	}
	
	static void solve (int maxLevel) {
		int level = maxLevel;
		for (level = maxLevel; level > 0; level--) {
			for (int j = level*(level-1)/2; j < level*(level+1)/2; j++) {
				if (level == maxLevel) {
					memo[j] = values[j];
				} else {
					memo[j] = values[j] + Math.max(memo[j + level], memo[j + level + 1]);
				}
			}
		}
	}

}
