import { makeRequest } from '../../api';
import React from "react";

export default class Body extends React.Component {

  constructor(props) {
    super(props);
  }

  state = {
    response: ''
  }

  fetchRemaining() {
    makeRequest("FETCH REMAINING", (response) => this.setState({
      response
    }));
  }

  fetchExpenses() {
    makeRequest("FETCH EXPENSES", (response) => this.setState({
      response
    }));
  }

  fetchExpenseTypes() {
    makeRequest("FETCH EXPENSE_TYPES", (response) => {
      try {
        const obj = JSON.parse(response);
        for (const element of obj.expenseTypes) {
          console.log(element);
        }
      } catch (e) {}
    });
    console.log('\n');
  }

  render() {
    return (
      <main>
        <textarea rows="25" cols="157" value={this.state.response}> </textarea><br/>
        <button onClick={() => this.fetchRemaining()}>Fetch Remaining</button>
        <button onClick={() => this.fetchExpenses()}>Fetch Expenses</button>
        <button onClick={() => this.fetchExpenseTypes()}>Fetch Expense Types</button>
      </main>
    );
  }
}
