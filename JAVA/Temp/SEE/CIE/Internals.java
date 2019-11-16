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
