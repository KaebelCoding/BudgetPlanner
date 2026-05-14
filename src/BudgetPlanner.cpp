#include "BudgetPlanner.h"

void BudgetPlanner::welcomeMsg()
{
	std::cout << "=== Budget Planner ================\n\nWelcome to the budget planner!\nThis programm will calculate your budget and give you some infos about your spendings.\nThe currency is in Euros.\n" << std::endl;
}

void BudgetPlanner::askForIncomes()
{
	do
	{
		std::cout << "What is your income? " << std::flush;
		// Input Validation
		while (!(std::cin >> tempIncome)) {					// Keep asking until the user enters a valid number
			std::cout << "Invalid input. Try again: ";
			std::cin.clear();								// Reset input errors
			std::cin.ignore(10000, '\n');					// Remove bad input
		}
		income.push_back(tempIncome);
		std::cout << tempIncome << " EURO\n" << std::flush;
		std::cout << "Is there another income? (yes/no) " << std::flush;
		std::cin >> InputAnotherIncome;
	} while (InputAnotherIncome.compare("no"));
	std::cout << std::endl;
}

void BudgetPlanner::askForCosts()
{
	do
	{
		std::cout << "What are your costs? " << std::flush;
		// Input Validation
		while (!(std::cin >> tempCost)) {					// Keep asking until the user enters a valid number
			std::cout << "Invalid input. Try again: ";
			std::cin.clear();								// Reset input errors
			std::cin.ignore(10000, '\n');					// Remove bad input
		}
		costs.push_back(tempCost);
		std::cout << tempCost << " EURO\n" << std::flush;
		std::cout << "Is there another cost? (yes/no) " << std::flush;
		std::cin >> InputAnotherCost;
	} while (InputAnotherCost.compare("no"));
	std::cout << std::endl;
}

void BudgetPlanner::calcSum()
{
	sumIncome = 0;
	for (auto i : income)
	{
		sumIncome += i;
	}
	sumCosts = 0;
	for (auto c : costs)
	{
		sumCosts += c;
	}
	sumTotal = sumIncome - sumCosts;
}

void BudgetPlanner::printSum()
{
	std::cout << "After all costs you have " << sumTotal << " EURO left of your budget." << std::endl;
}

void BudgetPlanner::calcPercent()
{
	percent = static_cast<float>(sumCosts * 100) / sumIncome;
}

void BudgetPlanner::printPercent()
{
	std::cout << "The costs makes " << percent << "\% of your budget." << std::endl;
}

void BudgetPlanner::printResult()
{
	if (sumCosts < sumIncome)
	{
		std::cout << "The budget covers your costs." << std::endl;
	}
	else
	{
		std::cout << "The costs are too high for your budget." << std::endl;
	}
}

void BudgetPlanner::run()
{
	BudgetPlanner::welcomeMsg();

	BudgetPlanner::askForIncomes();
	BudgetPlanner::askForCosts();

	BudgetPlanner::calcSum();
	BudgetPlanner::calcPercent();

	BudgetPlanner::printSum();
	BudgetPlanner::printPercent();
	BudgetPlanner::printResult();
}