package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Tram {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] initData = br.readLine().split(" ");
		int s = Integer.parseInt(initData[0]);
		int x1 = Integer.parseInt(initData[1]);
		int x2 = Integer.parseInt(initData[2]);
		
		int totDist = x2 - x1;
		
		String [] times = br.readLine().split(" ");
		int t1 = Integer.parseInt(times[0]);
		int t2 = Integer.parseInt(times[1]);
		
		int op1 = t2 * Math.abs(totDist);
		
		String trainInfo[] = br.readLine().split(" ");
		int p = Integer.parseInt(trainInfo[0]);
		int d = Integer.parseInt(trainInfo[1]);
		
		int op2 = 0;
		if (d * totDist > 0) {
			if (d == 1) {
				if (p <= x1) {
					op2 = t1*(x2 - p);
				} else {
					op2 = t1*(s - p) + t1*s + t1*x2;
				}
			} else {
				if (p >= x1) {
					op2 = t1* (p - x2);
				} else {
					op2 = t1*p + t1*s + t1*(s-x2);
				}
			}
		} else {
			if (d == 1) {
				op2 = t1 * (s - p) + t1* (s - x2);
			} else {
				op2 = t1 * p + t1 * x2;
			}
		}
		
		System.out.println(Math.min(op1, op2));

	}

}
