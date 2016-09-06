all:
	make clean
	make prob1 prob2 prob3 prob4
prob1:
	g++ prob_1.cpp Stack.cpp -o prob1
prob2:
	g++ prob_2.cpp Stack.cpp -o prob2
prob3:
	g++ prob_3.cpp Deque.cpp -o prob3
prob4:
	g++ prob_4.cpp DoublyLinkedList.cpp Stack.cpp -o prob4
clean:
	rm -rf prob1 prob2 prob3 prob4
	
