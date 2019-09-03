package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class StonesOnTheTable {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		String line = br.readLine();
		int count = 0;
		char actColor = line.charAt(0);
		
		for (int i = 1; i < n; i++) {
			char color = line.charAt(i);
			if (color == actColor) {
				count++;
			} else {
				actColor = color;
			}
		}
		
		System.out.println(count);

	}

}
