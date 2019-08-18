package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class PetyaAndCountryside {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		String[] levels = br.readLine().split(" ");
		
		int [] totRain = new int[n];
		int [] intLevels = new int [n];
		for (int i = 0; i < n; i++) {
			intLevels [i] = Integer.parseInt(levels[i]);
			totRain [i] = 1;
		}
		
		int li = 0;
		for (int ld = 1; ld < n; ld++) {
			if (intLevels[ld] == intLevels[ld-1]) {
				totRain[ld] += totRain[ld - 1];
				for (int j = ld - 1; j >= li; j--) {
					totRain[j]++;
				}
			} else if (intLevels[ld] > intLevels [ld-1]) {
				li = ld;
				totRain[ld] += totRain [ld - 1];
			} else {
				for (int j = ld - 1; j >= li; j--) {
					totRain[j]++;
				}
			}
		}
		
		int max = Integer.MIN_VALUE;
		for (int act : totRain) {
			max = Math.max(max, act);
		}
		bw.write(max + "\n");
		bw.close();
		br.close();
	}

}
