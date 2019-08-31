import java.util.*;

class book{
	String name, author;
	int num_pages;
	double price;
	
	// book(){}	
	// String name, String author, int num_pages, double price
	book(){
		name="Not Given";
		author="Not Given";
		num_pages=0;
		price=0.0;			
	}
	
	
	public String toString(){
		return ("Data\nName:"+name+"\nAuthor:"+author+"Pages:"+num_pages+"Price:"+price);
	}

	public void set_data(){
		Scanner s = new Scanner(System.in);
		System.out.println("Enter:\nName:");
		name=s.nextLine();
		System.out.println("\nAuthor:");
		author=s.nextLine();
		System.out.println("\nPages:");
		num_pages=s.nextInt();
		System.out.println("\nPrice:");
		price=s.nextDouble();	
	}
	
	public void get_data(){
		System.out.println("Data\nName:"+name+"\nAuthor:"+author+"Pages:"+num_pages+"Price:"+price);
	}
	
	/*	
	public static int get_object(int n){
		Scanner s = new Scanner(System.in);
		System.out.println("Enter object number:");
		int c=s.nextInt();		
		if(c>=n){
			System.out.println("Object does not exist!, using object 0");
			return 0;
		}
		else
			return c;
	}
*/

	public static void main(String args[]){
		int n, ch;
		book obj[] = new book[10];
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of objects:");
		n=s.nextInt();
	
		int i=0;
		while(i<n){
			obj[i] = new book();
			System.out.println("\n----MENU----\n");
			System.out.println("1.Using Set Data\n2. Using toString()\n4.Exit\nChoice:");
			ch=s.nextInt();
			switch(ch){
				case 1:
					obj[i].set_data();
					obj[i].get_data();
					break;
				case 2:
					obj[i].set_data();
					System.out.println(obj[i]);
					break;
				case 4:
					break;	
			}
			i++;
		}	
	}
}
