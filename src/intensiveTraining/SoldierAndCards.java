package intensiveTraining;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class SoldierAndCards {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Queue<Integer> firstPlayer = new LinkedList<Integer> ();
		Queue<Integer> secondPlayer = new LinkedList<Integer>();
		
		HashSet<StatesPassed> gamesPlayed = new HashSet<StatesPassed>();
		
		String [] initFirst = br.readLine().split(" ");
		int totFirst = Integer.parseInt(initFirst[0]);
		for (int i = 1; i <= totFirst; i++) {
			firstPlayer.add(Integer.parseInt(initFirst[i]));
		}
		
		String [] initSecond = br.readLine().split(" ");
		int totSecond = Integer.parseInt(initSecond[0]);
		for (int i = 1; i <= totSecond; i++) {
			secondPlayer.add(Integer.parseInt(initSecond[i]));
		}
		
		int totFights = 0;
		boolean stopGame = false;
		while (!stopGame) {
			StatesPassed actState = new StatesPassed(firstPlayer, secondPlayer);
			if (gamesPlayed.contains(actState)) {
				stopGame = true;
			} else if (firstPlayer.isEmpty() || secondPlayer.isEmpty()) {
				stopGame = true;
			} else {
				gamesPlayed.add(actState);
				int card1 = firstPlayer.poll();
				int card2 = secondPlayer.poll();
				if (card1 > card2) {
					firstPlayer.add(card2);
					firstPlayer.add(card1);
				} else {
					secondPlayer.add(card1);
					secondPlayer.add(card2);
				}
				totFights++;
			}
		}
		if (firstPlayer.isEmpty()) {
			System.out.println(totFights + " 2" );
		} else if (secondPlayer.isEmpty()) {
			System.out.println(totFights + " 1");
		} else {
			System.out.println("-1");
		}

	}

}

class StatesPassed {
	Queue<Integer> player1;
	Queue<Integer> player2;
	
	public StatesPassed(Queue<Integer> first, Queue<Integer> second) {
		player1 = first;
		player2 = second;
	}

	@Override
	public boolean equals(Object o) {
		StatesPassed state = (StatesPassed) o;
		boolean equals = player1.equals(state.player1) && player2.equals(state.player2);
		
		return equals;
	}
	
	
		
	
}
