#include<stdio.h>

void tabelPrinter(FILE *ptr,int table){
    fprintf(ptr, "+------+------+---------+\n");
    fprintf(ptr, "|   %-2s   |   %-2s   |   %-4s   |\n", "Num", "X", "Result");
    fprintf(ptr, "+------+------+---------+\n");

    for (int i = 1; i <= 10; i++) {
        fprintf(ptr, "|   %-2d   |   %-2d   |   %-4d   |\n", table, i, i * table);
    }

    fprintf(ptr, "+------+------+---------+\n");

}

int main(){
    FILE *mulTable;
    int num;
    printf("Enter a number");
    scanf("%d",&num);
    mulTable = fopen("table.txt","w");
    if(mulTable==NULL){
        printf("This file does not exist\n");
        return 1;
    }
    tabelPrinter(mulTable,num);
    fclose(mulTable);
    return 0;
}