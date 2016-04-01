/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/
int ap_check(int,int,int,int *);
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	int i, j, res[5], temp, d, t = 0, k,count=1,m=0,r;
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len < 0)
		return NULL;
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)
			{
				k = j;
				temp = arr[i];
				d = arr[j + 1] - arr[i];
				while (t == 0)
				{
					t = ap_check(temp, d, k,arr);
					k++;
					count++;
				}
			}
			if ((count>= 3) && m=0)
			{
				res[0] = i;
				res[1] = k - 1;
				m = 1;
				count = 1;
			}
			if (m == 1 && count >= 3)
			{
				res[2] = i;
				res[3] = k - 1;
				break;
			}
		}
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)
			{
				k = j;
				temp = arr[i];
				r = arr[j]/arr[i];
				while (t == 0)
				{
					t = ap_check(temp, r, k, arr);
					k++;
					count++;
				}
			}
			if (count >= 3)
			{
				res[0] = i;
				res[1] = k - 1;
				m = 1;
				count = 1;
			}
	}
}
	int ap_check(int temp, int r, int k,int arr)
	{
		int an=0;
		an = temp + (k - 1)*d;
		if (an == arr[k])
			return 0;
		else
			return k;
	}
	int gp_check(int temp, int r, int k, int arr)
	{
		int gp = 1;
		gp = gp*pow(gp, k);
		if (gp == arr[k])
			return 0;
		else
			return k;
	}