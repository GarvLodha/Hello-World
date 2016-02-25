#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>	//appended
using namespace std;
//string ReturnDateTime(int days);	
//string ReturnDateTime(time_t &ptime);	

int main() 
{
	time_t ctime = time(NULL);
	printf("I am here at: %s.\n", asctime(localtime(&ctime)));
	int durationDays = 7;	//'endDataTime' variable in reqHistoricalData increments by 'durationDays'
	time_t pTime;	//local time
//	char str[80];
//	char * str = new char[80];	//alternative statement to create an array of '80' characters.
	char * str = new char[8];	//alternative statement to create an array of '8' characters.
	struct tm *pPtr;	//pointer to past time
	pTime = time(NULL);
	pPtr = localtime(&pTime);
	cout << time(NULL);
	cout << "Current time is: " << pTime << endl;
	cout << "Current year is: " << pPtr->tm_year << endl;	
	

	if(pTime != (time_t)-1)
      	{
/*******Set the beginning date and time*******/
//		pPtr -> tm_year -= (1);	//years since 1900		
//		pPtr -> tm_year = 111 ;	//years since 1900		
		pPtr -> tm_mon = 2;	//months since January(0-11)
		pPtr -> tm_mday = 3;	//day of the month(1-31)
		cout << "It is: " << pPtr->tm_mday << "th day of the month: " << pPtr->tm_mon << endl;
		pTime = mktime(pPtr);
//		while(pPtr->tm_mday <= lPtr->tm_mday && pPtr->tm_mon <= lPtr->tm_mon && pPtr->tm_year <= lPtr->tm_year)
		while(pTime <= time(NULL))
		{
//      		strftime(str,80,"%Y%m%d",pPtr);	//format time to string
      			strftime(str,9,"%Y%m%d",pPtr);	//format time to string
//			cout << str << endl;
			string endDateTime;	//endDateTime in IB  format
/*******Concatenate the characters in 'str' array.*******/
			for(int i = 0; i <=7 ; i++)
			{
				endDateTime += str[i];
//				printf("%i\n",endDateTime);
			}	
			
			endDateTime = endDateTime + " " + "03:30:00";
			cout << "endDateTime is: " << endDateTime << endl ;
//			reqHistoricalData();
			pPtr->tm_mday += durationDays;
			pTime = mktime(pPtr);
			cout << pPtr->tm_mday << "day of the month: " << pPtr->tm_mon << "of the year: " << pPtr->tm_year << endl;
			cout << pPtr->tm_wday << "day of the week." << endl << endl;
			
		}
	}		
	
/*	int j = 0;
	for(int i = 0; i < 60 ; i++)
	{
		cout << ReturnDateTime(j) << endl;	
		j += 7;
	}*/
      	return 0;
}

/*string ReturnDateTime(int days)
{
	struct tm *ptr;
	time_t ltime;
	char str[80];
	string s;	//appended
	ltime = time(NULL); //return system time 
//	cout << ltime << endl;
	ptr = localtime(&ltime); // return time in the form of tm structure
	strftime(str,80,"%Y%m%d",ptr);
//	printf("%s\n",str);
	if(ltime != (time_t)-1)
      	{
      		ptr = localtime(&ltime); // return broken down time */ 
/*******Set the beginning date and time*******/
/*		ptr -> tm_year -= (1);	//years since 1900		
		ptr -> tm_mon = 0;	//months since January(0-11)
		ptr -> tm_mday = 1;	//day of the month(1-31)
      		strftime(str,80,"%Y%m%d",ptr);
//     		puts(str);
//     		ptr->tm_hour-=24;
//     		ptr->tm_hour-=(24 * 6) ;
//		cout << "Day of the month is " << ptr -> tm_mday << endl;
//		cout << "Hour is" << ptr -> tm_hour << endl;
//     		ptr->tm_hour-=(24 * days) ;
//     		ptr->tm_mday-=(90) ;
//     		ptr->tm_mday-=(days);
     		ptr -> tm_mday += (days);	//day of the month(1-31)
//		cout << "Hour is" << ptr -> tm_hour << endl;
//		cout << "Year is:" << ptr -> tm_year << endl;
      		ltime = mktime(ptr);
//		cout << ltime << endl;
     		ptr = localtime(&ltime);
      		strftime(str,80,"%Y%m%d",ptr);
//     		puts(str);

		for(int i = 0; i <=7 ; i++)
		{
			s += str[i];
//			printf("%i\n",s);
		}	

		string t = "03:30:00";
//		cout << "Date is:" << s + " " +  t << endl;
		string dateTime;
		dateTime = s + " " + t;
		return dateTime;
	}
      else 
//		puts("Time is not available");
		return "Time is not available";		
}*/
