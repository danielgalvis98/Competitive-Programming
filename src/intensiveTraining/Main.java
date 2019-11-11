package intensiveTraining;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String line = br.readLine();
		while (line != null) {
			int N = Integer.parseInt(line);
			
			int rows = 2*N;
			int columns = rows + 1;
			int total = rows * columns;
			
			node [] nodes = new node[total];
			for (int i = 0; i < total; i++) {
				nodes[i] = new node(i);
			}
			
			
			for (int i = 0; i < columns-1; i+=2) {
				node node1 = nodes[i+1];
				node node2 = nodes [i+2];
				
				node1.adj.add(node2);
				node2.adj.add(node1);
				
				
				node1 = nodes[(rows-1)*columns+i+1];
				node2 = nodes[(rows-1)*columns+i+2];
				node1.adj.add(node2);
				node2.adj.add(node1);
			}
			
			for (int i = 0; i < rows; i += 2) {
				if (i < rows-2) {
					node node1 = nodes[(i+1)*columns];
					node node2 = nodes[(i+2)*columns];
					
					node1.adj.add(node2);
					node2.adj.add(node1);
				}
				node node1 = nodes[i*(columns) + columns-1];
				node node2 = nodes[(i+1)*(columns) + columns - 1];
				
				node1.adj.add(node2);
				node2.adj.add(node1);
			
			}
			
			for (int i = 0; i < rows - 1; i++) {
				String row = br.readLine();
				for (int j = 0, lim = row.length(); j < lim; j++) {
					char act = row.charAt(j);
					if (i % 2 == 0) {
						int actPos = j*2 + columns*i;
						int right = actPos + 1;
						int down = actPos + columns;
						int diag = down + 1;						
						
						if (act == 'H') {
							node node1 = nodes[actPos];
							node node2 = nodes[right];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
							node1 = nodes[down];
							node2 = nodes[diag];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
				
						} else {
							node node1 = nodes[actPos];
							node node2 = nodes[down];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
							node1 = nodes[right];
							node2 = nodes[diag];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
						}
					} else {
						int actPos = (j+1)*2 + columns*i - 1;
						int right = actPos + 1;
						int down = actPos + columns;
						int diag = down + 1;
						if (act == 'H') {
							node node1 = nodes[actPos];
							node node2 = nodes[right];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
							node1 = nodes[down];
							node2 = nodes[diag];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
						} else {
							node node1 = nodes[actPos];
							node node2 = nodes[down];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
							
							node1 = nodes[right];
							node2 = nodes[diag];
							
							node1.adj.add(node2);
							node2.adj.add(node1);
						}
					}
				}
				
			}
			
			int components = bfs(nodes);
			
			bw.write(components - 1 + "\n");
			
			
			line = br.readLine();
		}
		
		bw.close();

	}
	
	static int bfs (node[] nodes) {
		int total = 0;
		for (int i = 0, l = nodes.length; i < l; i++) {
			node act = nodes[i];
			if (!act.visited) {
				total++;
				
				
				Queue<node> cola = new LinkedList<node>();
				cola.add(act);
				while (!cola.isEmpty()) {
					node index = cola.poll();
					for (node adj: index.adj) {
						if (!adj.visited) {
							adj.visited = true;
							cola.add(adj);
						}
					}
				}
				
			}
		}
		return total;
	}
	

}

class node {
	int pos;
	List<node> adj;
	boolean visited = false;
	
	node(int pos){
		this.pos = pos;
		adj = new ArrayList<node>();
	}
}