#include<iostream>
#include<fstream>
#include<sys/sysinfo.h>
#include<string>
#include<thread>
#include<chrono>
#include<SFML/Window.hpp>

//class containing all the data memebers 


class Process{
	public:
		std::string s;

		int value = 0;

		int freemem = 0 ;

		float done = 0.0 ;

		float convert = 0.0 ;

		//function to read the proc/file 

		void  Memusage(){


			 
						
			//reading the memory from the file 
			std::ifstream file("/proc/meminfo");

			//checking if the file is open or not 

			if(!file.is_open()){
				std::cerr<<"Error Reading the file";
				


			}

			


			
	
			//getting the data from the file as input
					file>>s>>value>>s;
					convert = (float)value/1000000;

					file>>s>>freemem;
					done = (float)freemem/1000000;

					 

					
				


				
					


				              std::cout<<"Total Mem:" <<  convert<< " GB \n"
						<<"Used Mem:" <<done<< "GB \n"
						<<"\033[2A"
						<<std::flush;
					      

				
					

					std::this_thread::sleep_for(std::chrono::seconds(3));
		
				

 
				//closing the file 

				file.close();	

}

};
//main function


int main(){

	//creating a window 
	
	



	//creating an object for the class 
	Process monitor;
	//while loop to run this infintely 
	
	while(true){

		monitor.Memusage();
	}



	return 0;
}		
