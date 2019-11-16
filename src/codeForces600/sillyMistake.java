package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class sillyMistake {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer token = new StringTokenizer(br.readLine());
        Set<Integer> enteredS = new HashSet<>();
        Set<Integer> actStat = new HashSet<>();
        int totInside = 0;
        int totPartitions = 0;
        List<Integer> sizes = new ArrayList<>();
        int startIndex = 0;
        for (int i = 0; i < n; i++){
            int act = Integer.parseInt(token.nextToken());
            if (act < 0){
                if (!actStat.contains(-act)){
                    totInside = -1;
                    break;
                }
                totInside--;
                actStat.remove(-act);
                if (totInside == 0){
                    enteredS = new HashSet<>();
                    totPartitions++;
                    sizes.add(i - startIndex + 1);
                    startIndex = i+1;
                }
            } else {
                if (enteredS.contains(act)){
                    totInside = -1;
                    break;
                }
                actStat.add(act);
                enteredS.add(act);
                totInside++;
            }
        }
        if (totInside != 0)
            bw.write("-1\n");
        else {
            bw.write(totPartitions + "\n");
            bw.write(sizes.get(0) + "");
            for (int i = 1; i < sizes.size(); i++){
                bw.write(" " + sizes.get(i));
            }
            bw.write("\n");
        }
        bw.close();
    }
}