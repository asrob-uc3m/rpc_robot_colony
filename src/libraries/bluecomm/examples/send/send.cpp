////////////////////////////////////////////
//BLUETOOTH COMMUNICATIONN
//	   Sending Program
//
//Jon Goitia 3/2/2012
////////////////////////////////////////////

#include <iostream>
#include <SerialPort.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>

#define TIMEOUT_USEC 10000

using namespace std;

void setup_terminal(){	// Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int consola_io_kbhit(void){
  int n;
  fd_set rfd;
  struct timeval timeout;

  timeout.tv_sec  = 0;
  timeout.tv_usec = TIMEOUT_USEC;

  FD_ZERO(&rfd);
  FD_SET(STDIN_FILENO,&rfd);

  n = select(STDIN_FILENO+1,&rfd,NULL,NULL,&timeout);

  return n;
}

char consola_io_getch(void){
  int n;
  char c;

  while (!consola_io_kbhit());

  n = read(STDIN_FILENO,&c,1);

  return c;
}

int main(int argc, char **argv){

	setup_terminal();	//No buffering, no echo in terminal
	
	//-- Check if the serial device name is given
  	if (argc<2) {
    	cerr << "No serial device name is given" << endl;
    	return 1;
  	}

  	cout << "Serial port: " << argv[1] << endl;
  	cout << "Opening..." << endl;

  	//-- Open the serial port
  	//-- Serial port configuration: 9600 baud, 8N1
  	SerialPort serial_port(argv[1]);
  	try {
    	serial_port.Open(SerialPort::BAUD_9600,
                     	SerialPort::CHAR_SIZE_8,
                     	SerialPort::PARITY_NONE,
                     	SerialPort::STOP_BITS_1,
                     	SerialPort::FLOW_CONTROL_NONE);
  	}
  	catch (SerialPort::OpenFailed E) {
    	cerr << "Error opening the serial port" << endl;
    	return 1;
  	}
  
  	cout<< argv[1] << " opened successfully" << endl;

    string c;
    int a=0;
    while(a<20){
		if (consola_io_kbhit()){
		    c=consola_io_getch();
		    //cout << c << endl;
		    serial_port.Write(c);
		    if (c=="p"){break;}
		}
	}
	
	serial_port.Close();
	cout<<"Program ended correctly"<<endl;
    return 0;
}
