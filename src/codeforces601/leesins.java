package codeforces601;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * leesins
 */
public class leesins {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        
        int n = Integer.parseInt(br.readLine());
        List<Integer []> [] triplets = new List [n + 3];
        int [] app = new int [n + 3];
        for (int i = 0; i < n + 3; i++)
            triplets[i] = new ArrayList<Integer []>();

        for (int cas = 0; cas < n - 2; cas++){
            StringTokenizer token = new StringTokenizer(br.readLine());
            Integer [] permu = new Integer [3];
            for (int i = 0; i < 3; i++){
                int index = Integer.parseInt(token.nextToken());
                permu[i] = index;
                triplets[index].add(permu);
                app[index]++;
            }
        }
        int index = 0;
        for (int i = 0; i < n + 3; i++){
            if (app[i] == 1){
                index = i;
                break;
            }
        }
        int [] real = new int [n];
        real[0] = index;
        Integer [] permu = triplets[index].get(0);

        List<Integer> others = new ArrayList<>();
        for (int elem : permu)
            if (elem != index)
                others.add(elem);

        List<Integer []> firstOption = triplets[others.get(0)];
        List<Integer []> secondOption = triplets[others.get(1)];

        int index2 = 0;
        int index3 = 0;
        Integer [] other = null;
        if (firstOption.size() == 2){
            index2 = others.get(0);
            index3 = others.get(1);
            other = firstOption.get(0) == permu ? firstOption.get(1) : firstOption.get(0);
        } else {
            index2 = others.get(1);
            index3 = others.get(0);
            other = secondOption.get(0) == permu ? secondOption.get(1) : secondOption.get(0);
        }

        real[1] = index2;
        real[2] = index3;
        
        int actIndex = 3;

        for (int act : other){
            if (act != index2 && act != index3){
                index = index2;
                index2 = index3;
                index3 = act;
                break;
            }
        }
        while (actIndex < n){
            real[actIndex++] = index3;
            List<Integer []> moreOptions = triplets[index3];
            boolean possible1 = false;
            boolean possible2 = false;
            for (Integer[] numb: moreOptions){
                int inter = 0;
                for (int xd: numb){
                    if (xd == index){
                        possible1 = false;
                        possible2 = false;
                        break;
                    } else if (xd == index3){
                        possible2 = true;
                    } else if (xd == index2){
                        possible1 = true;
                    } else {
                        inter = xd;
                    }
                }
                if (possible1 && possible2){
                    index = index2;
                    index2 = index3;
                    index3 = inter;
                    break;
                } else {
                    possible1 = false;
                    possible2 = false;
                }
            }

        }
        
        // real[actIndex] = index3;
        
        for (int act: real){
            bw.write(act + " ");
        }
        bw.close();
    }
    
}