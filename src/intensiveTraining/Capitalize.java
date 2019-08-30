package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Capitalize {

	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String word = br.readLine();

		System.out.print((word.charAt(0) + "").toUpperCase());

		for (int i = 1; i < word.length(); i++) {
			System.out.print(word.charAt(i));
		}
		System.out.println("");

	}

}

