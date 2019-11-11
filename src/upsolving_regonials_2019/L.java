package upsolving_regonials_2019;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class L {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer tokeni = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(tokeni.nextToken());
		int M = Integer.parseInt(tokeni.nextToken());
		
		int [][] mat = new int[N][M];
		for (int i = 0; i < N; i++) {
			String line = br.readLine();
			char last = line.charAt(0);
			int acum = 1;
			mat[i][0] = 1;
			for (int j  = 1; j < M; j++) {
				char act = line.charAt(j);
				if (act == last) {
					mat[i][j] = ++acum;
				} else {
					acum = 1;
					mat[i][j] = acum;
					last = act;
				}
			}
		}
		
		int ans = binarySearch(Math.min(N, M), mat);
		bw.write(ans * ans + "\n");
		
		
		bw.close();

	}
	
	static int binarySearch (int max, int [][] mat) {
		int min = 0;
		int ans = 0;
		while (min <= max) {
			int mid = (min + max) / 2;
			if (possible(mat, mid)) {
				min = mid+1;
				ans = mid;
			}
			else
				max = mid - 1;
		}
		
		return ans;
	}
	
	static boolean possible (int [][] mat, int obj) {
		
		for (int j = 0; j < mat[0].length; j++) {
			int acum = 0;
			for (int i = 0; i < mat[0].length; i++) {
				if (mat[i][j] >= obj)
					acum++;
				else
					acum = 0;
				if (acum >= obj) 
					return true;
			}
		}
		return false;
	}

}
