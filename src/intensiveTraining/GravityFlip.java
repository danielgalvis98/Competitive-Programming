package intensiveTraining;

import java.util.Arrays;
import java.util.Scanner;

public class GravityFlip {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		
		Arrays.sort(array);
		System.out.print(array[0]);
		for (int i = 1; i < n; i++) {
			System.out.print(" " + array[i]);
		}
		
		System.out.println("");
	}

}
