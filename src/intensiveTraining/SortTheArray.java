package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SortTheArray {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		String [] array = br.readLine().split(" ");
		
		int [] numbers = new int [n];
		for (int i = 0; i < n; i++) {
			numbers[i] = Integer.parseInt(array[i]);
		}
		
		int actValue = numbers[0];
		int l = 0;
		int r = 0;
		boolean order = true;
		boolean alreadyInverted = false;
		for (int i = 1; i < n; i++) {
			if (order) {
				if (numbers[i] < actValue) {
					if (alreadyInverted) {
						r = -1;
						break;
					}
					order = false;
					l = i-1;
					r = i;
				}
			} else {
				if (numbers[i] < actValue) {
					r = i;
				} else {
					order = true;
					alreadyInverted = true;
				}
			}
			actValue = numbers[i];
		}
		if (r != -1) {
			if ((l == 0 || numbers[l-1] <= numbers[r]) && (r == n-1 || numbers[r+1] >= numbers[l])) {
				System.out.println("yes");
				System.out.println((l+1) + " " + (r+1));
			} else {
				System.out.println("no");
			}
		} else {
			System.out.println("no");
		}
		

	}

}
