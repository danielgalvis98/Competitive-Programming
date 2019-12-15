package codeforces605Div3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
/**
 * snowWalkingRobot
 */
public class snowWalkingRobot {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int q = Integer.parseInt(br.readLine());
        for (int cas = 0; cas < q; cas++){
            int totU = 0;
            int totD = 0;
            int totL = 0;
            int totR = 0;
            String line = br.readLine();
            for (char x: line.toCharArray()){
                if (x == 'L') totL++;
                else if (x == 'R') totR++;
                else if (x == 'D') totD++;
                else totU++;
            }

            int totVert = Math.min(totU, totD);
            int totHor = Math.min(totL, totR);
            if (totVert == 0 && totHor == 0){
                bw.write("0\n");
                continue;
            }

            if (totVert == 0){
                bw.write("2\n");
                bw.write("LR\n");
                continue;
            }

            if (totHor == 0){
                bw.write("2\n");
                bw.write("UD\n");
                continue;
            }


            bw.write((totVert + totHor)*2 + "\n");
            for (int i = 0; i < totVert; i++)
                bw.write("U");

            for (int i = 0; i < totHor; i++)
              bw.write("R");
            
            for (int i = 0; i < totVert; i++)
                bw.write("D");

            for (int i = 0; i < totHor; i++)
                bw.write("L");
            
            bw.write("\n");
        }
        bw.close();
    }
}