package intensiveTraining;

import java.util.Scanner;

public class PoliceRecruits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int totPoliceS = 0;
		int totCrimes = 0;
		for (int i = 0; i < n; i++) {
			int read = sc.nextInt();
			if (read > 0) {
				totPoliceS+=read;
			} else {
				if (totPoliceS > 0) {
					totPoliceS--;
				} else {
					totCrimes++;
				}
			}
		}
		System.out.println(totCrimes);

	}

}
