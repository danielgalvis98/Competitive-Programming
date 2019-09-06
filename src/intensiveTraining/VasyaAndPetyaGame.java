package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;

public class VasyaAndPetyaGame {
	static int [] spf = new int [1005];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		ArrayList<Integer> needToAsk = new ArrayList<Integer>();
		
		sieve();
		for (int i = 2; i <= 1004; i++) {
			HashSet<Integer> factors = factors(i);
			if (factors.size() == 1) {
				needToAsk.add(i);
			}
		}
		int n = Integer.parseInt(br.readLine());
		
		int totNeeded = 0;
		StringBuilder builder = new StringBuilder();
		if (n == 1) {
			bw.write("0\n");
		} else {
			totNeeded++;
			builder.append("2");
			int i = 1;
			while ( i < needToAsk.size() && needToAsk.get(i) <= n) {
				int act = needToAsk.get(i);
				totNeeded++;
				builder.append(" " + act);
				i++;
			}
			bw.write(totNeeded+"\n" + builder.toString() + "\n");
		}
		bw.close();
		
	}
	
	static void sieve() {
		spf[1] = 1;
		for (int i = 2; i < 1005; i++) {
			if (i % 2 == 0) {
				spf[i] = 2;
			} else {
				spf[i] = i;
			}
		}
		
		for (int i = 3; i*i < 1005; i++) {
			if (spf[i] == i) {
				for (int j = i*i; j<1005; j+= i) {
					if (spf[j] == j) {
						spf[j] = i;
					}
				}
			}
		}
	}
	
	static HashSet<Integer> factors (int x){
		HashSet<Integer> factors = new HashSet<Integer>();
		
		while (x != 1) {
			factors.add(spf[x]);
			x = x / spf[x];
		}
		return factors;
	}

}


