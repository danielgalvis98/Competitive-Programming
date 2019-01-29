package trie;

public class RegistrationSystem {
	
	Trie root = new Trie(null);
	public static void main(String[] args) {
		
		
	}
	
	void update (Trie trie) {
		while (trie.parent != null) {
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < 10; i++) {
				if (trie.childs[i] == null || !trie.childs[i].set) {
					min = -1;
				} else {
					min = trie.childs[i].minPath < min ? trie.childs[i].minPath : min;
					break;
				}
			}
			trie.minPath = min + 1;
			trie = trie.parent;
		}
	}
	
	void addUser (String userName) {
		Trie actualTrie = root;
		int userLength = userName.length();
		for (int i = 0; i < userLength; i++) {
			char digit = userName.charAt(i);
			int index;
			if (digit >= '0' && digit <= '9') {
				index = Integer.parseInt(digit + "");
			} else {
				index = digit - 'a';
			}
			if (actualTrie.childs[index] == null) {
				actualTrie.childs[index] = new Trie(actualTrie);
			}
			actualTrie = actualTrie.childs[index];
		}
		
		if (!actualTrie.set) {
			actualTrie.set = true;
			return;
		} else {
			
			if (actualTrie.minPath == 0) {
				int min = Integer.MAX_VALUE;
				int indexMin = -1;
				for (int i = 0; i < 10; i++) {
					Trie child = actualTrie.childs[i];
					if (child != null || !child.set ) {
						child = child == null? new Trie(actualTrie) : child;
						child.set = true;
						System.out.print(indexMin);
						return;
					}
				}
			} else {
				int min = Integer.MAX_VALUE;
				int indexMin = -1;
				for (int i = 1; i < 10; i++) {
					Trie child = actualTrie.childs[i];
					if (child != null && !child.set ) {
						child.set = true;
						System.out.print(indexMin);
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
