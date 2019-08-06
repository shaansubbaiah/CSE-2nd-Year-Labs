#include <stdio.h>

int main(){
  int i,n;
  
  printf("Enter the number of students:");
  scanf("%d", &n);
  
  struct student{
    int roll;
    char name[30];
    int math, chem, phys;
    int total;
  }std[n];

  printf("\n ------- INPUT ------- \n");
  for(i=0; i<n; i++){
    printf("\nEnter details for student %d:\n", n);
    printf("\tRoll:");
    scanf("%d", &std[i].roll);
    printf("\tName:");
    scanf("%s", std[i].name);
    printf("\tMarks in:\n");
    printf("\t\tMathematics:");
    scanf("%d", &std[i].math);
    printf("\t\tChemistry:");
    scanf("%d", &std[i].chem);
    printf("\t\tPhysics:");
    scanf("%d", &std[i].phys);

    std[i].total = std[i].math + std[i].chem + std[i].phys;
  }

  printf("\n ------- OUTPUT ------- \n");
  for(i=0; i<n; i++){
    printf("\n\tRoll: %d", std[i].roll);
    printf("\n\tName: %s", std[i].name);
    printf("\n\tMarks in:");
    printf("\n\t\tMathematics: %d", std[i].math);
    printf("\n\t\tChemistry: %d", std[i].chem);
    printf("\n\t\tPhysics: %d", std[i].phys);
    printf("\n\tTOTAL: %d\n", std[i].total);
  }

  return 0;
}