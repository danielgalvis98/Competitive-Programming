package codeJamRound0;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Foregone {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		for (int test = 1; test <= T; test++) {
			char [] original = br.readLine().toCharArray();
			StringBuilder newNumber = new StringBuilder();
			for (int i = 0; i < original.length; i++) {
				if (original [i] == '4') {
					newNumber.append('1');
					original[i] = '3';
				} else {
					if (newNumber.length() != 0) {
						newNumber.append('0');
					}
				}
			}
			String newString = new String(original);
			bw.write("Case #" + test + ": "  + newString + " " + newNumber.toString() + "\n");
		}
		bw.close();

	}

}
