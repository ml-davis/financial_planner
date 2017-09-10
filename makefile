all:
	g++ src/model/Expense.C src/model/Partition.C src/model/Validator.C src/model/FinancialPlanner.C src/model/SqlFetcher.C src/view/View.C src/Main.C -lboost_date_time -I/usr/include/mysql -I/usr/include/mysql++ -L/usr/local/lib -lmysqlpp -lmysqlclient -lnsl -lz -lm -o run
