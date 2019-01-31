package trie;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class RegistrationSystem {
	
	static Trie root = new Trie(null);
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
		int users = Integer.parseInt(lector.readLine());
		for (int i = 0; i < users; i++) {
			String userName = lector.readLine();
			System.out.print(userName);
			addUser(userName);
		}
	}
	
	static void update (Trie trie) {
		while (trie.parent != null) {
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < 10; i++) {
				if (trie.childs[i] == null || !trie.childs[i].set) {
					min = -1;
					break;
				} else {
					min = trie.childs[i].minPath < min ? trie.childs[i].minPath : min;
				}
			}
			trie.minPath = min + 1;
			trie = trie.parent;
		}
	}
	
	static void addUser (String userName) {
		Trie actualTrie = root;
		int userLength = userName.length();
		for (int i = 0; i < userLength; i++) {
			char digit = userName.charAt(i);
			int index;
			if (digit >= '0' && digit <= '9') {
				index = Integer.parseInt(digit + "");
			} else {
				index = 10 + digit - 'a';
			}
			if (actualTrie.childs[index] == null) {
				actualTrie.childs[index] = new Trie(actualTrie);
			}
			actualTrie = actualTrie.childs[index];
		}
		
		if (!actualTrie.set) {
			actualTrie.set = true;
			update (actualTrie);
			System.out.println();
			return;
		} else {
			
			if (actualTrie.minPath == 0) {
				for (int i = 0; i < 10; i++) {
					Trie child = actualTrie.childs[i];
					if (child == null || !child.set ) {
						child = child == null? new Trie(actualTrie) : child;
						child.set = true;
						actualTrie.childs [i] = child;
						System.out.println(i);
						update (child);
						return;
					}
				}
			} else {
				int min = Integer.MAX_VALUE;
				int indexMin = -1;
				for (int i = 9; i >= 0; i--) {
					Trie child = actualTrie.childs[i];
					if (child == null || child.minPath <= min) {
						child = child == null? new Trie(actualTrie) : child;
						actualTrie.childs [i] = child;
						min = child.minPath;
						indexMin = i;
					}
				}
				System.out.print(indexMin);
				actualTrie = actualTrie.childs[indexMin];
				min = Integer.MAX_VALUE;
				indexMin = -1;
				while (actualTrie.minPath != 0) {
					for (int i = 0; i < 10; i++) {
						Trie child = actualTrie.childs[i];
						if (child != null && child.minPath < min) {
							min = child.minPath;
							indexMin = i;
						}
					}
					System.out.print(indexMin);
					actualTrie = actualTrie.childs[indexMin];
				}
				min = Integer.MAX_VALUE;
				indexMin = -1;
				for (int i = 0; i < 10; i++) {
					Trie child = actualTrie.childs[i];
					if (child == null || !child.set ) {
						child = child == null? new Trie(actualTrie) : child;
						child.set = true;
						System.out.println(indexMin);
						actualTrie.childs [i] = child;
						update(child);
						return;
					}
				}
			}
		}
	}

}

class Trie {
	boolean set = false;
	
	int minPath = 0;
	
	Trie parent;
	
	Trie [] childs = new Trie [36];
	
	Trie (Trie par) {
		parent = par;
	}
	
}
