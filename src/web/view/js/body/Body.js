import React from 'react'
import { Switch, Route } from 'react-router-dom'

import Home from './pages/Home'
import Expenses from './pages/expenses/Expenses'

const Body = () => (
  <main>
    <Switch>
      <Route exact path='/' component={Home}/>
      <Route path='/expenses' component={Expenses}/>
    </Switch>
  </main>
);

export default Body