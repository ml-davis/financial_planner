import React from "react";
import ReactDOM from "react-dom";
import { BrowserRouter } from 'react-router-dom';

import Body from "./components/Body";
import Footer from "./components/Footer";
import Header from "./components/Header";
import Nav from "./components/Nav";

class Layout extends React.Component {
  render() {
    return (
      <BrowserRouter>
        <div>
          <Header/>
          <Nav/>
          <Body/>
          <Footer/>
        </div>
      </BrowserRouter>
    );
  }
}

const app = document.getElementById('app');

ReactDOM.render(<Layout/>, app);
