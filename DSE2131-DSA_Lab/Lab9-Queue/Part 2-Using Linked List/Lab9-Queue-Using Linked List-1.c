/*
GPT-5 GENERATED CODE. NOT VERIFIED. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{int d;void*n;}N;
N*f,*r;                       // front & rear

N*new(int x){
 N*t=malloc(sizeof*t);
 t->d=x; t->n=0; return t;
}

void enqueue(int x){
 N*t=new(x);
 if(!r){f=r=t;return;}
 r->n=t; r=t;
}

void dequeue(){
 if(!f)return;
 N*t=f; f=(N*)f->n;
 if(!f)r=0;
 free(t);
}

void print(){
 for(N*t=f;t;t=t->n)printf("%d ",t->d);
 printf("\n");
}

/* helpers */
void clear(){while(f)dequeue();}
int front(){return f?f->d:-1;}
int empty(){return !f;}

int main(){
 clear();                  // T1 enqueue few
 enqueue(1); enqueue(2); enqueue(3);
 print();                  // expect 1 2 3

 dequeue();                // T2 remove one
 print();                  // expect 2 3

 printf("%d\n",front());   // T3 front==2

 while(!empty())dequeue(); // T4 clear all
 print();                  // expect blank

 enqueue(9); enqueue(8);   // T5 reuse after clear
 print();                  // expect 9 8
}