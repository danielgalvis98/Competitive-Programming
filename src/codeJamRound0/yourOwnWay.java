package codeJamRound0;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class yourOwnWay {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int  T = Integer.parseInt(br.readLine());
		for (int test = 1; test <= T; test++) {
			int N = Integer.parseInt(br.readLine());
			char [] lydia = br.readLine().toCharArray();
			String ans = "";
			for (int i = 0; i < lydia.length; i++) {
				char act = lydia[i];
				if (act == 'S') {
					ans += 'E';
				} else {
					ans += 'S';
				}
			}
			bw.write("Case #" + test + ": " + ans + "\n");
		}
		bw.close();
	}
}
