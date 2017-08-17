all:
	g++ src/model/Expense.C src/model/Partition.C src/model/IOHandler.C src/model/FinancialPlanner.C src/view/View.C src/Main.C -lboost_date_time -o run
