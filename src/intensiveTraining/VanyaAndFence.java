package intensiveTraining;

import java.util.Scanner;

public class VanyaAndFence {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int h = sc.nextInt();
		int minWidth = 0;
		for (int i = 0; i < n; i++) {
			int height = sc.nextInt();
			minWidth += height > h ? 2 : 1;
		}
		
		System.out.println(minWidth);
		sc.close();
	}

}
