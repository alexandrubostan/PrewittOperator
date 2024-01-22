CXX=g++
RM=rm -f

TARGET=main
TARGETFOLDER=bin

CPPFLAGS=-g -Wall -Wextra

SRCFOLDER=src

SRCS=$(SRCFOLDER)/bmpfileheader.cpp $(SRCFOLDER)/bmpinfoheader.cpp $(SRCFOLDER)/prewitt.cpp $(SRCFOLDER)/main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CPPFLAGS) -o $(TARGETFOLDER)/$(TARGET) $(SRCS)

clean:
	$(RM) $(TARGETFOLDER)/$(TARGET)
