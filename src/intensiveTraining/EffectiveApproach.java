package intensiveTraining;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EffectiveApproach {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int [] indexes = new int [n];
		String [] array = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			int index = Integer.parseInt(array[i]);
			indexes[index-1] = i;
		}
		
		int m = Integer.parseInt(br.readLine());
		String [] queries = br.readLine().split(" ");
		long first = 0;
		long second = 0;
		for (int i = 0; i < m; i++) {
			int query = Integer.parseInt(queries[i]);
			first += indexes[query-1] + 1;
			second += n - indexes[query-1];
		}
		
		System.out.println(first + " " + second);
	}

}
