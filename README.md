# railwayrearrangement
A data structures project using stacks following the FIFO method to arrange railroad cars in an order.

# Problem Description

It's a very nice application of stacks. Consider that a freight train has n railroad cars. Each to be left at different station. They're numbered 1 through n & freight train visits these stations in order n through 1. Obviously, the railroad cars are labeled by their destination.To facilitate removal of the cars from the train, we must rearrange them in ascending order of their number(i.e. 1 through n). When cars are in this order, they can be detached at each station. We rearrange cars at a shunting yard that has input track, output track & k holding tracks between input & output tracks(i.e. holding track). 

# Solution Strategy
To rearrange cars, we examine the cars on the input from front to back. If the car being examined is next one in the output arrangement, we move it directly to output track. If not, we move it to the holding track & leave it there until it's time to place it to the output track. The holding tracks operate in a LIFO manner as the cars enter & leave these tracks from top. When rearranging cars only following moves are permitted: 
*	A car may be moved from front (i.e. right end) of the input track to the top of one of the holding tracks or to the left end of the output track.
*	A car may be moved from the top of holding track to left end of the output track.
The figure shows a shunting yard with k = 3, holding tracks H1, H2 & H3, also n = 9. The n cars of freight train begin in the input track & are to end up in the output track in order 1 through n from right to left. The cars initially are in the order 5,8,1,7,4,2,9,6,3 from back to front. Later cars are rearranged in desired order.

# A three track example
![railwayrearrangement](Untitled.png)
