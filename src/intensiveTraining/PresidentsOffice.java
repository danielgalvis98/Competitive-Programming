package intensiveTraining;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class PresidentsOffice {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] initData = br.readLine().split(" ");
		
		int rows = Integer.parseInt(initData[0]);
		int columns = Integer.parseInt(initData[1]);
		
		char color = initData[2].charAt(0);
		
		char [] [] matrix = new char [rows][columns];
		
		for (int i = 0; i < rows; i++) {
			matrix[i] = br.readLine().toCharArray();
		}
		
		int x1 = -1;
		int x2 = -1;
		int y1 = -1;
		int y2 = 1;
		
		boolean stop = false;
		for (int i = 0; i < rows && !stop; i++) {
			for (int j = 0; j < columns && !stop; j++) {
				char act = matrix[i][j];
				if (act == color) {
					x1 = i;
					x2 = i;
					y1 = y2 = j;
					stop = true;
				}
			}
		}
		
		
		for (int i = x1 + 1; i < rows && matrix[i][y1] == color; i++) {
			x2 = i;
		}
		
		for (int i = y1 + 1; i < columns && matrix[x1][i] == color; i++) {
			y2 = i;
		}
		
		
		HashSet<Character> colors = new HashSet<Character>();
		
		
		for (int i = x1; i <= x2; i++) {
			if (y1 != 0) {
				char actual = matrix[i][y1-1];
				if (actual != '.') {
					colors.add(actual);
				}
			}
			
			if (y2 < columns - 1) {
				char actual = matrix[i][y2 + 1];
				if (actual != '.') {
					colors.add(actual);
				}
			}
		}
		
		for (int i = y1; i <= y2; i++) {
			if (x1 != 0) {
				char actual = matrix[x1-1][i];
				if (actual != '.') {
					colors.add(actual);
				}
			}
			
			if (x2 < rows - 1) {
				char actual = matrix[x2+1][i];
				if (actual != '.') {
					colors.add(actual);
				}
			}
		}
		
		System.out.println(colors.size());

	}

}
