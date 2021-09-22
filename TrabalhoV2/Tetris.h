#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris{
	public:
		//Inicialização
	    Tetris(const int size);
		Tetris(const Tetris &game);
	    ~Tetris();
		Tetris &operator=(const Tetris &game);
	    
		//Gets
		char get(int c, int l)const;
	    int getNumColunas()const;
	    int getAltura(int c)const;
	    int getAltura()const;
		int getMinHeight()const;
	    
		//Adição de peças
	    bool adicionaForma(int c, int l, char id, int r);
	    
		//Remoção 
		void removeColuna(int c);
	    void removeLinhasCompletas();
	
	private:
	    int columns;
	    int *alturas;
	    char **jogo;
	    
		//Adição de peças
	    bool addI(int c, int l, int r);
	    bool addJ(int c, int l, int r);
		bool addL(int c, int l, int r);
		bool addO(int c, int l, int r);
		bool addS(int c, int l, int r);
		bool addT(int c, int l, int r);
		bool addZ(int c, int l, int r); 

		//Set
		void set(int c, int l, char value);
		
		//Auxiliares
		bool isFilled(int c, int l)const;
		bool isSmallerThen(int a, int b)const;
		bool isBiggerThen(int a, int b)const;
		bool areEquals(int a, int b)const;
		const char empty()const;
};

#endif
