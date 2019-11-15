package upsolving_regonials_2019;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class G {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String city = br.readLine();
		int N = Integer.parseInt(br.readLine());
		
		SuffixAutomaton suf = new SuffixAutomaton();
		for (int i = 0; i < suf.maxn; i++) {
			suf.to[i] = new HashMap<Character, Integer>();
		}
	
		suf.addCharacter(city);
		
		for (int cas = 0; cas < N; cas++) {
			String friend = br.readLine();
			int count = 0;
			HashMap<Character, Integer> actNode = new HashMap<Character, Integer>();
			for (char act : friend.toCharArray()) {
				if (actNode.containsKey(act)) {
					actNode = suf.to[actNode.get(act)];
				} else {
					count++;
					actNode = suf.to[0];
					if (actNode.containsKey(act)) {
						actNode = suf.to[actNode.get(act)];
					} else {
						count = -1;
						break;
					}
				}
			}
			bw.write(count + "\n");
		}
		bw.close();
	}

}

class SuffixAutomaton {
	static final int maxn = 4*100009;
	static int [] len = new int[maxn];
	static int [] link = new int[maxn];
	static int[][] count = new int [2][maxn];
	static boolean vis[] = new boolean[maxn];
	
	static HashMap<Character, Integer> to [] = new HashMap [maxn];
	static int size = 0, last, res;
	
	public SuffixAutomaton() {
		link [0] = -1;
		size = 1;
		last = res = 0;
	}
	
	public static void addCharacter(String s) {
		for (char c : s.toCharArray()) {
			int p = last;
			last = size++;
			len[last] = len[p] + 1;
			for (; p != -1 && !to[p].containsKey(c); p = link[p])
				to[p].put(c, last);
			if (p == -1)
				continue;
			int q = to[p].get(c);
			if (len[q] == len[p] + 1) {
				link[last] = q;
				continue;
			}
			
			int c1 = size++;
			to[c1].putAll(to[q]);
			link[c1] = link[q];
			len[c1] = len[p] + 1;
			link [last] = link [q] = c1;
			for (; p != -1 && to[p].containsKey(c) && to[p].get(c) == q; p = link[p])
				to[p].put(c, c1);
		}
	}
}
