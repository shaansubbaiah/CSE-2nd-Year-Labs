import java.util.*;
import java.lang.Math.*;

abstract class Shape{
	public int dim1, dim2;
	abstract public void printArea();
	
	Scanner s = new Scanner(System.in);
}

class Rectangle extends Shape{
	public void printArea(){
		System.out.println("Length and Breadth:");
		dim1 = s.nextInt();
		dim2 = s.nextInt();
		System.out.println("Area = "+(float)(dim1*dim2));
	}
}

class Circle extends Shape{
	public void printArea(){
		System.out.println("Radius:");
		dim1 = s.nextInt();
		System.out.println("Area = "+(float)((Math.PI)*dim1*dim1));
	}
}

class Triangle extends Shape{
	public void printArea(){
		System.out.println("Height and Breadth:");
		dim1 = s.nextInt();
		dim2 = s.nextInt();
		System.out.println("Area = "+(float)(0.5*dim1*dim2));
	}
}

class Driver{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.println("Shape:\n1.Rectangle\n2.Circle\n3.Triangle\nChoice:");
		int choice = s.nextInt();
		switch(choice){
			case 1:
				Shape rec = new Rectangle();
				rec.printArea();
				break;
			case 2:
				Shape cir = new Circle();
				cir.printArea();
				break;
			case 3:
				Shape tri = new Triangle();
				tri.printArea();
				break;
			default:
				System.out.println("Wrong Input.\n");
		}
	}
}