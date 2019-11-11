package upsolving_regonials_2019;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class K {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String input = br.readLine();
		
		char initial = input.charAt(0);
		
		boolean startsPositive = initial == 'H';
		
		List<Long> lists = new ArrayList<Long>();
		
		lists.add(1l);
		
		for (int i = 1, l = input.length(); i < l; i++) {
			char act = input.charAt(i);
			if (act != initial) {
				long pos = 2*i +1;
				initial = act;
				lists.add(0l);
				for (int j = lists.size() - 1; j > 0; j--) {
					lists.set(j, lists.get(j) + lists.get(j-1)*pos);
				}
		
			}
		}
		
		boolean pair = lists.size() % 2 == 0;
		int sign = pair ^ startsPositive ? 1 : -1;
		
		int listSize = lists.size();
		bw.write((listSize - 1) + "\n");
		
		for (int i = 0; i < lists.size() - 1; i++) {
			bw.write(lists.get(i)*sign + " ");
			sign *= -1;
		}
		
		bw.write(lists.get(listSize - 1)*sign + "\n") ;
		
		bw.close();
	}

}
