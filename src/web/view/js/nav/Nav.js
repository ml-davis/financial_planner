import React from 'react'
import { Link } from 'react-router-dom'

const Nav = () => (
  <nav>
    <Link to='/'><div class="link">Home</div></Link>
    <Link to='/expenses'><div class="link">Expenses</div></Link>
  </nav>
);

export default Nav
