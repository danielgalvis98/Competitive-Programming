package codeForces600;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class antena {
    private static List<lamp> lamps = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer token = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(token.nextToken());
        int m = Integer.parseInt(token.nextToken());
        for (int i = 0; i < n; i++) {
            token = new StringTokenizer(br.readLine());
            int center = Integer.parseInt(token.nextToken());
            int radio = Integer.parseInt(token.nextToken());
            int left = center - radio;
            int right = center + radio;
            lamps.add(new lamp(left, right, center));
        }

        lamps.sort(new Comparator<lamp>() {
            @Override
            public int compare(lamp o1, lamp o2) {
                return o1.center - o2.center;
            }
        });
        
        int coins = solution(lamps.size() - 1, m);

        bw.write(coins + "\n");
        bw.close();
    }

    static int solution(int i, int m) {
        if (m <= 0)
            return 0;

        lamp act = lamps.get(i);
        if (i == 0)
            return Math.max(Math.max(act.left - 1, m - act.right), 0);

        if (act.right >= m) {
            m = Math.min(m, act.left - 1);
            return solution(i - 1, m);
        }

        int op1 = 0;
        op1 = solution(i - 1, m);

        int op2 = 0;
        int dif = m - act.right;
        op2 = dif;
        op2 += solution(i - 1, act.left - dif - 1);

        return Math.min(op1, op2);
    }
}

class lamp {
    int left;
    int right;
    int center;

    lamp(int a, int b, int c) {
        left = a;
        right = b;
        center = c;
    }
}