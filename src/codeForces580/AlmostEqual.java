package codeForces580;

import java.util.Scanner;

public class AlmostEqual {

	public static void main(String[] args) {
		int n = (new Scanner(System.in)).nextInt();
		if (n % 2 == 0) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			StringBuilder builder = new StringBuilder();
			int i = 1;
			while (i <= 2*n) {
				builder.append(i + " ");
				i += i % 2 == 0? 1 : 3;
			}
			i = 2;
			while (i <= 2*n) {
				builder.append(i + " ");
				i += i % 2 == 0? 1 : 3;
			}
			System.out.println(builder.toString().trim());
		}

	}

}
