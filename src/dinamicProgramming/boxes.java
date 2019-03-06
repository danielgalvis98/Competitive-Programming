//package dinamicProgramming;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static int [] [] memo;

	static box [] theBoxes;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		while (N != 0) {
			memo = new int [N][3006];
			for (int i = 0; i < memo.length; i++) {
				for (int j = 0; j < memo[0].length; j++) {
					memo[i][j] = -1;
				}
			}
			theBoxes = new box [N];
			for (int i = 0; i < N; i++) {
				String [] data = br.readLine().split(" ");
				theBoxes [i] = new box(i, Integer.parseInt(data[0]), Integer.parseInt(data[1]));
			}
			bw.write(maxBoxes(-1, 3001) + "\n");
			N = Integer.parseInt(br.readLine());
		}
		bw.close();

	}
	
	public static int maxBoxes (int box, int maxW) {
		if (box != -1 && memo[box][maxW] != -1) {
			return memo[box][maxW];
		}
		int max = -1;
		for (int i = box + 1; i < theBoxes.length; i++) {
			if (memo[i][maxW] != -1) {
				max = Math.max(max, memo[i][maxW]);
			} else {
				box newBox = theBoxes[i];
				if (newBox.weight <= maxW) {
					int newMax = Math.min(newBox.maxLoad, maxW - newBox.weight);
					int newStack = maxBoxes(i, newMax);
					max = Math.max(max, newStack);
					memo[i][maxW] = newStack;
				}
			}
		}
//		if (box != -1) {
//			memo[box][max]
//		}
		return max + 1;
	}

}

class box {
	int position;
	int weight;
	int maxLoad;
	
	box (int pos, int wt, int ml){
		position = pos;
		weight = wt;
		maxLoad = ml;
	}
}
