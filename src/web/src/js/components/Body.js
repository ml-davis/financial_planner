import React from "react";

export default class Body extends React.Component {
  
  constructor() {
    super();
    this.state = {
      display: ""
    }
  }

  fetchRemaining() {
    this.setState({ display: "Fetching remaining" });
  }

  fetchExpenses() {
    this.setState({ display: "Fetching expenses" });
  }

  render() {
    return (
      <main>
        <textarea rows="25" cols="150" value={this.state.display}></textarea><br/>
        <button onClick={() => this.fetchRemaining()}>Fetch Remaining</button>
        <button onClick={() => this.fetchExpenses()}>Fetch Expenses</button>
      </main>
    );
  }
}
