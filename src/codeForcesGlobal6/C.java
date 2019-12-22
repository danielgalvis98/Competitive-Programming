package codeForcesGlobal6;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
/**
 * C
 */
public class C {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(token.nextToken());
        int c = Integer.parseInt(token.nextToken());

        if (r == 1 && c == 1)
            bw.write("0\n");
        else{
            long [][] mat = new long[r][c];
            if (r==1 || c == 1){
                for (int i = 0; i < r; i++){
                    for (int j = 0; j < c; j++){
                        mat[i][j]= i+j+2;
                    }
                }
            } else {
                mat[0][0]=2;
                mat[0][1]=3;
                mat[1][0]=4;
                mat[1][1]=12;
                int rows[] = new int[r];
                int cols[] = new int [c];
                
                rows[0]=1;
                rows[1]=4;
                cols[0]=2;
                cols[1]=3;

                int actRow = 2;
                int actCol = 2;
                int actDiv = 5;
                while(actCol < c){
                    cols[actCol]=actDiv;
                    for (int i = 0; i < actRow; i++)
                        mat[i][actCol] = ((long)actDiv)*rows[i];
                    actCol++;
                    actDiv++;
                }

                while (actRow < r){
                    rows[actRow] = actDiv;
                    for (int j = 0; j < actCol; j++)
                        mat[actRow][j] = actDiv*cols[j];
                    actRow++;
                    actDiv++;
                }
            }
            for (int i = 0; i < r; i++){
                bw.write(mat[i][0] + "");
                for (int j = 1; j < c; j++){
                    bw.write(" " + mat[i][j]);
                }
                bw.write("\n");
            }
        }
        bw.close();
    }
}