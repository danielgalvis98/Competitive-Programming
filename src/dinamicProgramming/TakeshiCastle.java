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
		L = Double.parseDouble(initialData[1]);
		double D = Double.parseDouble(initialData[2]);
		String [] probas = reader.readLine().split(" ");
		String [] dists = reader.readLine().split(" ");
		
		distances = new double [cases + 1];
		probabilities = new double [cases + 1];
		for (int i = 0; i < cases; i++) {
			distances [i] = Double.parseDouble(dists[i]);
			probabilities [i] = Double.parseDouble(probas[i]);
		}
		distances [cases] = D;
		probabilities[cases] = 1;
		memo = new double [cases];
		for (int i = 0; i < memo.length; i++) {
			memo[i] = -1;
				
		}
		double solution = prob(cases);
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMinimumFractionDigits(6);
		String result = nf.format(solution);
		String correct = result.replace(',', '.');
		writer.write(solution == 0 ? "IMPOSSIBLE" : correct);
		reader.close();
		writer.close();
	}
	
	public static double prob(int position) {	
		if (distances [position] <= L) {
			return probabilities[position];
		}
		
		double result = 0;
		
		int actualPosition = position - 1;
		while (actualPosition >= 0 && distances[position] - distances[actualPosition] <= L) {
			double candidate;
			if (memo[actualPosition] == -1) {
				candidate = prob(actualPosition);
				memo[actualPosition] = candidate;
			} else {
				candidate = memo[actualPosition];
			}
			result = Math.max(result, candidate);
			actualPosition--;
		}
		
		return result * probabilities[position];
	}

}
