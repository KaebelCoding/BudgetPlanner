#include "BudgetPlanner.h"

void BudgetPlanner::welcomeMsg()
{
	std::cout << "=== Budget Planner ================\n" << std::endl;
}

void BudgetPlanner::askForIncomes()
{
	do
	{
		std::cout << "What is your income? " << std::flush;
		std::cin >> tempIncome;
		// TODO check for correct input
		income.push_back(tempIncome);
		std::cout << "Is there another income? (0/1) " << std::flush;
		std::cin >> anotherIncome;
	} while (anotherIncome);
	std::cout << std::endl;
}

void BudgetPlanner::askForCosts()
{
	do
	{
		std::cout << "What are your costs? " << std::flush;
		std::cin >> tempCost;
		// TODO check for correct input
		costs.push_back(tempCost);
		std::cout << "Is there another cost? (0/1) " << std::flush;
		std::cin >> anotherCost;
	} while (anotherCost);
	std::cout << std::endl;
}

void BudgetPlanner::calcSum()
{
	for (auto i : income)
	{
		sumIncome += i;
	}
	for (auto c : costs)
	{
		sumCosts += c;
	}
	sumTotal = sumIncome - sumCosts;
}

void BudgetPlanner::printSum()
{
	std::cout << "After all costs you have " << sumTotal << " \u20AC left." << std::endl;
}

void BudgetPlanner::calcPercent()
{
	percent = static_cast<float>(sumCosts * 100) / sumIncome;
}

void BudgetPlanner::printPercent()
{
	std::cout << "The costs make " << percent << "\% of your budget." << std::endl;
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