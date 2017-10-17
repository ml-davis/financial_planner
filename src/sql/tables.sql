---------------- EXPENSES ----------------

CREATE TABLE expense_types(
  type_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(25),
  description VARCHAR(100),
  due_date INT
);

CREATE TABLE expenses(
  expense_id INT PRIMARY KEY AUTO_INCREMENT,
  type_id INT
    REFERENCES expense_types(type_id)
    ON UPDATE CASCADE,
  date DATE,
  description VARCHAR(100),
  cost DECIMAL(10, 2)
);

CREATE TABLE targets(
  target_id INT PRIMARY KEY AUTO_INCREMENT,
  type_id INT
    REFERENCES expense_types(type_id)
    ON UPDATE CASCADE,
  date DATE,
  amount DECIMAL(10, 2)
);

CREATE TABLE savings(
  savings_id INT PRIMARY KEY AUTO_INCREMENT,
  type_id INT
    REFERENCES expense_types(type_id)
    ON UPDATE CASCADE,
  amount DECIMAL(10, 2)
);


---------------- INCOME ----------------

CREATE TABLE income_types(
  type_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(25),
  description VARCHAR(100)
);

CREATE TABLE income(
  income_id INT PRIMARY KEY AUTO_INCREMENT,
  type_id INT
    REFERENCES income_types(type_id)
    ON UPDATE CASCADE,
  date DATE,
  amount DECIMAL(10, 2),
  description VARCHAR(100)
);
