all:
	g++ Expense.C FinancialCalculator.C Partition.C IOHandler.C Main.C -lboost_date_time -o run
