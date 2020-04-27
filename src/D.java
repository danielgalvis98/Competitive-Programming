import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * D
 */
public class D {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        while (N-- != 0){
            String [] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int l = Integer.parseInt(line[1]);
            int d = Integer.parseInt(line[2]);
            int g = Integer.parseInt(line[3]);

            double initArea = (n*l*l)/(4*Math.tan(Math.PI/n));

            initArea += n*l*d*g + Math.PI*d*g*d*g;

            bw.write(initArea + "\n");
        }

        bw.close();
    }
} 