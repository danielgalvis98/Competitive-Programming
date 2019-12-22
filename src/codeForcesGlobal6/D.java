package codeForcesGlobal6;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * D
 */
public class D {
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n,m;
        StringTokenizer token = new StringTokenizer(br.readLine());
        n = Integer.parseInt(token.nextToken());
        m = Integer.parseInt(token.nextToken());
        
        int debts = 0;
        List<Map<Integer, Long>> nodes = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
        nodes.add(new HashMap<>());
        for (int i = 0; i < m; i++){
            token = new StringTokenizer(br.readLine());
            int nodeA = Integer.parseInt(token.nextToken()) - 1;
            int nodeB = Integer.parseInt(token.nextToken()) - 1;
            long debt = Long.parseLong(token.nextToken());
            if (nodeA == nodeB) continue;
            Map <Integer, Long> theMap = nodes.get(nodeA);
            if (theMap.containsKey(nodeB))
                theMap.put(nodeB, theMap.get(nodeB) + debt);
                else{
                theMap.put(nodeB,debt);
                debts++;
            }
        }
        
        boolean changes = true;
        while (changes){
            changes=false;
            for (int i = 0; i < n; i++){
                Map<Integer, Long> act = nodes.get(i);
                for (int adj: act.keySet()){
                    long debt = act.get(adj);
                    Map<Integer, Long> mapAdj = nodes.get(adj);
                    for (int adjadj: mapAdj.keySet()){
                        changes=true;
                        long debt2 = mapAdj.get(adjadj);
                        long min = Math.min(debt, debt2);
                        debt2 -= min;
                        if (debt2 == 0){
                            mapAdj.remove(adjadj);
                            debts--;
                        } else {
                            mapAdj.put(adjadj, debt2);
                        }
    
                        if (act.containsKey(adjadj))
                            act.put(adjadj, act.get(adjadj) + min);
                        else if (i != adjadj){
                            act.put(adjadj, min);
                            debts++;
                        }
                        
                        debt -= min;
                        if (debt == 0) break;
                    }
                    if (debt == 0){
                        debts--;
                        act.remove(adj);
                    } else {
                        act.put(adj, debt);
                    }
                }
            }

        }
        bw.write(debts+"\n");
        for (int i = 0; i < n; i++){
            for (int key : nodes.get(i).keySet())
            bw.write((i+1) + " " + (key+1) + " " + nodes.get(i).get(key) + "\n");
        }
        bw.close();
    }

    
}