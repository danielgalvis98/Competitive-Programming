package dinamicProgramming;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;

public class TakeshiCastle {
	static double L;
	static double [] distances;
	static double [] probabilities;
	static double [] memo;
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String [] initialData = reader.readLine().split(" ");
		int cases = Integer.parseInt(initialData[0]);
		L = Integer.parseInt(initialData[1]);
		String [] probas = reader.readLine().split(" ");
		String [] dists = reader.readLine().split(" ");
		
		distances = new double [cases];
		probabilities = new double [cases];
		for (int i = 0; i < cases; i++) {
			distances [i] = Double.parseDouble(dists[i]);
			probabilities [i] = Double.parseDouble(probas[i]);
		}
		memo = new double [cases];
		for (int i = 0; i < memo.length; i++) {
			memo[i] = -1;
		}
		//Hola que tal
		double solution = prob(cases - 1);
		DecimalFormat df = new DecimalFormat("##.######");
		writer.write(df.format(solution));
		reader.close();
		writer.close();
	}
	
	public static double prob(int position) {
		if (position < 0) {
			return 0;
		}
		double result = -1;
		double actDist = distances [position];
		int newPosition = position--;
		while (actDist - distances[newPosition] <= L) {
			double candidate;
			if (memo[newPosition] == -1) {
				candidate = prob(newPosition - 1);
				memo[newPosition] = candidate;
			} else {
				candidate = memo[newPosition];
			}
			result = Math.max(result, candidate);
		}
		return result;
	}

}
