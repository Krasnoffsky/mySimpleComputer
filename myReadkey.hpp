#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#define ON 1
#define OFF 0

#define F5 
#define F6

struct termios term;

int rk_readkey (int *keys)
{
	int read_chars;
	char buf[20];
	if ((read_chars = read (0, buf, 19)) > 0){
		*keys = buf[0];
		return 0;
	} else {
		return -1;
	}
}

int rk_mytermsave (void){
	if(!tcgetattr(0, &term)){
		return 0;
	} else
		return -1;
}

int rk_mytermrestore (void){
	if(!tcsetattr(0, TCSAFLUSH, &term)){
		return 0;
	} else
		return -1;
}

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint){
	struct termios tfl;
	if (regime)
		tfl.c_lflag = tfl.c_lflag |(ICANON);
	else 
		tfl.c_lflag = tfl.c_lflag& (~ICANON);

	tfl.c_cc[VTIME] = vtime;
	tfl.c_cc[VMIN] = vmin;

	if (echo)
		tfl.c_lflag = tfl.c_lflag |(ECHO);
	else 
		tfl.c_lflag = tfl.c_lflag & (~ECHO);

	if (sigint)
		tfl.c_lflag = tfl.c_lflag |(ISIG);
	else 
		tfl.c_lflag = tfl.c_lflag & (~ISIG);
	if(tcsetattr(0, TCSAFLUSH, &term)){
		return -1;
	} else
		return 0;
}