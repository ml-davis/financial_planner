import React from "react";

import Footer from "./Footer";
import Header from "./Header";

export default class Layout extends React.Component {
  constructor() {
    super();
    this.state = {
      name: "Matthew"
    };
  }

  changeName(name) {
    this.setState({name});
  }

  render() {
    return (
      <div>
        <Header changeName={this.changeName.bind(this)} name={this.state.name}/>
        <Footer />
      </div>
    );
  }
}
