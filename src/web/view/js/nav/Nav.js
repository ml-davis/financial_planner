import React from 'react'
import { Link } from 'react-router-dom'

const Nav = () => (
  <nav>
    <ul>
      <li><Link to='/'>Home</Link></li>
      <li><Link to='/page2'>Expenses</Link></li>
    </ul>
  </nav>
);

export default Nav
