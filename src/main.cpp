#include <windows.h>

#include "BudgetPlanner.h"

int main()
{
	BudgetPlanner bp;

	SetConsoleOutputCP(1252);

	bp.welcomeMsg();

	bp.askForIncomes();
	bp.askForCosts();

	bp.calcSum();
	bp.calcPercent();

	bp.printSum();
	bp.printPercent();
	bp.printResult();
}