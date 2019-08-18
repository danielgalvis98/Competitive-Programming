package intensiveTraining;

import java.util.Scanner;

public class PatrickAndShopping {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int d1 = sc.nextInt();
		int d2 = sc.nextInt();
		int d3 = sc.nextInt();
		
		int max;
		int min;
		if (d1 > d2) {
			max = d1;
			min = d2;
		} else {
			max = d2;
			min = d1;
		}
		
		int acum = min;
		acum += Math.min(min + max, d3);
		acum += Math.min(max, d3 + min);
		
		System.out.println(acum);

	}

}
