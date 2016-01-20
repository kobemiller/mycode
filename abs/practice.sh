#!/bin/bash

# 在一个二元命令中提供一个占位符
: ${username=`whoami`}
# ${username=`whoami`}
# :和$之间必须有空格

# 使用参数替换来评估字符串变量
: ${HOSTNAME?} ${USER?} ${MAIL?}

# 变量扩展/字串替换
# 在和>结合使用时，把一个文件截断到0长度，没有修改它的权限,
# 如果文件在之前不存在，就创建它。
: > data.xxx    # 现在data.xxx被清空了
# 这与cat /dev/null > data.xxx的作用相同，
# 但是这不会产生一个新的进程，因为：是内建命令.

# ：还用来在/etc/passwd和$PATH变量中用来作分割符
