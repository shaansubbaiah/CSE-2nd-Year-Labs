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
