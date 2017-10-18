import React from "react";
import ReactDOM from "react-dom";

import Body from "./components/Body";
import Footer from "./components/Footer";
import Header from "./components/Header";

class Layout extends React.Component {
  render() {
    return (
      <div>
        <Header />
        <Body />
        <Footer />
      </div>
    );
  }
}

const app = document.getElementById('app');

ReactDOM.render(<Layout/>, app);
