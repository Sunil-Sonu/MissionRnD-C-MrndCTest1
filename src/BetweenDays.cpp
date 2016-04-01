/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int * year(struct node *, struct node *);
int * month(struct node *, struct node *);
int * day(struct node *, struct node *);
int val[1],val1[1],val2[1];
int check_days(int);
struct node{
	int data;
	struct node *next;
}*temp1=NULL,*temp2=NULL;


int between_days(struct node *date1head, struct node *date2head){
	int *y, *m, *d,c=0,e=0,t;
	if (date1head==NULL || date2head==NULL)
	return -1;
	else
	{
		y = (int *)malloc(sizeof(int) * 2);
		m = (int *)malloc(sizeof(int) * 2);
		d = (int *)malloc(sizeof(int) * 2);
		y=year(date1head, date2head);
		m=month(date1head, date2head);
		d=day(date1head, date2head);
		if (y[0] > y[1])
		{
			t = y[1];
			for (int i = t; i < y[0]; i++)
			{
				if (i % 4 == 0)
					c++;
			}
			c = check_days(m[1]);
			c = c + t + (y[0] - t) * 365;
		}
		else
		{
			t = y[0];
			for (int i = t; i < y[1]; i++)
			{
				if (i % 4 == 0)
					e++;
			}
		}
		e = check_days(m[0]);
		e = e+ d[1] + ((y[1] - t) * 365);
		return(abs(c - e));
	}
}
int * year(struct node *date1head, struct node *date2head)
{
	int c=0,d=0;
	temp1 = date1head;
	temp2 = date2head;
	for (int i = 0; i < 4;i++)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	val[0] = (temp1->data)*1000 + (temp1->next->data)*100 + (temp1->next->next->data)*10 + temp1->next->next->next->data;
	val[1] = (temp2->data)*1000 + (temp2->next->data)*100 + (temp2->next->next->data)*10 + temp2->next->next->next->data;
	return val;

}
int * month(struct node *date1head, struct node *date2head)
{
	temp1 = date1head;
	temp2 = date2head;
	for (int i = 0; i < 3; i++)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	val1[0] = (temp1->data)*10 + temp1->next->data;
	val1[1] = (temp2->data)*10 + temp2->next->data;
	return val1;
}
int * day(struct node *date1head, struct node *date2head)
{
	
	temp1 = date1head;
	temp2 = date2head;
	val2[0] = (temp1->data) * 10 + temp1->next->data;
	val2[1] = (temp2->data) * 10 + temp2->next->data;
	return val;
}
int check_days(int )
{
	int ret=0;
	if (ret == 1)
		return 0;
	else if (ret == 2)
		return 31;
	else if (ret == 3)
		return 59;
	else if (ret == 4)
		return 90;
	else if (ret == 5)
		return 120;
	else if (ret == 6)
		return 151;
	else if (ret == 7)
		return 181;
	else if (ret == 8)
		return 212;
	else 	if (ret == 9)
				return 243;
			else if (ret == 10)
		return 273;
	else if (ret == 11)
		return 304;
	else
		return 334;
}