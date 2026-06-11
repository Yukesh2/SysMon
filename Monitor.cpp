#include<iostream>
#include<fstream>
#include<sys/sysinfo.h>
#include<string>
#include<thread>
#include<chrono>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

//class containing all the data memebers 


class Process{
	public:
		std::string s;

		int value = 0;

		int freemem = 0 ;

		float done = 0.0 ;

		float convert = 0.0 ;

		//function to read the proc/file 

		std::string  Memusage(){


			 
						
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

					float used = convert - done;

					


					

					

					 

					
				


				
					


				    return "Total Mem: " + std::to_string(convert) + " GB\n" +
           "Unused Mem: " + std::to_string(done) + " GB\n" +
           "Used: " + std::to_string(used) + " GB";


				
					

					std::this_thread::sleep_for(std::chrono::seconds(3));
		
				

 
				//closing the file 

				file.close();	

}

};
//main function


int main(){

	//creating a window 
	Process monitor;

	sf::RenderWindow window(sf::VideoMode({400,300}),"SiMon");
	sf:: Font font;
	font.openFromFile("arial.ttf");
	sf::Text text(font);


	text.setCharacterSize(25);

       
	text.setFillColor(sf::Color::Red);
					
	text.setPosition({10.f,10.f});
	

 
 
     while (window.isOpen())
    {
    
       
	    text.setString(monitor.Memusage());  // ← give result to text
	    window.clear();

	    window.draw(text);

	    window.display();
        // Process events
        while (const std::optional event = window.pollEvent())
        {
		
            // Close window: exit
            if (event->is<sf::Event::Closed>())

                window.close();
        }

    }
     window.clear();


	


    
     return 0;
}		
