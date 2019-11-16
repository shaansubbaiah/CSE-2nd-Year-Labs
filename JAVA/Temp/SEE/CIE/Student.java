package CIE;
import java.util.*;

public class Student{
    String usn;
    String name;
    int sem;

    Scanner s = new Scanner(System.in);
    
    public void getStudentData(){
        System.out.println("USN:");
        usn = s.nextLine();
        System.out.println("Name:");
        name = s.nextLine();
        System.out.println("Semester:");
        sem = s.nextInt();
    }
}
