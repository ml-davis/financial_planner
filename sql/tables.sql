CREATE TABLE partitions(
  partition_id INT PRIMARY KEY AUTO_INCREMENT,
  category VARCHAR(25),
  description VARCHAR(100),
  due_date INT,
  amount_reserved DOUBLE,
  amount_remaining DOUBLE
);

CREATE TABLE expenses(
  expense_id INT PRIMARY KEY AUTO_INCREMENT,
  category_id INT REFERENCES partitions(partition_id),
  date DATE,
  description VARCHAR(100),
  cost DOUBLE
);

CREATE TABLE savings(
  savings_id INT PRIMARY KEY AUTO_INCREMENT,
  category_id INT REFERENCES partitions(partition_id),
  amount DOUBLE
);
