/*
GPT-5 GENERATED CODE. NOT VERIFIED. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{int d;void*n;}N;
N*h;

N*new(int x){
 N*t=malloc(sizeof*t);
 t->d=x;t->n=0;return t;
}

void insert_head(int x){
 N*t=new(x);t->n=h;h=t;
}

void insert_tail(int x){
 N*t=new(x),*p=h;
 if(!h){h=t;return;}
 while(p->n)p=p->n;
 p->n=t;
}

void insert_at(int x,int k){
 N*t=new(x),*q=h;
 for(int i=1;i<k-1;i++)q=q->n;
 t->n=(N*)q->n;q->n=t;
}

void delete_head(){
 if(!h)return;
 N*t=h;h=(N*)h->n;free(t);
}

void delete_tail(){
 if(!h)return;
 if(!h->n){free(h);h=0;return;}
 N*t=h,*p=0;
 while(t->n){p=t;t=t->n;}
 p->n=0;free(t);
}

void delete_at(int k){
 if(k==1){delete_head();return;}
 N*t=h;for(int i=1;i<k-1;i++)t=t->n;
 N*q=t->n;t->n=(N*)q->n;free(q);
}

void print(){
 for(N*t=h;t;t=t->n)printf("%d ",t->d);
 printf("\n");
}

/* helpers */
void clear(){while(h)delete_head();}
void make(int*a,int n){clear();for(int i=0;i<n;i++)insert_tail(a[i]);}
int check(int*a,int n){
 N*t=h;
 for(int i=0;i<n;i++){if(!t||t->d!=a[i])return 0;t=t->n;}
 return !t;
}
void ok(int c){printf("%s\n",c?"OK":"FAIL");}

int main(){
 clear();                 // T1 head/tail insert
 insert_head(1);
 insert_head(2);
 insert_tail(3);
 int a1[]={2,1,3}; ok(check(a1,3));

 int s2[]={1,3};          // T2 middle insert
 make(s2,2); insert_at(2,2);
 int a2[]={1,2,3}; ok(check(a2,3));

 int s3[]={9,8,7};        // T3 delete head
 make(s3,3); delete_head();
 int a3[]={8,7}; ok(check(a3,2));

 int s4[]={5,6};          // T4 delete tail
 make(s4,2); delete_tail();
 int a4[]={5}; ok(check(a4,1));

 int s5[]={1,2,3,4};      // T5 delete middle
 make(s5,4); delete_at(3);
 int a5[]={1,2,4}; ok(check(a5,3));

 print();                 // final display
}