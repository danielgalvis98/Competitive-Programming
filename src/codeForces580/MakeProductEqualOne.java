package codeForces580;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MakeProductEqualOne {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = Integer.parseInt(br.readLine());
		String [] numbers = br.readLine().split(" ");
		long totNegatives = 0;
		boolean isZero = false;
		long acumulator = 0;
		for (String number: numbers) {
			long numberInt = Long.parseLong(number);
			if (numberInt == 0) isZero = true;
			else if (numberInt < 0) totNegatives++;
			acumulator +=Math.abs(Math.abs(numberInt) - 1);
			
		}
		if (totNegatives % 2 == 0) {
			System.out.println(acumulator);
		} else {
			if (isZero)
				System.out.println(acumulator);
			else
				System.out.println(acumulator + 2);
		}

	}

}
