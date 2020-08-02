IDIR =inc
CFLAGS=-I$(IDIR)

main: test/main.cpp src/conv_layer.cpp src/model.cpp src/pooling_layer.cpp src/dense_layer.cpp src/tensor.cpp
	g++ test/main.cpp src/conv_layer.cpp src/model.cpp src/pooling_layer.cpp src/dense_layer.cpp src/tensor.cpp $(CFLAGS) -o main