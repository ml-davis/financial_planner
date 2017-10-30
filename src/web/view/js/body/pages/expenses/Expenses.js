import React from "react";

import Expense from "./Expense";

export default class Expenses extends React.Component {

  constructor() {
    super();
  }

  static renderExpenses() {

    // expenses will eventually come from C++ request
    const expenses = [
      {
        date: '2017-10-01',
        category: 'Groceries',
        description: 'Bought milk and chicken',
        cost: '32.29'
      },
      {
        date: '2017-10-02',
        category: 'Entertainment',
        description: 'Went to bar',
        cost: '58.92'
      },
      {
        date: '2017-10-03',
        category: 'Entertainment',
        description: 'Went to restaurant',
        cost: '51.29'
      }
    ];

    let expenseElements = [];
    let count = 0;
    for (const e of expenses) {
      expenseElements.push(<Expense key={count++} date={e.date} category={e.category} description={e.description} cost={e.cost} />);
    }

    return expenseElements;
  }

  render() {
    return (
      <div>
        {Expenses.renderExpenses()}
        <button id="addExpense" onClick={this.addExpense}>+</button>
        <button id="submitExpenses">Submit</button>
      </div>
    );
  }
}
