#include <wiringPi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int i;
	int ii;
	int n;
	int nn;
	double d;
	double dd;
	time_t t;
	time_t tt;
	if(argc<3)exit(1);
	i=wiringPiSetup();
	if(i==-1)exit(1);
	d=atof(argv[1]);
	d=1/d*500;
	i=(int)d;
	dd=atof(argv[2]);
	ii=(int)dd;
	pinMode(7,1);
	t=time(NULL);
	t+ii;
	while(1){
		digitalWrite(7,1);
		for(n=0;n<i;n++)usleep(1000);
		digitalWrite(7,0);
		for(n=0;n<i;n++)usleep(1000);
		if(time(NULL)>t)goto exits;
	}
	exits:
	return 0;
}
