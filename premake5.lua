-- premake5.lua
workspace "financial_planner"
  configurations { "Debug", "Release" }

project "run"
  kind "ConsoleApp"
  language "C++"
  files { "src/**.H", "src/**.C" }

  includedirs 
  {
    "src/libs/mysql++",
    "src/libs/mysql"
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

