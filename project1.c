#include <stdio.h>
#include <stdlib.h>
#include <mmcobj.h>

char chunk;
int counter1 =0;
int counter2 = 0;


struct n{
    int x;
      struct n* next;
      struct n* prev;
};
typedef struct n node;
node *temp;
node *temp1;
node *multiplicand;
node *multiplier ;
node *back;
node *back1;
node *result;
void readtxt() {
         FILE *fp = fopen("number.txt", "r");


    while((chunk = fgetc(fp)) !='\n'){
        counter1++;
        temp = (node*) malloc(sizeof (node));
        temp -> x = chunk-'0';
        if (multiplicand == NULL){

            multiplicand = temp;
            printf("Multiplicand : %d", multiplicand->x);

        } else{
            back = multiplicand;
            temp-> next = back;
            back->prev = temp;
            multiplicand =temp;

            printf("%d", multiplicand->x);
        }



    }
    while((chunk = fgetc(fp)) && !feof(fp)){
        counter2++;
        temp1 = (node*) malloc(sizeof (node));
        temp1 -> x = chunk-'0';
        if (multiplier == NULL){

            multiplier = temp1;
            printf("  \nMultiplier : %d", multiplier->x);

        } else{
            back1 = multiplier;
            temp1-> next = back1;
            back1->prev = temp1;
            multiplier = temp1;
            printf("%d", multiplier->x);

        }

    }

}

int main() {


    readtxt();
    result = (node *) malloc(sizeof(node));
    int residual;
    node *number1 = multiplicand;
    node *number2 = multiplier;
    node *number3 = result;
    node *number3head = result;
    node *number3headstart = result;
    int step = 0;

    int tempresult;

        for (int i = 0; i < counter1; i++) {
            temp =(node *) malloc(sizeof(node));
            tempresult = (number1->x * number2->x) + residual ;
            residual = 0;

            if (tempresult >= 10) {

                residual = tempresult / 10;

                tempresult = tempresult % 10;
                number3->x = tempresult;
            } else {
                number3->x = tempresult;
            }
            number1 = number1->next;
           // printf(" \nresult :%d", number3->x);
            step++;
            temp =(node *) malloc(sizeof(node));
            temp->next =NULL;
            temp->prev =number3;
            number3 ->next = temp;
            number3 = number3->next;

        }
        if (residual > 0) {
            number3->x = residual;
           // printf(" \nresult :%d", number3->x);
            residual = 0;
        }
        /*else{
            number3 = number3->prev;
            number3->next = NULL;
        }
*/
    number2 = multiplier;
   for (int j= 1; j <counter2 ; j++) {
        number3head = number3headstart;
        number1 = multiplicand;
        number2 = number2->next;
        number3 = number3headstart;

        for (int i = 0; i < counter1; i++) {
            number3head =number3head->next;
            number3 = number3->next;

            tempresult = (number1->x * number2->x) + residual +number3head->x ;
            residual = 0;

            if (tempresult >= 10) {

                residual = tempresult / 10;

                tempresult = tempresult % 10;
                number3->x = tempresult;
            } else {
                number3->x = tempresult;
            }
            number1 = number1->next;
           // printf(" \nresult :%d", number3->x);
            if (number3->next ==NULL && residual>0){
                step++;
                temp =(node *) malloc(sizeof(node));
                temp->next =NULL;
                temp->prev =number3;
                number3 ->next = temp;
                number3 = number3->next;
            }

        }
        if (residual > 0) {
            number3->x = residual;
           // printf(" \nresult :%d", number3->x);
           residual = 0;

        }

       number3headstart = number3headstart->next;


        }
    FILE *output = fopen("output.txt", "w");
    fprintf(output,"\nRESULT :%d", number3->x);
    for (int i = 0; i <step ; ++i) {

       fprintf(output,"%d", number3->prev-> x);
        number3 =number3->prev;
    }
    return 0;
    }











