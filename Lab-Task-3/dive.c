#include <stdio.h>
#include <stdlib.h>

float getAmbientPressure(int depth)
{
	return (depth / 33.0) + 1;
}

float getOxygenPressure(float pressureAmbient, int percentO2)
{
	return (percentO2 / 100.0) * pressureAmbient;
}

char getOxygenPressureGroup(float pressureO2)
{
	int pressureGroup = (pressureO2 * 10) + 'A';
	return pressureGroup;
}

int main()
{
	int depth, percentO2;
	float pressureAmbient, pressureO2;
	char pressureGroup;

	printf("Enter depth and percentage O2\t: ");
	scanf("%d %d", &depth, &percentO2);

	pressureAmbient = getAmbientPressure(depth);
	pressureO2 = getOxygenPressure(pressureAmbient, percentO2);
	pressureGroup = getOxygenPressureGroup(pressureO2);

	printf("\nAmbient pressure\t\t: %3.1f", pressureAmbient);
	printf("\nO2 pressure\t\t\t: %3.2f", pressureO2);
	printf("\nO2 group\t\t\t: %c", pressureGroup);

	printf("\n\n\nExceeds maximal O2 pressure\t: %s", pressureO2 > 1.4 ? "true" : "false");
	printf("\nExceeds contingency O2 pressure\t: %s\n", pressureO2 > 1.6 ? "true" : "false");

	return(EXIT_SUCCESS);
}