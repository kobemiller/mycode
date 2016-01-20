#!/bin/bash

#
# 检查被调用的参数是否正确
#
E_WRONG_ARGS=65
script_parameters="-a -h -m -z"

if [ $# -ne $Number_of_expected_args ]
then
    echo "Usage:`basename $0` $script_parameters"
    exit $E_WRONG_ARGS
fi

