#include<stdio.h>
#include<stdlib.h>

struct stack {
   int* s;
   int top;
};
typedef struct stack stack;
int railroad(int[],int,int);
void outputFromHoldingTrack();
int putInHoldingTrack(int);
int* create(int size);
int peek(stack *st);
int stfull(stack st,int size);
void push(stack *p_st,int item);
int stempty(stack st);
int pop(stack *p_st);
void display(stack st);
int numberOfCars;
int numberOfTracks;
int smallestCar;                                                                    //smallest car in any holding track
int itsTrack;
stack track[100];                                                                     //holding track with car smallestCar
int main()
{
    int z=0, i, a;
    int inputOrder[numberOfCars];
    printf("Enter number of tracks:");
    scanf("%d",&numberOfTracks);
    for(i=1;i<=numberOfTracks;i++)
        track[i].s=create(100);
    printf("Enter number of cars:");
    scanf("%d",&numberOfCars);
    printf("Enter the values of the cars:");
    for(i=0;i<numberOfCars;i++)
    {
        scanf("%d",&inputOrder[i]);
        //input=z;
    }
    a=railroad(inputOrder,numberOfTracks,numberOfCars);
    printf("%d",a);
    // push(&track[0],5);
    // push(&track[1],8);
    // push(&track[2],1);
    // push(&track[3],7);
    // push(&track[4],4);
    // push(&track[5],2);
    // push(&track[6],9);
    // push(&track[7],6);
    // push(&track[8],3);
    //for(i=0;i<numberOfCars;i++)
    {
        //display(track[i]);
    }
}
int railroad(int inputOrder[],int theNumberOfCars, int theNumberOfTracks)           // Rearrange railroad cars beginning with the initial order.
{                                                                                   // Return true if successful, false if impossible.
	int nextCarToOutput = 1;
    int i;                                                                          // rearrange cars
    for (i = 0; i < numberOfCars; i++)
        if (inputOrder[i] == nextCarToOutput)
        {
            printf("Move car %d from input track to output track\n" ,inputOrder[i]);  // send car inputOrder[i] straight out
            nextCarToOutput++;
            while (smallestCar == nextCarToOutput)                                  // output from holding tracks
            {
                outputFromHoldingTrack();
                nextCarToOutput++;
            }
        }
        else                                 // put car inputOrder[i] in a holding track
            putInHoldingTrack(inputOrder[i]);
    return 1;
}
/* output the smallest car from the holding tracks */
void outputFromHoldingTrack()
{
    int i;
	pop(&track[itsTrack]);                                                          // remove smallestCar from itsTrack
	printf("Move car %d from holding train track %d to output track\n",smallestCar,itsTrack);
	smallestCar = numberOfCars + 2;                                                 // find new smallestCar and itsTrack by checking top of all stacks
	for (i = 0; i < numberOfTracks; i++)
	{
	    if (!stempty(track[i]) && (peek(&track[i]) < smallestCar))
		{
		smallestCar = peek(&track[i]);
		itsTrack = i;
		}
	}
}
/* put car c into a holding track and return false if there is no feasible holding track for this car */
int putInHoldingTrack(int c)
{
    int i;                                                                                  // find best holding track for car c, initialize
	int bestTrack = 0;                                                                      // best track so far
	int bestTop = numberOfCars + 2;                                                         // top car in bestTrack
	smallestCar=numberOfCars+1;
	push(&track[1],numberOfCars + 1);
	push(&track[2],numberOfCars + 1);
	push(&track[3],numberOfCars + 1);
    push(&track[4],numberOfCars + 1);
    push(&track[5],numberOfCars + 1);

	for (i = 1; i <= numberOfTracks; i++)                                                   // scan tracks
	{
	    if (!stempty(track[i]))                                                             // track i not empty
		{
			int topCar = peek(&track[i]);
			if ((c < topCar) && (topCar < bestTop)   )                                          // track i has smaller car at top
			{
				bestTop = topCar;
				bestTrack = i;
				push(&track[bestTrack],c);                                                              // add c to bestTrack
                printf("Move car %d from input track to holding track %d \n",c,bestTrack);
			}
		}
		else if (bestTrack == 0)                                                            // track i empty
            bestTrack = i;
	}
	if (bestTrack == 0)
		 return 0;                                                                          // no feasible track
	if (c < smallestCar)                                                                    // update smallestCar and itsTrack if needed
	{
        smallestCar = c;
        itsTrack = bestTrack;
	}
	return 1;
}
int* create(int size)
{
    return(malloc(sizeof(int)*size));
}
int peek(stack *st)
{
    return st->s[st->top];
}
int stfull(stack st,int size)
{
   if (st.top >= size - 1)
      return 1;
   else
      return 0;
}
void push(stack *p_st,int item)
{
    p_st->top++;
    p_st->s[p_st->top] = item;
}
int stempty(stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}
int pop(stack *p_st)
{
    int item;
    item = p_st->s[p_st->top];
    p_st->top--;
    return (item);
}
void display(stack st)
{
    int i;
    if (stempty(st))
        printf("\nStack Is Empty!");
    else
        for (i = st.top; i >= 0; i--)
            printf("\n%d", st.s[i]);
}

