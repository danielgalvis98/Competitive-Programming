package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Word {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String word = br.readLine();
		int lowercase = 0;
		for (char x : word.toCharArray()) {
			if (x >= 'a' && x <= 'z') {
				lowercase++;
			}
		}
		if (lowercase >= Math.ceil(word.length() / 2d))
			System.out.println(word.toLowerCase());
		else
			System.out.println(word.toUpperCase());

	}

}
