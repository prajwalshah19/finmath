# CMake generated Testfile for 
# Source directory: /Users/shashank/finmath
# Build directory: /Users/shashank/finmath/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "/Users/shashank/finmath/build/runTests")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/Users/shashank/finmath/CMakeLists.txt;33;add_test;/Users/shashank/finmath/CMakeLists.txt;0;")
subdirs("_deps/pybind11-build")
