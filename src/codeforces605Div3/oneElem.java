package codeforces605Div3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
/**
 * oneElem
 */
public class oneElem {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int [] arr = new int[n];
        StringTokenizer token = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(token.nextToken());
        
        List <Integer> subs = new ArrayList<>();
        subs.add(-1);
        int last = arr[0];
        for (int i = 1; i < n; i++){
            int newElem = arr[i];
            if (newElem <= last)
                subs.add(i-1);
            last = newElem;
        }
        subs.add(n-1);
        int size = subs.size();
        int lastIndex = -1;
        int ans = 1;
        for (int i = 1; i < size - 1; i++){
            int newIndex = subs.get(i);
            int subSize = newIndex - lastIndex;
            if (subSize != 1){
                int nextIndex = subs.get(i+1);
                int nextSize = nextIndex - newIndex;
                if (nextSize != 1){
                    if ((newIndex != n-2 && arr[newIndex] < arr[newIndex + 2])
                        || (newIndex != 0 && arr[newIndex - 1] < arr[newIndex + 1])){
                        subSize+= nextSize - 1;
                    }
                } else {
                    if (newIndex != n-2 && arr[newIndex] < arr[newIndex + 2]){
                        int nextNext = subs.get(i+2);
                        int newSize = nextNext - nextIndex;
                        subSize += newSize;
                    }
                }
                ans = Math.max(ans, subSize);

            }
            lastIndex = newIndex;

        }
        ans = Math.max(ans, subs.get(size-1) - subs.get(size - 2));
        bw.write(ans + "\n");
        bw.close();
    }
}