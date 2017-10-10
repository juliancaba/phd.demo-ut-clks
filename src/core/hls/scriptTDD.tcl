open_project prj.TDD
set_top topTesting
add_files -tb ./src/testbench.cc
add_files ./src/topTesting.cc
add_files ./src/wrapperOBJ.cc
add_files ./src/hls_casting.cc
add_files ./src/vector_norm.cc

open_solution "solution"
set_part xc7z020clg484-1
create_clock -period 10

source "./directivesTDD.tcl"

csynth_design