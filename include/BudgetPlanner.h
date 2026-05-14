#pragma once

#include <array>
#include <iostream>
#include <string>
#include <vector>

class BudgetPlanner
{
public:
	int                       tempIncome;
	int                       tempCost;
	std::vector<unsigned int> income;
	std::vector<unsigned int> costs;
	std::string               InputAnotherIncome;
	std::string               InputAnotherCost;

	// TODO calculate in Cent and output in Euro with 2 decimals
	int   valueCent;
	float valueEuro;

	unsigned int 			  sumIncome;
	unsigned int              sumCosts;
	signed int                sumTotal;
	float                     percent;

	void welcomeMsg ();
	void askForIncomes ();
	void askForCosts ();

	void calcSum ();
	void calcPercent ();

	void printSum ();
	void printPercent ();
	void printResult ();

	void run();
};
