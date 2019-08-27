package intensiveTraining;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class BoyOrGirl {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		char[] user = br.readLine().toCharArray();
		
		HashSet<Character> letters = new HashSet<Character>();
		
		boolean isFemale = true;
		for (char x: user) {
			if (!letters.contains(x)) {
				isFemale = !isFemale;
				letters.add(x);
			}
		}
		
		if (isFemale) {
			System.out.println("CHAT WITH HER!");
		} else {
			System.out.println("IGNORE HIM!");
		}

	}

}
