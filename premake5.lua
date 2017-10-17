-- premake5.lua
workspace "financial_planner"
  configurations { "Debug", "Release" }

project "run"
  kind "ConsoleApp"
  language "C++"
  files { "src/cpp/**.H", "src/cpp/**.C" }

  includedirs 
  {
    "src/cpp/libs/mysql++",
    "src/cpp/libs/mysql"
  }

  links
  {
    "boost_date_time",
    "boost_system",
    "boost_thread",
    "mysqlpp"
  }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
