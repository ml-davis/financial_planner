CREATE TABLE partitions(
  partition_id INT PRIMARY KEY AUTO_INCREMENT,
  category VARCHAR(25),
  description VARCHAR(100),
  due_date INT,
  amount_reserved DECIMAL(10, 2)
);

CREATE TABLE expenses(
  expense_id INT PRIMARY KEY AUTO_INCREMENT,
  category_id INT REFERENCES partitions(partition_id),
  date DATE,
  description VARCHAR(100),
  cost DECIMAL(10, 2)
);

CREATE TABLE savings(
  savings_id INT PRIMARY KEY AUTO_INCREMENT,
  category_id INT REFERENCES partitions(partition_id),
  amount DECIMAL(10, 2)
);

CREATE TABLE income(
  income_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(25),
  date DATE,
  description VARCHAR(100),
  amount DECIMAL(10, 2)
);

