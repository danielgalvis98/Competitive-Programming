package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Coins {
	static String aWithB = null;
	static String bWithC = null;
	static String aWithC = null;
	
	static int firstPosB;
	static int secondPosB;
	static int firstPosC;
	static int secondPosC;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line1 = br.readLine();
		String line2 = br.readLine();
		String line3 = br.readLine();
		
		readLine(line1);
		readLine(line2);
		readLine(line3);
		
		if (firstPosB != secondPosB) {
			if (secondPosC != firstPosC) {
				System.out.println("Impossible");
			} else if (firstPosB == 0) {
				System.out.println("CBA");
			} else {
				System.out.println("ABC");
			}
		} else {
			if (firstPosB == 0) {
				if (secondPosC == 0) {
					System.out.println("BCA");
				} else {
					System.out.println("BAC");
				}
			} else {
				if (secondPosC == 0) {
					System.out.println("CAB");
				} else {
					System.out.println("ACB");
				}
			}
		}
		

	}
	
	public static void readLine(String line)
	{
		char first = line.charAt(0);
		char comparison = line.charAt(1);
		char second = line.charAt(2);
		if (first == 'A') {
			if (second == 'B') {
				if (comparison == '<') {
					aWithB = "AB";
					firstPosB = 1;
				} else {
					aWithB = "BA";
					firstPosB = 0;
				}
			} else {
				if (comparison == '<') {
					aWithC = "AC";
					secondPosC = 1;
				} else {
					aWithC = "CA";
					secondPosC = 0;
				}
			}
			
			
		} else if (first == 'B') {
			if (second == 'C') {
				if (comparison == '<') {
					bWithC = "BC";
					secondPosB = 0;
					firstPosC = 1;
				} else {
					bWithC = "CB";
					secondPosB = 1;
					firstPosC = 0;
				}
			} else {
				if (comparison == '<') {
					aWithB = "BA";
					firstPosB = 0;
				} else {
					aWithB = "AB";
					firstPosB = 1;
				}
			}
		} else {
			if (second == 'A') {
				if (comparison == '<') {
					aWithC = "CA";
					secondPosC = 0;
				} else {
					aWithC = "AC";
					secondPosC = 1;
				}
			} else {
				if (comparison == '<') {
					bWithC = "CB";
					secondPosB = 1;
					firstPosC = 0;
				} else {
					bWithC = "BC";
					secondPosB = 0;
					firstPosC = 1;
				}
			}
		}
	}
}
