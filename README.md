# Shell Vip Utility written in C for *NX Systems

Simple: Vip shell to avoid usage of sudo

#

Crafted / developed by Software craftsman - Felipe Alfonso González - f.alfonso@res-ear.ch

#instructions

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
 

