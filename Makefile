CFLAGS=`pkg-config --cflags opencv`
LIBS=`pkg-config --libs opencv`

%: %.cpp
	g++ `pkg-config opencv --cflags --libs` -o $@ $<
