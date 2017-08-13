all:
	g++ src/Expense.C src/Partition.C src/IOHandler.C src/View.C src/FinancialPlanner.C src/Main.C -lboost_date_time -o run
