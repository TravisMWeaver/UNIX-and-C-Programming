#include <stdio.h>
#include <stdlib.h>

#define SUPER_RICH 500000
#define QUITE_RICH 200000
#define MIAMI_POOR 100000
#define AVERAGE 50000
#define REALISTIC 20000

#define HIGH_RATE 0.25
#define MEDIUM_RATE 0.10
#define LOW_RATE 0.03
#define NO_RATE 0.00

#define MAXIMAL_TAX 50000

void inputIncomeAndDeductions(double *income, double *deductions)
{
	double input = -1;

	while(input != 0)
	{
		printf("Enter next amount : ");
		scanf("%lf", &input);

		if(input > 0)
		{
			*income += input;
		}

		else
		{
			*deductions -= input;
		}
	}
}

double computeTaxableIncome(double income, double deductions)
{
	double taxableIncome = 0.0;

	taxableIncome = income - deductions;

	if(taxableIncome >= 0)
	{
		return taxableIncome;
	}

	return 0.0;
}

char getTaxGroup(double taxableIncome)
{
	if(taxableIncome >= SUPER_RICH)
	{
		return 'S';
	}

	else if(taxableIncome >= QUITE_RICH)
	{
		return 'Q';
	}

	else if(taxableIncome >= MIAMI_POOR)
	{
		return 'M';
	}

	else if(taxableIncome >= AVERAGE)
	{
		return 'A';
	}

	else if(taxableIncome >= REALISTIC)
	{
		return 'R';
	}

	else
	{
		return 'P';
	}
}

double computeTax(double taxableIncome, char taxGroup)
{
	double taxCalculation = 0.0;

	switch(taxGroup)
	{
		case 'S':
			taxCalculation = taxableIncome * HIGH_RATE;
			break;
		case 'Q':
			taxCalculation = taxableIncome * HIGH_RATE;
			break;
		case 'M':
			taxCalculation = taxableIncome * MEDIUM_RATE;
			break;
		case 'A':
			taxCalculation = taxableIncome * LOW_RATE;
			break;
		case 'R':
			taxCalculation = taxableIncome * LOW_RATE;
			break;
		case 'P':
			taxCalculation = taxableIncome * NO_RATE;
			break;
	}

	if(taxCalculation <= MAXIMAL_TAX)
	{
		return taxCalculation;
	}

	else
	{
		return MAXIMAL_TAX;
	}
}

int main(void)
{
	double income = 0.0;
	double deductions = 0.0;
	double taxableIncome = 0.0;
	char taxGroup;
	double taxCalculation = 0.0;

	inputIncomeAndDeductions(&income, &deductions);
	taxableIncome = computeTaxableIncome(income, deductions);
	taxGroup = getTaxGroup(taxableIncome);
	taxCalculation = computeTax(taxableIncome, taxGroup);

	printf("\nIncome\t\t = $%10.2f", income);
	printf("\nDeductions\t = $%10.2f", deductions);
	printf("\nTaxable Income\t = $%10.2f", taxableIncome);
	printf("\nTax group\t = %c", taxGroup);
	printf("\nTax owed\t = $%10.2f\n", taxCalculation);

	return(EXIT_SUCCESS);
}