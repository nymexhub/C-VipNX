/*
 * Developed and engineered by Felipe Alfonso gonzalez <f.alfonso@res-ear.ch>
 * Under GNU/GPL
 *************************************
 * gunzip vip.c.gz
 * gcc -o vip vip.c (compilation)
 * su
 * vi /etc/group (nuevo grupo, ej.: staff:x:100:user)
 * mv vip /usr/bin/
 * exit
 * vip
 * */

# include <stdio.h>

# define MAXLENCMD	1024*6

main( na, arg )
int na;
char *arg[];
{
	char cmd[MAXLENCMD+1];
        int  pid, rc, i, p;

	setuid(0);
	setgid(1);

	fprintf(stderr,"Starting Vip Shell ...\n" );
	if( na < 2 )
	{
		if( (pid=fork()) == -1 )  {
		    fprintf( stderr, "Fork Failed.\n" );
		    exit(0);
                }
		else if( pid == 0 ) {
		    execl( "/usr/local/bin/tcsh", "tcsh", NULL );
		    execl( "/bin/tcsh", "tcsh", NULL );
		    execl( "/usr/bin/tcsh", "tcsh", NULL );
                }
		else  {
		    while( (p=wait(&rc)) != -1 && p != pid );

		    fprintf(stderr,"Vip Shell Ending.\n" );
		    exit(0);
	        }	
	}
	for( i=1, cmd[0]=0; i < na ; i++ )
	{
		if( (strlen(cmd) + strlen(arg[i]) + 1) > MAXLENCMD )
		{
			fprintf(stderr, "Too many arguments, sorry ....\n");
			fprintf(stderr,"Vip Shell Ending.\n" );
			exit(1);
		}
		strcat(cmd, arg[i]);
		strcat(cmd, " " );
	}
	system( cmd );
	fprintf(stderr,"Vip Shell Ending.\n" );
}



