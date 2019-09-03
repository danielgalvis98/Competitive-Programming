package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class LovelyPalindromes {

	public static void main(String[] args) throws IOException {
		String numb = (new BufferedReader(new InputStreamReader(System.in)).readLine());
		
		StringBuilder builder = new StringBuilder(numb);
		for (int i = numb.length() - 1; i >= 0; i--) {
			builder.append(numb.charAt(i) + "");
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(
				builder.toString() + "\n");
		
		bw.close();
	}

}
