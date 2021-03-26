#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include <unistd.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 255



bool EnableLogging=false;

int LogMessage(const char *format, ...)
{
	va_list args;
	if(EnableLogging)
	{
		va_start(args, format);
		printf(format, args);
        	va_end(args);
	}
}

int main(int argc, char *argv[]){
	bool gpioInputFlag=false, gpioOutputFlag=false;
        char gpioInputName[MAX_ARG_LENGTH], gpioOutputName[MAX_ARG_LENGTH];

	for(int i=1; i< argc; ++i){
		if(0==strcmp(argv[i],"--log")){
			EnableLogging=true;
		}
		else if(0==strcmp(argv[i],"--help")){
			//TO DO -> print help info
			printf("TO DO Help Info\n");
			return 0;
		}
		else if(0==strcmp(argv[i],"-i")){
                	if((i+1) < argc)
			{
				gpioInputFlag = true;
				strncpy(gpioInputName, argv[i+1], MAX_ARG_LENGTH);
				continue;
			}
		}
		else if(0==strcmp(argv[i],"-o")){
                	if((i+1) < argc)
			{
				gpioOutputFlag = true;
				strncpy(gpioOutputName, argv[i+1], MAX_ARG_LENGTH);
				continue;
			}
		}
	}

	if((gpioInputFlag == false) || (gpioOutputFlag == false))
	{
		printf("Invalid Arguments.. type --help for information\n");
		return -1;
	}

}
