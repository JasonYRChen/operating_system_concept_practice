producer.o: producer.c
	gcc -c producer.c
producer: producer.o
	gcc producer.o -o producer
consumer.o: consumer.c
	gcc -c consumer.c
consumer: consumer.o
	gcc consumer.o -o consumer
main.o: main.c
	gcc -c main.c
main: main.o
	gcc main.o -o main
auto: producer.c consumer.c main.c
	make producer.o
	make producer
	make consumer.o
	make consumer
	gcc -c main.c
	gcc main.o -o main
