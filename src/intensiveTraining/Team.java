package intensiveTraining;

import java.util.Scanner;

public class Team {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int totProblems = 0;
		for (int i = 0; i < n; i++) {
			int totVotes = 0;
			for (int j = 0; j < 3; j++) {
				totVotes += sc.nextInt();
			}
			if (totVotes >= 2) {
				totProblems++;
			}
		}
		System.out.println(totProblems);

	}

}
