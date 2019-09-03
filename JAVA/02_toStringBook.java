import java.util.*;

class book{
	String name, author;
	int num_pages;
	double price;
	
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
		System.out.print("Enter:\n\tName:");
		name=s.nextLine();
		System.out.print("\tAuthor:");
		author=s.nextLine();
		System.out.print("\tPages:");
		num_pages=s.nextInt();
		System.out.print("\tPrice:");
		price=s.nextDouble();	
	}
	
	public void get_data(){
		System.out.println("Data\nName:"+name+"\nAuthor:"+author+"Pages:"+num_pages+"Price:"+price);
	}

	public static void main(String args[]){
		int n, ch;
		book obj[] = new book[10];
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of objects:");
		n=s.nextInt();
	
		int i=0;
		while(i<n){
			obj[i] = new book();
			System.out.print("\n----MENU----\n");
			System.out.print("1.Using Set Data\n2.Using toString()\n4.Exit\nChoice:");
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
