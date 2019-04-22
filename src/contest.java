

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;

public class contest {
	static long [][] memo;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String [] inputs = br.readLine().split(" ");
		int n = Integer.parseInt(inputs[0]);
		int k = Integer.parseInt(inputs[1]);
		String [] levels = br.readLine().split(" ");
		
		memo = new long[n + 3][k + 3];
		for (int i = 0; i < memo.length; i++) {
			Arrays.fill(memo[i], -1);
			
		}
		
		HashMap<Integer, Integer> values = new HashMap<Integer, Integer>();
		for (String level : levels) {
			int levelInt = Integer.parseInt(level);
			if (!values.containsKey(levelInt))
				values.put(levelInt, 1); 
			else 
				values.put(levelInt, values.get(levelInt) + 1);
		}
		
		Integer [] arr = new Integer [1];
		arr = values.values().toArray(arr);
		System.out.println(possibilites(arr, 0, k));
	}
	
	static long possibilites (Integer [] arr, int i, int k) {
		if (k == 0) 
			return memo[i][k] = 1;
		
		
		if (arr.length - i < k)
			return memo[i][k] = 0;
		long pos1 = memo[i+1][k-1] != -1 ? memo[i+1][k-1] : possibilites(arr, i+1, k-1);
		long pos2 = memo[i+1][k] != -1 ? memo[i+1][k] : possibilites(arr, i+1, k);
		
		return memo[i][k] = ((arr[i]%998244353 * pos1%998244353)%998244353 + pos2%998244353)%998244353;
		
		
	}

}
