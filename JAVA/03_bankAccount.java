/*
 *   Inheritance prog where class bank has 2 subclasses
 *   Savings -> Has no cheque facility              and 
 *   Current -> Has minimum balance and cheque facility 
 */
import java.util.*;
import java.lang.Math.*;

class bank{
    public int cust_id, acc_no;
    public double balance, CI;
    public String acc_type, cust_name;

    Scanner s = new Scanner(System.in);

    void input(){
        System.out.print("\nEnter Details:\n");
        System.out.print("\tCustomer ID:");
        cust_id = s.nextInt();
        System.out.print("\tCustomer Name:");
        cust_name = s.next();
        System.out.print("\tAccount number:");
        acc_no = s.nextInt();
        System.out.print("\tBalance:");
        balance = s.nextDouble();
    }

    void cal_interest(){
        System.out.print("\n---INTEREST---:\n");
        System.out.print("\tRate:");
        double rate = s.nextDouble();
        System.out.print("\tTerm(in years):");
        double time = s.nextDouble();
        double tot = balance * Math.pow((1 + (rate/100)), time);
		CI = tot - balance;
        System.out.println("Compund Interest = "+CI);
    }

    void display(){
        System.out.println("\n---DETAILS---");
        System.out.println("\tCustomer Name: "+cust_name+"\n\tID:"+cust_id);
        System.out.println("\tAccount Number:"+acc_no);
        System.out.println("\tCompund Interest:"+CI);
    }

    void withdrawal(){
        System.out.print("\n---WITHDRAWAL---\n");
        System.out.print("\tEnter amount to withdraw:");
        double wd = s.nextDouble();
        balance -= wd;
    }
}



class savings extends bank{
    // no cheque facility.
    void display(){
        super.display();
        System.out.println("\tNo Cheque Facility Available.");
    }
}



class current extends bank{
    // check min balance and assign service charge
    double min_balance = 5000.00; 
    double svc_chrg = 0.05 * balance; // svc charge is 5% of balance
    void cal_interest(){
        if(balance <= min_balance){
            System.out.print("Balance is less than Minimum!\n");
            System.out.print("Service charge "+svc_chrg+" has been debited!\n");
            balance -= svc_chrg;
            System.out.print("Balance = "+balance);
        }
        super.cal_interest();
    }

    // provides cheque book facility
    void display(){
        super.display();
        System.out.println("\tCheque Facility Available.");
    }
}



class bank_demo{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int ch = 0;

        while(ch!=4){
            System.out.print("\n----BANK-MENU----\n");
            System.out.print("1.Savings\n2.Current\n4.Exit\n  Choice:");
            ch = s.nextInt();
            switch(ch){
                case 1:
                    bank b1 = new savings();
                    b1.input();
                    b1.withdrawal();
                    b1.cal_interest();
                    b1.display();
                    break;

                case 2:
                    bank b2 = new current();
                    b2.input();
                    b2.withdrawal();
                    b2.cal_interest();
                    b2.display();
                    break;

                case 4:
                    break;

                default:
                    System.out.println("Wrong Input!");
            }
        }
    }
} 