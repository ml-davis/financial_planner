import React from 'react'
import { Switch, Route } from 'react-router-dom'

import Home from './pages/Home'
import Expenses from './pages/Expenses'

const Body = () => (
  <main>
    <Switch>
      <Route exact path='/' component={Home}/>
      <Route path='/page2' component={Expenses}/>
    </Switch>
  </main>
);

export default Body