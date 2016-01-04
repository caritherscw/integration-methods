Gpp=g++
srcs=$(wildcard *.cpp)
objs=$(srcs:.cpp=.o)
deps=$(srcs:.cpp=.d)

default:test

%.o:%.d
	$(Gpp) -c $*.cpp

%.d:%.cpp
	echo -n "$*.d ">$*.d
	$(Gpp) -MM $*.cpp>>$*.d

test: $(objs)
	$(Gpp) $^ -o $@

-include $(deps)

.PHONY:clean default

clean:
	-rm -rf *.o test *.d