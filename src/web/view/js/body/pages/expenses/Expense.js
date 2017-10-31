import React from "react";

export default class Expense extends React.Component {
 constructor(props) {
   super(props);
 }

 render() {
   return (
     <div id="expense">
       <input type="text" id="date" defaultValue={this.props.date} />
       <input type="text" id="category" defaultValue={this.props.category} />
       <input type="text" id="description" defaultValue={this.props.description} />
       <input type="text" id="cost" defaultValue={this.props.cost} />
       <button class="delete">X</button>
     </div>
   )
  }
};