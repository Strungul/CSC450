package CSC450;



public class Main {

	public static void main(String[] args) {
		System.out.println("It's counting time!");
		Counter counter = new Counter(0, 20, '+');
		
		Thread up = new Thread(counter);
		up.start();
		
		//make program pause here to exectue the thread
		try{
			up.join();
		} catch(InterruptedException e) {
			System.out.println("Thread has been interrupted: " + e);
		}
		
		//change counter direction
		counter.setDirection('-');
		counter.setGoal(0);
		
		Thread down = new Thread(counter);
		down.start();
		try{
			down.join();
		} catch(InterruptedException e) {
			System.out.println("Thread has been interrupted: " + e);
		}
		
		System.out.println("Counting time is over!");
		
	}
}


