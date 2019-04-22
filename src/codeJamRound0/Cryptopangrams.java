package codeJamRound0;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Cryptopangrams {

	static int [] primes = generatePrimes();
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int[] primes = generatePrimes();
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String [] data = br.readLine().split(" ");
			int N = Integer.parseInt(data[0]);
			int L = Integer.parseInt(data[1]);
			String [] numbs = br.readLine().split(" ");
			
		}

	}
	
	static int [] generatePrimes () {
		int in = 0;
		int primes [] = new int [10001];
		boolean [] isNotprimes = new boolean [10001];
		isNotprimes [0] = isNotprimes[1] = true;
		for (int i = 2; i <= 10000; i++) {
			if (!isNotprimes[i]) {
				for (int j = i*i; j <= 10000; j++) {
					isNotprimes[j] = true;
				}
				primes[in++] = i;
			}
		}
		return primes;
	}
	
	static int [] primeFactors (int number) {
		int [] factors = new int [2];
		int ind = 0;
		int pf_idx = 0;
		int PF = primes[pf_idx];
		while (PF * PF <= number && factors[1] == 0){
			if (number % PF == 0) {
				number /= PF;
				factors [ind++] = PF;
			}
			PF = primes[pf_idx++];
		}
		if (number != 1) {
			factors[2] = number;
		}
		return factors;
	}

}
