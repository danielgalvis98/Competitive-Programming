package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Decoding {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int totLength = Integer.parseInt(br.readLine());
		
		String codedWord = br.readLine();
		
		
		char [] decoded = new char [totLength];
		
		int middle = totLength / 2;
		boolean putLeft = totLength % 2 == 0;
		int actLeft;
		int actRight;
		
		actLeft = middle - 1;
		actRight = middle;
		
		for (char character : codedWord.toCharArray()) {
			if (putLeft) {
				decoded[actLeft--] = character;
			} else {
				decoded[actRight++] = character;
			}
			putLeft = !putLeft;
		}
		
		System.out.println(new String(decoded));
	}

}
