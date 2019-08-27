package intensiveTraining;

import java.util.Scanner;

public class BeautifulsSetsOfPoints {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int minTerms = sc.nextInt();
		int posible = sc.nextInt();
		minTerms = posible < minTerms ? posible : minTerms;
		System.out.println(minTerms + 1);
		int first = 0;
		int second = 1;
		for (int i = 0; i <= minTerms; i++) {
			System.out.println(i + " " + (i+1)%(minTerms+1));
		}
	}

}
