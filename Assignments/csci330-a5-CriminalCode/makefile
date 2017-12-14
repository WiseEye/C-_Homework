PROGRAM = main
FILES =  main.cpp utilities/FileReader.cpp utilities/helper.cpp utilities/UserInput.cpp NumDays.cpp PersonnelReport.cpp TimeOff.cpp

all: run
run: zip
zip: build
build: clean

run:
	./$(PROGRAM).o

zip:
	rm -f $(PROGRAM).zip
	zip $(PROGRAM).zip *.cpp *.h makefile

build:
	clear
	clear
	clear
	clear
	g++ $(FILES) -o $(PROGRAM).o

clean:
	rm -f *.zip
	rm -f *.o
