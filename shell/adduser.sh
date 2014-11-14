#!/bin/sh -e
   . /etc/init.d/functions
      
      for n in $(seq -w 10)
             do  
                        passwd=`echo $(date +%t%N)$RANDOM|md5sum|cut -c 2-9`
                               useradd kobemiller-$n >&/dev/null && user_status=$?
                                      echo "$passwd"|passwd --stdin kobemiller-$n >&/dev/null && pass_status=$?
                                             
                                             if [ $user_status -eq 0 -a $pass_status -eq 0 ]
                                                        then
                                                                       action "adduser kobemiller-$n" /bin/true
                                                                                  echo -e "user:\tkobemiller-$n pass:\t$passwd" >>./user.log
                                                                                         else
                                                                                                        action "adduser kobemiller-$n" /bin/false
                                                                                                                   echo -e "user:\tkobemiller-$n pass:\t$passwd" >>./fail_user.log
                                                                                                                          fi  
                                                                                                                             done

