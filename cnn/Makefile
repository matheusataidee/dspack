IDIR =inc
CFLAGS=-I$(IDIR)

main: tst/main.cpp src/conv_layer.cpp src/model.cpp src/pooling_layer.cpp src/dense_layer.cpp src/tensor.cpp
	g++ tst/main.cpp src/conv_layer.cpp src/model.cpp src/pooling_layer.cpp src/dense_layer.cpp src/tensor.cpp $(CFLAGS) -o main
