#include <stdio.h>

int main(){

    int a , b, choice;
    float result;
    
    printf ("------The calculator Program-----\n");
    printf ("Enter a number: ");
    scanf("%d", &a);

    printf("Enter another number: ");
    scanf("%d", &b);

    printf (
           " \n1 - Addition\n"
           "2 - Subtraction\n"
           "3 - Multiplication\n"
           "4 - Division\n");

    printf("Enter a calculator operation: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        result = a + b;
        printf("%d + %d = %d\n",a ,b,result);
        break;
    
    case 2:
        result = a - b;
        printf("%d - %d = %d\n",a ,b,result);
        break;
 
    case 3:
        result = a * b;
        printf("%d * %d = %d\n",a ,b,result);
        break;
    
    case 4:
        if (b != 0){

            result = a / b;
            printf("%d / %d = %d\n",a ,b,result);
        }
        else{
            printf("Number cannot be Zero\n" );
        }

        break;
        
    default:
        printf("Invalid Input\n");
        break;
        



    }


  return 0; 
}