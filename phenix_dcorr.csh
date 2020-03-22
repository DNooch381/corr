#!/bin/csh
setenv HOME /phenix/u/$LOGNAME
source /etc/csh.login
foreach i (/etc/profile.d/*.csh)
  source $i
end
source $HOME/.login
source /opt/phenix/core/bin/phenix_setup.csh

echo now running with argument $1 $2 $3

./do_rangenx $1 $2 $3

