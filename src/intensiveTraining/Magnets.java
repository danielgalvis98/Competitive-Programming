package intensiveTraining;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Magnets {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int tot = 1;
		
		int act = Integer.parseInt(br.readLine());
		for (int i = 1; i < n; i++) {
			int next = Integer.parseInt(br.readLine());
			if (next != act) {
				tot++;
				act = next;
			}
		}
		System.out.println(tot);

	}

}
