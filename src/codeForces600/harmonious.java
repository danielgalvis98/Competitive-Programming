package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class harmonious {
    
    static int max = 0;
    static int min = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        node [] nodes=  new node [n + 3];
        for (int i = 1; i <= n; i++){
            nodes[i] = new node(i);
        }
        for (int i = 0; i < m; i++){
            tokenizer = new StringTokenizer(br.readLine());
            node node1 = nodes[Integer.parseInt(tokenizer.nextToken())];
            node node2 = nodes[Integer.parseInt(tokenizer.nextToken())];
            
            node1.adj.add(node2);
            node2.adj.add(node1);
        }

        int addEdges = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++){
            node act = nodes[i];
            if (!act.visited){
                if (i < max)
                    addEdges++;
                int bfsMax = bfs(act);
                max = Math.max(bfsMax, max);
            }
        }

        bw.write(addEdges + "\n");

        bw.close();
    }

    static int bfs (node theNode){
        int max = 0;
        min = Integer.MAX_VALUE;
        max = Integer.MIN_VALUE;
        theNode.visited = true;
        Queue<node> cola = new LinkedList<node>();
        cola.add(theNode);
        while(!cola.isEmpty()){
            node act = cola.poll();
            max = Math.max(max, act.id);
            for (node adj : act.adj){
                if (!adj.visited){
                    adj.visited = true;
                    cola.add(adj);
                }
            }
        }
        return max;
    }
}

class node {
    int id;
    List<node> adj;
    boolean visited;
    public node (int id){
        this.id = id;
        adj = new ArrayList<>();
    }
}