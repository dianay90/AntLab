default: inputValidation.cpp antMain.cpp Menu.cpp Ant.cpp AntBoard.cpp
	g++ -std=c++0x inputValidation.cpp antMain.cpp Menu.cpp Ant.cpp AntBoard.cpp -o diana

clean: 
	rm diana 
	

