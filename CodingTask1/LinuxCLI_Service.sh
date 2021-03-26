#!/bin/bash
# Description: Linux CLI GPIO Application Service

BASE_PATH=/usr/bin
LINUX_CLI_EXE=LinuxCLISample

function init(){

	#Setting the LED to OFF upon Init
        echo 0 > /sys/class/leds/EB:blue:usr1/brightness;

        #Enable Push Button GPIO
        echo 105 > /sys/class/gpio/export && echo "in" > /sys/class/gpio/gpio105/direction

        #Give Executable Permissions
        chmod u+x $BASE_PATH/$LINUX_CLI_EXE
}

case "$1" in
    start)
        init
        echo "Starting Linux CLI App"
        $BASE_PATH/$LINUX_CLI_EXE -i /sys/class/gpio/gpio105/value -o /sys/class/leds/EB:blue:usr1/brightness --log &
        #$BASE_PATH/$LINUX_CLI_EXE &
        ;;
    stop)
        echo "Stopping Linux CLI App"
        killall $LINUX_CLI_EXE
        ;;
    restart)
        $0 stop && $0 start
        ;;
    *)
        echo "Usage: service $0 {start|stop|restart}"
        exit 1
esac

exit 0
