import { makeRequest } from '../../api';
import React from "react";

export default class Body extends React.Component {
  
  constructor(props) {
    super(props);
  }

  state = {
    display: ''
  }

  fetchRemaining() {
    makeRequest((err, display) => this.setState({
      display
    }), "FETCH REMAINING");
  }

  fetchExpenses() {
    makeRequest((err, display) => this.setState({
      display
    }), "FETCH EXPENSES");
  }

  render() {
    return (
      <main>
        <textarea rows="25" cols="157" value={this.state.display}> </textarea><br/>
        <button onClick={() => this.fetchRemaining()}>Fetch Remaining</button>
        <button onClick={() => this.fetchExpenses()}>Fetch Expenses</button>
      </main>
    );
  }
}
