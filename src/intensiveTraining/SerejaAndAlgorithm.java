package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class SerejaAndAlgorithm {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String word = br.readLine();
		int [] totX = new int[word.length()];
		int [] totY = new int[word.length()];
		int [] totZ = new int [word.length()];
		
		int actX = 0;
		int actY = 0;
		int actZ = 0;
		for (int i = 0; i < word.length(); i++) {
			if (word.charAt(i) == 'x')
				actX++;
			else if (word.charAt(i) == 'y')
				actY++;
			else
				actZ++;
			totX[i] = actX;
			totY[i] = actY;
			totZ[i] = actZ;
		}
		
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			String [] data = br.readLine().split(" ");
			int l = Integer.parseInt(data[0]) - 1;
			int r = Integer.parseInt(data[1]) - 1;
			int longi = r - l + 1;
			if (longi < 3) {
				bw.write("YES\n");
			} else {
				int xForInt = 0;
				int yForInt = 0;
				int zForInt = 0;
				if (l == 0) {
					xForInt = totX[r];
					yForInt = totY[r];
					zForInt = totZ[r];
				}
				else {
					xForInt = totX[r] - totX[l-1];
					yForInt = totY[r] - totY[l-1];
					zForInt = totZ[r] - totZ[l-1];
				}
				
				int difxy = Math.abs(xForInt - yForInt);
				int difxz = Math.abs(xForInt - zForInt);
				int difyz = Math.abs(zForInt - yForInt);
				if (difxy <= 1 && difxz <= 1 && difyz <= 1)
					bw.write("YES\n");
				else
					bw.write("NO\n");
				}
			}
			
		bw.close();
		}
}


