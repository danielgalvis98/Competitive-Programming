package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class DrazilAndFactorial {

	public static void main(String[] args) throws NumberFormatException, IOException {
		HashMap<Character, char []> decomposed = new HashMap<>();
		decomposed.put('2', new char[] {'2'});
		decomposed.put('3', new char[] {'3'});
		decomposed.put('4', new char[] {'3','2','2'});
		decomposed.put('5', new char[] {'5'});
		decomposed.put('6', new char[] {'5', '3'});
		decomposed.put('7', new char[] {'7'});
		decomposed.put('8', new char[] {'7', '2', '2', '2'});
		decomposed.put('9', new char[] {'7', '3', '3', '2'});
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int size = Integer.parseInt(br.readLine());
		char [] numbers = br.readLine().toCharArray();
		ArrayList<Character> newNumbers = new ArrayList<Character>();
		for (Character number : numbers) {
			if (number != '1' && number != '0') {
				for (char newNumber : decomposed.get(number)) {
					newNumbers.add(newNumber);
				}
			}
		}
		Collections.sort(newNumbers);
		for (int i = newNumbers.size() - 1; i >= 0; i--) {
			bw.write(newNumbers.get(i));
		}
		bw.write("\n");
		bw.close();
	}

}
