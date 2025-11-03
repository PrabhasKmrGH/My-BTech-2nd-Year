/*
TODO: expand
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{int d;void*n;}N;
N*t;                       // top ptr

N*new(int x){
 N*m=malloc(sizeof*m);
 m->d=x; m->n=t; return m;
}

void push(int x){
 t=new(x);
}

void pop(){
 if(!t)return;
 N*m=t; t=(N*)t->n; free(m);
}

void print(){
 for(N*m=t;m;m=m->n)printf("%d ",m->d);
 printf("\n");
}

/* helpers */
void clear(){while(t)pop();}
int top(){return t?t->d:-1;}
int empty(){return !t;}

int main(){
 clear();                 // T1: push 3 vals
 push(1); push(2); push(3);
 print();                 // expect 3 2 1

 pop();                   // T2: pop once
 print();                 // expect 2 1

 printf("%d\n",top());    // T3: top==2

 while(!empty())pop();    // T4: clear stack
 print();                 // expect blank

 push(9); push(8);        // T5: reuse after clear
 print();                 // expect 8 9
}