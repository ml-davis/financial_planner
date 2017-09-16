-- premake5.lua
workspace "financial_planner"
  configurations { "Debug", "Release" }

project "run"
  kind "ConsoleApp"
  language "C++"
  files { "**.H", "**.C" }

  includedirs 
  {
    "/usr/include/mysql++",
    "/usr/include/mysql"
  }

  links
  {
    "boost_date_time",
    "mysqlpp"
  }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

