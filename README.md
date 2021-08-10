# Shell Vip Utility written in C for *NX Systems

Simple: Vip shell to avoid usage of sudo

#

Crafted / developed by Software Engineer - Felipe Alfonso González - f.alfonso@res-ear.ch

#instructions

You need to install tcsh:
in Debian GNU/Linux : sudo apt-get install tcsh

 | gunzip vip.c.gz
 
 | sudo gcc -o vip vip.c (compilation)
 
 
 | su
 
 | vi /etc/group (nuevo grupo, ej.: staff:x:100:user
 | vim visudo
 | #
 

# User privilege specification
root    ALL=(ALL:ALL) ALL
 
vip     ALL=(ALL:ALL) ALL
 
 | mv vip /usr/bin/
 
 | exit
 
 | vip
 
 then,
execute it as a user:
 sudo vip
 

