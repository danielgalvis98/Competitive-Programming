package intensiveTraining;

import java.util.Scanner;

public class EasterEggs {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char[] colors = new char[] {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
		
		int n = sc.nextInt();
		int mod = n % 7;
		int div = n / 7;
		for (int i = 0; i < div; i++) {
			System.out.print("ROYGBIV");
		}
		
		if (mod >= 4) {
			for (int i = 0; i < mod; i++) {
				System.out.print(colors[i]);
			}
		} else {
			for (int i = 0; i < mod; i++) {
				System.out.print(colors[3 + i]);
			}
		}
		
		System.out.println("");

	}

}
