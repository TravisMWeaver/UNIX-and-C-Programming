#include <stdio.h>
#include <stdlib.h>

#define ROADKILLCON 1.47
#define AVGROADWIDTH 0.01

int main()
{
	float sideOfSquare, roadLength, kangarooNum, estDeaths;

	printf("Enter side of square in km\t: ");
	scanf("%f", &sideOfSquare);
	printf("Enter roads length in km\t: ");
	scanf("%f", &roadLength);
	printf("Enter number of 'roos\t\t: ");
	scanf("%f", &kangarooNum);

	estDeaths = (ROADKILLCON * roadLength * AVGROADWIDTH * kangarooNum) / (sideOfSquare * sideOfSquare);

	printf("Expected number of kills is\t: %3.1f\n", estDeaths);

	return(EXIT_SUCCESS);
}