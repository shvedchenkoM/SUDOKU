sudoku-app: logic.o grid.o gameView.o gameOver.o panel.o
	g++ logic.o grid.o gameView.o gameOver.o panel.o -o sudoku-app -lsfml-graphics -lsfml-window -lsfml-system -std=c++14

grid.o: grid.cpp
	g++ -c grid.cpp -std=c++14

logic.o: logic.cpp
	g++ -c logic.cpp -std=c++14

gameView.o: gameView.cpp
	g++ -c gameView.cpp -std=c++14

gameOver.o: gameOver.cpp
	g++ -c gameOver.cpp -std=c++14

panel.o: panel.cpp
	g++ -c panel.cpp -std=c++14

clean:
	rm -f *.o
	rm -f sudoku-app
   


