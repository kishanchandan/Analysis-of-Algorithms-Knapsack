#include<stdio.h>

int Knapsack(int elements, int capacity, int wt[], int val[]);
int find_max (int x, int y);

int main ()
{
	int elements,capacity,i;
	int wt[50],val[50];

	printf("Input the number of elements : ");
	scanf("%d",&elements);

	printf("Input the capacity of Knap bag: ");
	scanf("%d",&capacity);

	for(i=1;i<=elements;i++) {
		printf("Enter the weight of item %d :",i);
		scanf("%d",&wt[i]);
		printf("Enter the value of item %d :",i);
		scanf("%d",&val[i]);
	}

	Knapsack(elements,capacity,wt,val);//Calling Knapsack function
}

int Knapsack(int elements, int capacity, int wt[], int val[])
{
	int Knap[50][50];
	int i,j;
	int items_in_bag[50];
	int pointer=0;

	//Initiazling elements if weight 0
  	for (i = 0; i <= elements; i++) 
		Knap[i][0] = 0;

	//Initializing weigths if 0 items
	for (j = 0; j <= capacity; j++)
		Knap[0][j] = 0;

	//Inserting values in Knapsack table
  	for (j = 1; j <= capacity; j++) {
		for (i = 1; i <= elements; i++) {
			if(wt[i] <= capacity) {
				if(j - wt[i]<0)
					Knap[i][j] = Knap[i-1][j];
				else
					Knap[i][j] = find_max(Knap[i-1][j], val[i] + Knap[i-1][j - wt[i]]);
			} 
			else 
				Knap[i][j] = Knap[i-1][j];
		}
	}

	//print Knapsack table
	for (i = 0; i <= elements; i++)	{
		for (j = 0; j <= capacity; j++)	{
	  		printf ("%d\t", Knap[i][j]);
		}
      		printf ("\n");
    	}


	//Backtracking
	i=elements;
	j=capacity;

	while(i>0) {
		if(Knap[i][j]!=Knap[i-1][j]) {
			items_in_bag[pointer] = i;
			j=j-wt[i];
			i=i-1;
			pointer = pointer + 1;			
		}
		else {
			i=i-1;
		}
	}
	
	printf("Items Included:\t");

	for(i=0;i<pointer;i++)
		printf("%d\t",items_in_bag[i]);

	printf("\nTotal value : %d\n",Knap[elements][capacity]);

}

int find_max (int x, int y) //Function to find max
{
	int max;

	if (x >= y)
	   	max = x;
	else
  		max = y;
	
	return max;
}

