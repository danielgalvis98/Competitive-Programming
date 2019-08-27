package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PetyaAndStrings {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String first = br.readLine().toLowerCase();
		String second = br.readLine().toLowerCase();
		
		int compare = first.compareTo(second);
		if (compare<0) {
			System.out.println("-1");
		} else if (compare > 0) {
			System.out.println("1");
		} else {
			System.out.println("0");
		}

	}

}
