package SEE;
import java.util.*;
// import package CIE that we created earlier
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
