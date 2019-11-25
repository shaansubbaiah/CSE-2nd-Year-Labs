class bms implements Runnable{
	Thread t1;
	bms(){
		t1 = new Thread(this,"bms");
	}
	public void run(){
		try{
			for(int i=5; i>0; i--){
				System.out.println("BMS College of Engineering");
				Thread.sleep(10000);
			}
		}
		catch(InterruptedException e){
			System.out.println("BMS interrupted\n");
		}
		System.out.println("Exiting: "+t1);
	}
}

class cse implements Runnable{
	Thread t2;
	cse(){
		t2 = new Thread(this,"cse");
	}
	public void run(){
		try{
			for(int i=5; i>0; i--){
				System.out.println("CSE");
				Thread.sleep(2000);
			}
		}
		catch(InterruptedException e){
				System.out.println("CSE interrupted\n");
		}
		System.out.println("Exiting: "+t2);
	}
}

class threadprg{
	public static void main(String args[]){
		bms obj1 = new bms();
		cse obj2 = new cse();
		obj1.t1.start();
		obj2.t2.start();
	}
}