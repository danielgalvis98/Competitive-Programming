import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.TreeSet;

public class PowerGenerator {

	static boolean[] primes=new boolean[10000]; 
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//BufferedWriter bw = new BufferedWriter(new FileWriter(new File("./out.txt")));
		fillSieve();
		BigInteger lim = new BigInteger(2 + "");
		lim = lim.pow(64);
		TreeSet<BigInteger> set = new TreeSet<BigInteger>();
		for (long i = 2; i < 100000; i++) {
			int j = 4;
			BigInteger base = new BigInteger(i + "");
			BigInteger act = base.pow(j);
			while(act.compareTo(lim) < 0) {
				if (!isPrime(j)) {
					set.add(act);
				}
				act = act.multiply(base);
				j++;
			}
		}
		
		bw.write("1\n");
		for (BigInteger a : set) {
				bw.write(a.toString()+"\n");
		}
		bw.close();
			

	}
	//set up the primesieve
	public static void fillSieve() {
		Arrays.fill(primes,true);        // assume all integers are prime.
		primes[0]=primes[1]=false;       // we know 0 and 1 are not prime.
		for (int i=2;i<primes.length;i++) {
			//if the number is prime, 
			//then go through all its multiples and make their values false.
			if(primes[i]) {
				for (int j=2;i*j<primes.length;j++) {
					primes[i*j]=false;
				}
			}
		}
	}
	
	public static boolean isPrime(int n) {
		return primes[n]; //simple, huh?
	}
	

}
