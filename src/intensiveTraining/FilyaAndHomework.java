package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.TreeSet;

public class FilyaAndHomework {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		String [] array = br.readLine().split(" ");
		
		TreeSet<Long> set = new TreeSet<>();
		
		int total = 0;
		for (int i = 0; i < n && total <= 3; i++) {
			long numb = Long.parseLong(array[i]);
			if (!set.contains(numb)) {
				total++;
				set.add(numb);
			}
		}
		if (total > 3)
			bw.write("NO\n");
		else if (total <= 2)
			bw.write("YES\n");
		else {
			long first = set.pollFirst();
			long second = set.pollFirst();
			long third = set.pollFirst();
			if (second - first == third - second) {
				bw.write("YES\n");
			} else {
				bw.write("NO\n");
			}
		}
		bw.close();

	}

}
