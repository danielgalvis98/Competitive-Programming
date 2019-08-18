package intensiveTraining;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AntonAndDanik {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		
		String winners = br.readLine();
		
		int Anton = 0;
		int Danik = 0;
		for (char winner: winners.toCharArray()) {
			if (winner == 'A')
				Anton++;
			else
				Danik++;
		}
		
		if (Anton > Danik) {
			System.out.println("Anton");
		} else if (Danik > Anton) {
			System.out.println("Danik");
		} else {
			System.out.println("Friendship");
		}

	}

}
