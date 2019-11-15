package upsolving_regonials_2019;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class I {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer token = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(token.nextToken());
		int L = Integer.parseInt(token.nextToken());
		
		node [] nodes = new node[N];
		for (int i = 0; i < L; i++) {
			nodes[i] = new node(i, 0);
		}
		for (int i = L; i < N; i++) {
			nodes[i] = new node(i, 1);
		}
		
		for (int i = 0; i < L; i++) {
			token = new StringTokenizer(br.readLine());
			int K = Integer.parseInt(token.nextToken());
			for (int j = 0; j < K; j++) {
				int adj = Integer.parseInt(token.nextToken()) - 1;
				nodes[i].adj.add(nodes[adj]);
			}
		}
		
		node initial = nodes[0];
		initial.dfs();
		bw.write(initial.totSent + " " + initial.totVisited + "\n");
		bw.close();
	}

}

class node {
	static int modulo = 1000000007;
	int id;
	List<node> adj;
	boolean visited;
	long totSent;
	long totVisited;
	node(int id, long totSent){
		this.id = id;
		adj = new ArrayList<>();
		this.totSent = totSent;
		this.totVisited = totSent;
	}
	
	void dfs () {
		visited = true;
		for (node adjacent : adj) {
			if (adjacent.visited) {
				totSent += adjacent.totSent;
				totSent %= modulo;
			}
			else {
				adjacent.dfs();
				totSent += adjacent.totSent;
				totVisited += adjacent.totVisited;
				totSent %= modulo;
				totVisited %= modulo;
			}
		}
	}
}
