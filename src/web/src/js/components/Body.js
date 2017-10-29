import React from 'react'
import { Switch, Route } from 'react-router-dom'

import Page1 from './Page1'
import Page2 from './Page2'

const Body = () => (
  <main>
    <Switch>
      <Route exact path='/' component={Page1}/>
      <Route path='/page2' component={Page2}/>
    </Switch>
  </main>
);

export default Body