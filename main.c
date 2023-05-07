/**********************
**Rantses Vinse
**AM:2022201900196
**dit19196@go.uop.gr
**
**Alexandropoulos Ilias
**AM:2022201900007
**dit19007@go.uop.gr
***********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100000

typedef struct Node
{
	double afijh;
	double oloklirwsh;
	struct Node *next; 
}node;

typedef struct
{
	 node *head, *tail;	
}QUEUE;	


void QUEUEput(QUEUE *q, double afijh, double ergasia);
double QUEUEget(QUEUE *q);

int QUEUEempty(QUEUE *q);

void QUEUEinit(QUEUE *q);
void QUEUEfree(QUEUE *q);
void QUEUEprint(QUEUE *q);

double genrand(double rate);

int main(void)
{
	int x;
	do{
		srand(time(NULL));
	
		int flag = -1, i, j = 0;
		double sum = 0, r, Tmd1[9], Tmm1[9];
		
		do
		{
			printf("Epileje systhma\n1. M/D/1\n2. M/M/1\n3. Creators\n4. Exit\n");
			scanf("%d", &x);
		}while(x < 1 || x > 4);
		if(x == 3)
		{
			printf("Made by ");
			printf("\033[1;36m");
			printf("L0uSg3");
			printf("\033[0m");
			printf(" and ");
			printf("\033[1;31m");
			printf("TheHueMaster");
			printf("\033[0m");	
			printf("!!\n");		
		}
		else if( x == 4)
		{
			printf("\nExiting...\n");
			return 0;	
		}
		else if(x == 2)
		{
			flag = 1; //M/M/1
		}
		if( x == 1 || x == 2)
		{	 
			for (r = 0.1; r <= 0.9; r += 0.1)
			{
				sum = 0;
				QUEUE q;		
				QUEUEinit(&q);
				if( flag == -1)
				{
					QUEUEput(&q, genrand(r),1); //Eisagwgh prwtou pelati M/D/1
				}
				else
				{
					QUEUEput(&q, genrand(r),genrand(1)); // M/M/1
				}
		
				double time = q.head->next->afijh, c_time;
				for(i = 0 ; i < N-1 ; i++)
				{
					c_time = time + genrand(r);
					if(flag == 1)
					{
						QUEUEput(&q,c_time,genrand(1));  // M/M/1
						time = c_time;
					}
					else
					{
						QUEUEput(&q,c_time,1);  // M/D/1
						time = c_time;
					}
					node *k = q.head->next;
					//Afairesh pelatwn
					do
					{
						if(k->oloklirwsh < c_time)
						{
							sum += QUEUEget(&q);
						}
						k = k->next;
					}while( k != q.tail);
				}	
				
				node *m = q.head->next;
				
				do{
					sum += QUEUEget(&q);
					m = m->next;
				}while(m != NULL);
								
				QUEUEfree(&q);
				printf("MO anamonis: %f\n", sum/N);
				Tmd1[j] = (2-r)/(2*(1-r));
				Tmm1[j] = 1/(1-r); 
				j++;
			}
			for(i = 0; i < 9; i++)
			{
				printf("Thewritika anamenomenos xronos:%f\n", Tmd1[i]*(flag == -1)+Tmm1[i]*(flag == 1));
			}
		}
		printf("\n\n\n");
	}while( x != 4);
}

void QUEUEinit(QUEUE *q)
{

	q->head = (node*)malloc(sizeof(node)); 
	
	q->tail = q->head; 
	
	q->head->next = NULL;
}

void QUEUEfree(QUEUE *q)
{
	
	while(!QUEUEempty(q))
	{
		QUEUEget(q);
	}	
	free(q->head);
}

int QUEUEempty(QUEUE *q)
{
	
	return q->head == q->tail;
}

void QUEUEput(QUEUE *q, double afijh, double ergasia)
{
	
	node* t = (node*)malloc(sizeof *t);
	
	t->afijh = afijh;
	
	if( QUEUEempty(q) )
	{
		t->oloklirwsh = t->afijh + ergasia;
	}	
	else
	{
		if( q->tail->oloklirwsh - t->afijh >= 0)
		{
			t->oloklirwsh = q->tail->oloklirwsh + ergasia;
		}
		else
		{
			t->oloklirwsh = t->afijh + ergasia;
		}
	}
	t->next = q->tail->next;
	
	q->tail->next = t;
	
	q->tail = t; 

}

double QUEUEget(QUEUE *q)
{
	
	node* t = q->head->next;
		
	q->head->next = t->next;
	
	double x = t->oloklirwsh - t->afijh;
	
	if(q->tail == t) 
	{		
		q->tail = q->head;
	}
		
	free(t);
		
	return x;
	
}

void QUEUEprint(QUEUE *q)
{
	
	node* z = q->head->next;
	
	while(z != NULL){
			
		printf("%.2f, %.2f //",z->afijh, z->oloklirwsh);
		
		z = z->next;

	}
	
	printf("\n");
	
}

double genrand(double rate)
{
	
	int y;
	
	double p;
	
	while ((y = rand()) == RAND_MAX);
	
	p = (double) y / RAND_MAX;
	
	return -log(1-p) / rate;
}
