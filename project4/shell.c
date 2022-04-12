#include "userlib.h"

char* getcommand(char* line);
char* getfilename(char* line);
int compareCommand(char* cmd1, char* cmd2);

void main() {
  char command[80];
  char buffer[13312]; //buffer stores the contents from the file when file is read/program is executed
  int flag = 0; //true if file/program is found and can be executed
  
  while(1){
    //Print out shell command as "Shell> "
    printString("Shell> \0");

    //get the command
    readString(command);
    printString("\r\n\0");

    //compare command and execute it accordingly
    
    //command is "type"
    if (command[0] == 't' && command[1] == 'y' && command[2] == 'p' && command[3] == 'e' && command[4] == ' ') {
      //printString("Command is type.\r\n\0");
      
      flag = readfile(command+5, buffer);

      if (flag != -1) { //file was found
	printString(buffer);
      } else { //file not found, display error
	printString("Error: file not found\r\n\0");
      }
    }
    
      //command is "execute"
    else if (command[0] == 'e' && command[1] == 'x'&& command[2] == 'e' && command[3] == 'c' && command[4] == 'u' && command[5] == 't' && command[6] == 'e' && command[7] == ' ') {
      //printString("Command is execute.\r\n\0");

      flag = executeProgram(command+8, 0x2000);

      if (flag == -1) { //file was found
	printString("Error: cannot execute file.\r\n\0");
      } else if (flag == -2) {
	printString("Invalid segment.\r\n\0");
      } else {
	printString("Program was executed.\r\n\0");
      }

      //command is invalid 
    }
    
      //command is "delete"
    else if (command[0] == 'd' && command[1] == 'e'&& command[2] == 'l' && command[3] == 'e' && command[4] == 't' && command[5] == 'e' && command[6] == ' ') {
      printString("Command is delete.\r\n\0");

      flag = deleteFile(command+7);

      if (flag == -1) { //file was found
	printString("Error: cannot delete file because file not found.\r\n\0");
      } else {//file was found
	printString("Successfully deleted file.\r\n\0");
      }

      //have to add write file here
      
      //command is invalid 
    }

    //command is "copy"
    else if (command[0] == 'c' && command[1] == 'o'&& command[2] == 'p' && command[3] == 'y' && command[4] == ' ') {
      printString("Command is copy.\r\n\0");

      //from index 5, iterate through the remaining characters until we find a space, say we found space at index n, src = command+5 to command+(n-1), dest = command+n+1
      //read file (src)
      //write file (dest)

      //iif statements to recognize if it was successful or not
      //readfile = -1 "file not found"
      //writefile = -1 "Disk directory is full"
      //writefile = -2 "Disk is full"
      
      //command is invalid 
    }else { 
      printString("Unrecognized command.\r\n\0");
    }
    
  }
}
