/*  -------------------------------------------------
    All programs have been put in a single file for 
    convenience.

    Current Directory    
    ↳ CIE/
        ↳ Internals.java
        ↳ Student.java
        
    ↳ SEE/
        ↳ Externals.java

    ↳ Demo.java

    Note: Student.class file must be present in SEE 
    during compilation of External.java (or) all 3
    package files must be compiled together using 
    java -d . <file 1> <file 2> ... <file n>
*/  -------------------------------------------------


/* 
    Internals.java  ---------------------------------
*/

package CIE;
import java.util.*;

public class Internals{
    public int cie_marks[] = new int[5];
    
    Scanner s = new Scanner(System.in);

    public void getInternalsData(){
        System.out.println("\nInternals:\n");
        for(int i=0; i<5; i++){
            System.out.println("\tSub "+i+":");
            cie_marks[i] = s.nextInt();
        }
    }
}

/* 
    Student.java    ---------------------------------
*/

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

/* 
    Externals.java  ---------------------------------
*/

package SEE;
import java.util.*;
import CIE.*;

public class Externals extends Student{
    public int see_marks[] = new int[5];

    Scanner s = new Scanner(System.in);

    public void getExternalsData(){
        Student st = new Student();
        st.getStudentData();

        System.out.println("\nExternals:\n");
        for(int i=0; i<5; i++){
            System.out.println("\tSub "+i+":");
            see_marks[i] = s.nextInt();
        }
    }
}

/* 
    Total.java  -------------------------------------
*/

import java.util.*;
import SEE.Externals;

class Total{    
    public static void main(String args[]){
        Internals obj1 = new Internals();
        obj1.getInternalDetails();

        Externals obj2 = new Externals();
        obj2.getExternalDetails();

        int final_marks[] = new int[5];

        System.out.println("\nFinal Marks:\n");
        for(int i=0; i<5; i++){
            final_marks[i] = obj1.cie_marks[i] + obj2.see_marks[i];
            System.out.println("\tSub "+i+":"+final_marks[i]);
        }
    }
}
