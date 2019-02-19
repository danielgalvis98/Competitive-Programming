package dinamicProgramming;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.util.Locale;

public class TakeshiCastleIterative {
	static double L;
	static double [] distances;
	static double [] probabilities;
	static double [] memo;
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String [] initialData = reader.readLine().split(" ");
		int cases = Integer.parseInt(initialData[0]);	
		L = Double.parseDouble(initialData[1]);
		double D = Double.parseDouble(initialData[2]);
		String [] probas = reader.readLine().split(" ");
		String [] dists = reader.readLine().split(" ");
		
		distances = new double [cases + 1];
		distances[0] = 0;
		probabilities = new double [cases + 1];
		probabilities[0] = 1;
		for (int i = 1; i < cases + 1; i++) {
			distances [i] = Double.parseDouble(dists[i - 1]);
			probabilities [i] = Double.parseDouble(probas[i - 1]);
		}
		memo = new double [cases + 1];
		for (int i = 1; i < memo.length; i++) {
			memo[i] = -1;
		}
		
		memo[0] = 1;
		
		double solution = prob(cases + 1);
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMinimumFractionDigits(6);
		String result = nf.format(solution);
		String correct = result.replace(',', '.');
		writer.write(solution == 0 ? "IMPOSSIBLE" : correct);
		reader.close();
		writer.close();
	}
	
	public static double prob(int length) {
		double probAct = 1;
		for (int i = 0; i < length; i++) {
			probAct = memo[i];
			for (int j = i+1; j < length && distances[j] - distances[i] <= L; j++) {
				double newProb = memo[j];
				memo[j] = Math.max(newProb, probAct * probabilities[j]);
			}
		}
		
		if (L - distances[length - 1] <= L)
			return memo[length-1];
		else 
			return 0;
	}

}
