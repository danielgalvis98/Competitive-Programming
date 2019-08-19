package intensiveTraining;

import java.util.Scanner;

public class BearAndBigBrother {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int limak = sc.nextInt();
		int bob = sc.nextInt();
		int totYears = 0;
		while (limak <= bob) {
			limak *= 3;
			bob *= 2;
			totYears++;
		}
		System.out.println(totYears);

	}

}
