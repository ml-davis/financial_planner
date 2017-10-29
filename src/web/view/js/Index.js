import React from "react";
import ReactDOM from "react-dom";
import { BrowserRouter } from 'react-router-dom';

import Body from "./body/Body";
import Footer from "./footer/Footer";
import Header from "./header/Header";
import Nav from "./nav/Nav";

const Layout = () => (
  <BrowserRouter>
    <div>
      <Header/>
      <Nav/>
      <Body/>
      <Footer/>
    </div>
  </BrowserRouter>
);

const app = document.getElementById('app');

ReactDOM.render(<Layout/>, app);
