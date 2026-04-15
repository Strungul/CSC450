package CSC450;

public class Counter implements Runnable{
	private int counterVal;
	private int goalNum;
	private char direction;
	
	public Counter(int startNum, int endNum, char direction) {
		validateDirection(direction);
		this.counterVal = startNum;
		this.goalNum = endNum;
		this.direction = direction;
	}
	
	public void run() {
		this.count();
	}
	
	private void count() {
		
		if(this.direction == '+') {
			if(this.counterVal >= this.goalNum) {
				System.out.println("Counter value " + this.counterVal + " is already greater than or equal to the goal value.");
				return;
			}
		
			System.out.println(this.counterVal);
			
			while(this.counterVal < this.goalNum) {
				this.counterVal++;
				System.out.println(this.counterVal);
			}
		}
		
		if(this.direction == '-') {
			if(this.counterVal <= this.goalNum) {
				System.out.println("Counter value " + this.counterVal + " is already less than or equal to the goal value.");
				return;
			}
		
			System.out.println(this.counterVal);
			
			while(this.counterVal > this.goalNum) {
				this.counterVal--;
				System.out.println(this.counterVal);
			}
		}
		
	}//end count method
	
	public void setDirection(char direction) {
		validateDirection(direction);
		this.direction = direction;
	};
	
	public char getDirection() {
		return this.direction;
	};
	
	private void validateDirection(char dir) {
		if (dir != '+' && dir != '-') {
	        throw new IllegalArgumentException("Invalid direction argument.  Direction must be '+' or '-'.");
	    }
	}
	
	public void setGoal(int goal) {
		this.goalNum = goal;
	}
	
	public int getGoal() {
		return this.goalNum;
	}
}
