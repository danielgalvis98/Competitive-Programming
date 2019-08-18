package codeForces580;

import java.util.HashSet;
import java.util.Scanner;

public class ChooseTwoNumbers {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		HashSet<Integer> arrayA = new HashSet<>();
		HashSet<Integer> arrayB = new HashSet<>();
		
		int n = sc.nextInt();
		for (int i = 0 ; i < n; i++) {
			arrayA.add(sc.nextInt());
		}
		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
			arrayB.add(sc.nextInt());
		}
		
		boolean found = false;
		int a = -1;
		int b = -1;
		for (int first: arrayA) {
			a = first;
			for (int second: arrayB) {
				b = second;
				int result = a + b;
				if (!arrayA.contains(result) && !arrayB.contains(result)) {
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
		
		System.out.println(a + " " + b);
	}

}
