all:
	g++ Expense.C Partition.C IOHandler.C View.C FinancialCalculator.C Main.C -lboost_date_time -o run
