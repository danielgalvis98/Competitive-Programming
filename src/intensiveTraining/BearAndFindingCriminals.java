package intensiveTraining;

import java.io.BufferedReader;
import java.util.Scanner;

public class BearAndFindingCriminals {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int [] totCriminals = new int [n];
		for (int i = 0; i < n; i++) {
			totCriminals[i] = sc.nextInt();
		}
		
		int criminalsCatched = 0;
		for (int i = 0; (a - 1 - i) >= 0 || (a - 1 + i) < n; i++) {
			boolean catchedLeft = true;
			boolean catchedRight = true;
			int possibleSum = 0;
			if (a - 1 - i >= 0) {
				catchedLeft = totCriminals[a-1-i] == 1;
				possibleSum++;
			}
			
			if (a - 1 + i < n) {
				catchedRight = totCriminals[a-1+i] == 1;
				possibleSum++;
			}
			if (catchedLeft && catchedRight) {
				if (i==0)
					criminalsCatched++;
				else
					criminalsCatched += possibleSum;
			}
		}
		System.out.println(criminalsCatched);

	}

}
