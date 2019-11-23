import java.util.*;

class fatherAgeException extends Exception{
	public String toString(){
		return ("Father's age is less than 0");
	}
}

class sonAgeException extends Exception{
	int a;
	sonAgeException(int age){
		a = age;
	}
	public String toString(){
		if(a<0)
			return ("Son's age is less than 0");
		else
			return ("Son's age is more than father's age");
	}
}

class father{
	public int age1;
	Scanner s = new Scanner(System.in);
	father(){
		System.out.print("Enter father's age: ");
		age1 = s.nextInt();
	}
	void ex1() throws fatherAgeException{
		if(age1<0)
			throw new fatherAgeException();
	}
}

class son extends father{
	public int age2;
	son(){
		System.out.print("Enter son's age: ");
		age2 = s.nextInt();
	}
	void ex2() throws sonAgeException{
		if(age2<0 || age2>super.age1)
			throw new sonAgeException(age2);
	}
}

class fatherson{
	public static void main(String args[]){
		son s = new son();
		try{
			s.ex1();
		}
		catch(fatherAgeException e){
			System.out.println(e);
		}
		try{
			s.ex2();
		}
		catch(sonAgeException e){
			System.out.println(e);
		}
	}
}