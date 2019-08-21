package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.HashSet;

public class Watchmen {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Long, Long> rows = new HashMap<>();
		HashMap<Long, Long> columns = new HashMap<>();
		HashMap<String, Long> checkRepeated = new HashMap<>();
		
		long areEqual = 0;
		
		int n = Integer.parseInt(br.readLine());
		long posRepeated = 0;
		
		for (int i = 0; i < n; i++){
			String [] pos = br.readLine().split(" ");
			long x = Long.parseLong(pos[0]);
			long y = Long.parseLong(pos[1]);
			
			if (checkRepeated.containsKey(x + "," + y)){
				long total = checkRepeated.get(x + "," + y);
				areEqual -= total;
				checkRepeated.put(x + "," + y, total + 1L);
			} else {
				checkRepeated.put(x + "," + y, (long)1);
			}
			
			if (rows.containsKey(x)){
				long total = rows.get(x);
				areEqual += total;
				rows.put(x, total + 1);
			} else {
				rows.put(x, (long) 1);
			}
			
			if (columns.containsKey(y)){
				long total = columns.get(y);
				areEqual += total;
				columns.put(y, total + 1);
			} else {
				columns.put(y, (long) 1);
			}
		}
		
		
		
		System.out.println(areEqual);
	}

}



