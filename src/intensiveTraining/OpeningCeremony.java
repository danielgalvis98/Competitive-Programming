	package intensiveTraining;
	
	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.InputStreamReader;
	import java.io.OutputStreamWriter;
	import java.util.Comparator;
	import java.util.Iterator;
	import java.util.StringTokenizer;
	import java.util.TreeMap;
	
	public class OpeningCeremony {
	
		public static void main(String[] args) throws Exception{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int n = Integer.parseInt(br.readLine());
			StringTokenizer token = new StringTokenizer(br.readLine());
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>(new Comparator<Integer>() {
				public int compare (Integer i1, Integer i2) {
					return i2 - i1;
				}
			});
			
			while (token.hasMoreTokens()) {
				int height = Integer.parseInt(token.nextToken());
				if (map.containsKey(height)) {
					int actValue = map.get(height);
					map.put(height, actValue + 1);
				} else {
					map.put(height, 1);
				}
			}
			bw.write(minShots(map, map.keySet().iterator()) + "\n");
			
			bw.close();
	
		}
		
		static int minShots (TreeMap<Integer, Integer> map, Iterator<Integer> it) {
			int height = it.next();
			int buildings = map.get(height);
			
			if (!it.hasNext()) {
				return Math.min(height, buildings);
			}
			
			
			return Math.min(height, buildings + minShots(map, it));
		}
	
	}
