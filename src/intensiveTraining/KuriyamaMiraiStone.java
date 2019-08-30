package intensiveTraining;

public class KuriyamaMiraiStone {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	

}

class BinaryIndexedTreeSum {
	// Max tree size
	final static int MAX = 100005;

	static long BITree[] = new long[MAX];

	/*
	 * n --> No. of elements present in input array. BITree[0..n] --> Array that
	 * represents Binary Indexed Tree. arr[0..n-1] --> Input array for whic prefix
	 * sum is evaluated.
	 */

	// Returns sum of arr[0..index]. This function
	// assumes that the array is preprocessed and
	// partial sums of array elements are stored
	// in BITree[].
	long getSum(int index) {
		long sum = 0; // Iniialize result

		// index in BITree[] is 1 more than
		// the index in arr[]
		index = index + 1;

		// Traverse ancestors of BITree[index]
		while (index > 0) {
			// Add current element of BITree
			// to sum
			sum += BITree[index];

			// Move index to parent node in
			// getSum View
			index -= index & (-index);
		}
		return sum;
	}

	public static void updateBIT(int n, int index, long val) {
// index in BITree[] is 1 more than  
// the index in arr[] 
		index = index + 1;

// Traverse all ancestors and add 'val' 
		while (index <= n) {
// Add 'val' to current node of BIT Tree 
			BITree[index] += val;

// Update index to that of parent  
// in update View 
			index += index & (-index);
		}
	}

	/*
	 * Function to construct fenwick tree from given array.
	 */
	void constructBITree(long arr[], int n) {
// Initialize BITree[] as 0 
		for (int i = 1; i <= n; i++)
			BITree[i] = 0;

// Store the actual values in BITree[] 
// using update() 
		for (int i = 0; i < n; i++)
			updateBIT(n, i, arr[i]);
	}
}




class BinaryIndexedTreeMin {
	// Max tree size
	final static int MAX = 100005;

	static long BITree[] = new long[MAX];

	/*
	 * n --> No. of elements present in input array. BITree[0..n] --> Array that
	 * represents Binary Indexed Tree. arr[0..n-1] --> Input array for whic prefix
	 * sum is evaluated.
	 */

	// Returns sum of arr[0..index]. This function
	// assumes that the array is preprocessed and
	// partial sums of array elements are stored
	// in BITree[].
	long getMin(int index) {
		long min = Long.MIN_VALUE; // Iniialize result

		// index in BITree[] is 1 more than
		// the index in arr[]
		index = index + 1;

		// Traverse ancestors of BITree[index]
		while (index > 0) {
			// Add current element of BITree
			// to sum
			min = Math.min(BITree[index], min);

			// Move index to parent node in
			// getSum View
			index -= index & (-index);
		}
		return min;
	}

	public static void updateBIT(int n, int index, long val) {
// index in BITree[] is 1 more than  
// the index in arr[] 
		index = index + 1;

// Traverse all ancestors and add 'val' 
		while (index <= n) {
// Add 'val' to current node of BIT Tree 
			BITree[index] += val;

// Update index to that of parent  
// in update View 
			index += index & (-index);
		}
	}

	/*
	 * Function to construct fenwick tree from given array.
	 */
	void constructBITree(long arr[], int n) {
// Initialize BITree[] as 0 
		for (int i = 1; i <= n; i++)
			BITree[i] = 0;

// Store the actual values in BITree[] 
// using update() 
		for (int i = 0; i < n; i++)
			updateBIT(n, i, arr[i]);
	}
}