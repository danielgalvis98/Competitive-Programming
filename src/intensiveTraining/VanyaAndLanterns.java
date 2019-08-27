package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class VanyaAndLanterns {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] initData = br.readLine().split(" ");
		int n = Integer.parseInt(initData[0]);
		long l = Long.parseLong(initData[1]);
		
		String [] lanterns = br.readLine().split(" ");
		long [] longLanterns = new long[n];
		for (int i = 0; i < n; i++) {
			longLanterns[i] = Long.parseLong(lanterns[i]);
		}
		Arrays.sort(longLanterns);
		long firstLant = longLanterns[0];
		double minD = (double) firstLant;
		for (int i = 0; i < n - 1; i++) {
			double possible = (longLanterns[i+1] - longLanterns[i])/2d;
			if (possible > minD)
				minD = possible;
		}
		long newPosibility = l - longLanterns[n - 1];
		if (newPosibility > minD) {
			System.out.println(newPosibility);
		} else {
			System.out.format("%.10f", minD);
		}
		
	}

}
