import { makeRequest } from '../../../../../serverRequestor';
import React from "react";

import Expense from "./Expense";

export default class Expenses extends React.Component {

  constructor(props) {
    super(props);
    this.state = { response: '' };
    this.fetchExpenses();
  }

  fetchExpenses() {
    makeRequest("FETCH EXPENSES", (response) => this.setState({
      response
    }));
  }

  renderExpenses() {
    if (this.state.response !== '') {
      let count = 0;
      let expenseElements = [];

      const jsonObject = JSON.parse(this.state.response);
      for (const e of jsonObject.expenses) {
        expenseElements.push(
          <Expense key={count++} date={e.date} category={e.category} description={e.description} cost={e.cost}/>
        );
      }
      return expenseElements;
    } else {
      return "";
    }
  }

  render() {
    return (
      <div>
        {this.renderExpenses()}
        <button id="addExpense" >+</button><br/>
        <button id="submitExpenses" >Submit</button>
      </div>
    );
  }
}
