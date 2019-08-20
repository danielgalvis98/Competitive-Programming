package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class CaisaAndPylons {

	public static void main(String[] args) throws Exception{
		//sadasdasdadasd
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		String [] data = br.readLine().split(" ");
		int toPay = 0;
		int actEnergy = 0;
		toPay += Integer.parseInt(data[0]);
		for (int i = 1; i < n; i++) {
			int dif = Integer.parseInt(data[i-1]) - Integer.parseInt(data[i]);
			actEnergy += dif;
			if (actEnergy < 0) {
				toPay -= actEnergy;
				actEnergy = 0;
			}
		}
		
		
		
		System.out.println(toPay);

		
		
		
	}

}
