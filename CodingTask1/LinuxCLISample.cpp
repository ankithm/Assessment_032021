#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include <unistd.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 255

char GPIO_LOW[4]="0";
char GPIO_HIGH[4]="250";

bool EnableLogging=false;

int LogMessage(const char *format, ...)
{
	va_list args;
	if(EnableLogging)
	{
		va_start(args, format);
		vfprintf(stdout, format, args);
        	va_end(args);
	}
}


int ToggleFunc(char* inputGpio, char* outputGpio)
{
	int inputfd = -1, outputfd = -1;
	int ret=0;
	bool toggleFlag = false;
	char buff;

	inputfd = open(inputGpio, O_RDONLY);
	if(inputfd < 0)
	{
		LogMessage("%s open failed", inputGpio);
		return -1;
	}

	outputfd = open(outputGpio, O_RDWR);
	if(outputfd < 0)
	{
		LogMessage("%s open failed", outputGpio);
		return -1;
	}

	while(1)
	{
		ret = read(inputfd, (char *)&buff, 1);
		if(buff == '0')
		{
			LogMessage("gpio %s OFF\n",inputGpio); 
			printf("gpio %s OFF\n",inputGpio); 
			write(outputfd, GPIO_LOW, 4);
		}	
		else if(buff == '1')
		{
			LogMessage("gpio %s ON",inputGpio); 
			printf("gpio %s ON",inputGpio); 
			if(toggleFlag == false)
			{
				toggleFlag = true;			
				write(outputfd, GPIO_LOW, 4);
			}
			else
			{
				toggleFlag = false;
				write(outputfd, GPIO_HIGH, 4);
			}
		}
		else
		{
			printf("other than 0 and 1");
		}
		lseek(inputfd, 0, SEEK_SET);
		usleep(1000000);		//1sec
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

	LogMessage("LM -i %s -o %s\n",gpioInputName, gpioOutputName);
	printf("P -i %s -o %s\n",gpioInputName, gpioOutputName);
	ToggleFunc(gpioInputName, gpioOutputName);
}
