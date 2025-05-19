#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <getopt.h>

using namespace std;



void readOsDateTime(int *date, int *month,int *year, int *hour, int *min, int *sec, int *wday)
{
	time_t current = time(NULL);
	struct tm *current_s = localtime(&current);

	if(current_s != NULL)
	{
		*date  =  current_s	->tm_mday;
		*month =  ++current_s	->tm_mon;
		*year  =  current_s	->tm_year;

		if(*year>100)
			*year = *year - 100;

		*hour  = current_s	->tm_hour;
		*min   = current_s	->tm_min;
		*sec   = current_s	->tm_sec;
		*wday  = current_s	->tm_wday;
	}
}

void sys_time(){

	//init all variable to 0
	int date   =0;
	int month  =0;
	int year   =0;
	int hour   =0;
	int min    =0;
	int sec    =0;
	int wday   =0;

	//define weekdays names
	string Names[] = {"Sunday","Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

	//function call that will assign date and time in variables
	readOsDateTime(&date, &month, &year, &hour, &min, &sec, &wday);
	//printing the date
    std::cout << "\t\t=--<< Javaline Date&Time >>---=\n" <<std::endl;
	cout<<"\t\t"<<date<<"/"<<month<<"/"<<year+2000<<"  "<<hour<<":"<<min<<":"<<sec<<"  "<<Names[wday];
	cout<<endl;   
     std::cout << "\t\t=----------------------------=\n" <<std::endl;    
    

}

int main(void){

    while(1){
    

    sys_time();
    sleep(1);
    system("clear"); 

    }

    return 0;
}