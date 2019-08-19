package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BurglarAndMatches {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] initData = br.readLine().split(" ");
		int n = Integer.parseInt(initData[0]);
		int m = Integer.parseInt(initData[1]);
		Container [] containers = new Container [m];
		for (int i = 0; i < m; i++) {
			String [] containerData = br.readLine().split(" ");
			containers[i] = new Container(Integer.parseInt(containerData[0]),
					Integer.parseInt(containerData[1]));
		}
		Arrays.sort(containers);
		int totMatches = 0;
		int totMatchBoxs = 0;
		m--;
		while (totMatchBoxs < n && m >= 0) {
			Container act = containers[m];
			if (totMatchBoxs + act.matchboxes > n) {
				totMatches += (n - totMatchBoxs) * act.matchsPerMatchbox;
				totMatchBoxs = n;
			} else {
				totMatches += act.matchboxes * act.matchsPerMatchbox;
				totMatchBoxs += act.matchboxes;
				m--;
			}
		}
		System.out.println(totMatches);

	}

}

class Container implements Comparable<Container>{
	int matchboxes;
	int matchsPerMatchbox;
	Container (int a, int b){
		matchboxes = a;
		matchsPerMatchbox = b;
	}
	@Override
	public int compareTo(Container o) {
		// TODO Auto-generated method stub
		return matchsPerMatchbox - o.matchsPerMatchbox;
	}
}
