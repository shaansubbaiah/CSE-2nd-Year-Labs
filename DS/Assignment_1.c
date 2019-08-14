/*
 *  ---------- Program to demonstrate using stacks with structures ----------
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 60

struct student{
    char name[30], email[50], usn[11];
}
        std[MAX_STUDENTS];

int i, c, top=-1;

void Push(){
    if(top == MAX_STUDENTS-1)
        printf("Max Student Limit Reached!\n\n");
    else{
        top+=1;
        printf("Enter Name: ");
        scanf("%s", std[top].name);
        printf("\t  USN: ");
        scanf("%s", std[top].usn);
        printf("\t  Email: ");
        scanf("%s", std[top].email);
    }
}

void Pop(){
    if(top < 0)
        printf("Student List Empty!\n\n");
    else{
        printf("Student '%s'(USN: %s) has been popped.\n\n", std[top].name, std[top].usn);
        top-=1;
    }
}

void Display(){
    if(top < 0)
        printf("Student List Empty!\n\n");
    else{
        printf("---------------\n");
        for(i=top; i>=0; i--){
            printf("Name: %s \nUSN: %s \nEmail: %s \n", std[i].name, std[i].usn, std[i].email);
            printf("---------------\n");
        }
    }
}

int main(){
    printf("Student Attendance Register \n\n");
    do{
        printf("Press \n 1.Push Student \n 2.View Students \n 3.Pop Student \n 4.Exit\n");
        scanf("%d", &c);

        switch(c){
            case 1:
                Push();
                break;
            case 2:
                Display();
                break;
            case 3:
                Pop();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong Choice! \n\n");
        }
    }while(1);
    return 0;
}

/* ----------- OUTPUT -----------

Student Attendance Register

Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
2
Student List Empty!

Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
3
Student List Empty!

Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
1
Enter Name: Ron
      USN: 1EM18CS001
      Email: ron@mail.com
Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
1
Enter Name: Dave
      USN: 1EM18CS054
      Email: dave@mail.com
Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
1
Enter Name: Mario
      USN: 1EM18CS042
      Email: red_luigi@mail.com
Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
2
---------------
Name: Mario
USN: 1EM18CS042
Email: red_luigi@mail.com
---------------
Name: Dave
USN: 1EM18CS054
Email: dave@mail.com
---------------
Name: Ron
USN: 1EM18CS001
Email: ron@mail.com
---------------
Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
3
Student 'Mario'(USN: 1EM18CS042) has been popped.

Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
2
---------------
Name: Dave
USN: 1EM18CS054
Email: dave@mail.com
---------------
Name: Ron
USN: 1EM18CS001
Email: ron@mail.com
---------------
Press
 1.Push Student
 2.View Students
 3.Pop Student
 4.Exit
4
exit status 1

*/
