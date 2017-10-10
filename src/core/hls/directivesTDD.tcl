## topTesting directives
set_directive_interface -mode ap_ctrl_none "topTesting" 
set_directive_interface -mode ap_fifo "topTesting" din
set_directive_interface -mode ap_fifo "topTesting" dout
set_directive_dataflow "topTesting"
config_dataflow -default_channel fifo -fifo_depth 32


## Functions directives
## Directives of scale2 function
set_directive_inline -off "scale2"
set_directive_inline "testing_scale2"
set_directive_inline "readParameters_scale2"
set_directive_inline "writeReturn_scale2"

## Directives of mult_hist_scale function
set_directive_inline -off "mult_hist_scale"
set_directive_inline "testing_mult_hist_scale"
set_directive_inline "readParameters_mult_hist_scale"
set_directive_inline "writeReturn_mult_hist_scale"

## Directives of sum_hist_pow function
set_directive_inline -off "sum_hist_pow"
set_directive_inline "testing_sum_hist_pow"
set_directive_inline "readParameters_sum_hist_pow"
set_directive_inline "writeReturn_sum_hist_pow"

## Directives of l2norm function
# set_directive_inline -off "l2norm"
# set_directive_inline "testing_l2norm"
# set_directive_inline "readParameters_l2norm"
# set_directive_inline "writeReturn_l2norm"

## Directives of scale1 function
# set_directive_inline -off "scale1"
# set_directive_inline "testing_scale1"
# set_directive_inline "readParameters_scale1"
# set_directive_inline "writeReturn_scale1"

## Directives of scale1_sqrt function
# set_directive_inline -off "scale1_sqrt"
# set_directive_inline "testing_scale1_sqrt"
# set_directive_inline "readParameters_scale1_sqrt"
# set_directive_inline "writeReturn_scale1_sqrt"

## Directives of sum_min_hist_scale function
# set_directive_inline -off "sum_min_hist_scale"
# set_directive_inline "testing_sum_min_hist_scale"
# set_directive_inline "readParameters_sum_min_hist_scale"
# set_directive_inline "writeReturn_sum_min_hist_scale"

## Directives of sum_hist function
# set_directive_inline -off "sum_hist"
# set_directive_inline "testing_sum_hist"
# set_directive_inline "readParameters_sum_hist"
# set_directive_inline "writeReturn_sum_hist"

## Directives of l1norm function
# set_directive_inline -off "l1norm"
# set_directive_inline "testing_l1norm"
# set_directive_inline "readParameters_l1norm"
# set_directive_inline "writeReturn_l1norm"

## Directives of l1sqrt function
# set_directive_inline -off "l1sqrt"
# set_directive_inline "testing_l1sqrt"
# set_directive_inline "readParameters_l1sqrt"
# set_directive_inline "writeReturn_l1sqrt"

## Directives of l2hys function
# set_directive_inline -off "l2hys"
# set_directive_inline "testing_l2hys"
# set_directive_inline "readParameters_l2hys"
# set_directive_inline "writeReturn_l2hys"
