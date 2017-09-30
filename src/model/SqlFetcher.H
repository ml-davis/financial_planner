#pragma once

#include "FinancialPlanner.H"
#include "Validator.H"

#include <mysql++.h>

#include <cstdlib>

// forward declaration needed due to circular dependency
class FinancialPlanner;

class SqlFetcher
{
  public:
    void load(FinancialPlanner& fp, const int year, const int month);
};
