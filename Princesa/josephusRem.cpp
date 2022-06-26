#include<iostream>

class node{
	public:
		node *prox;
		int val;
		node(int val);
};
node::node(int val)
{
	this->val = val;
}
class List{
	node *atual , *espada;
	public:
		List(){
		atual = espada = NULL;
		}
		void add(int val);
		void print();
		int josephus();
};
void List::add(int val)
{
	node *n = new node(val);
	if(espada == NULL)
	{
		espada = n;
		espada->prox = espada;
		atual = espada;
		return;
	}
	atual->prox = n;
	atual = atual->prox;
	atual->prox = espada;
}
int List::josephus()
{
	atual = espada;
	node *del = espada->prox;
	int val;
	while(espada->prox != espada)
	{
		for(int i = 1; i < 3; i++)
		{
			atual = atual->prox;
			del = del->prox;
		}
		
		atual->prox = del->prox;
		if(del == espada)
		{
			espada = espada->prox;
		}
		val = del->val;
		delete del;
		atual = atual->prox;
		del = atual->prox;
		std::cout << "( " << val << " morreu ) " << "  "; 
		
	}
	std::cout << std::endl;
	return espada->val;
}
void List::print()
{
	atual = espada;
	std::cout << "[ ";
	do{
		std::cout << atual->val << " ";
		atual = atual->prox;
	}while(atual != espada);
	std::cout << "]\n";
	
	
}
int main()
{

	int tam = 0;
	std::cin >> tam;
	List l;
	
	for(int i = 1; i < tam; i++){
		l.add(i);
	}

	l.print();
	std::cout << "vencedor ( " << l.josephus()<< " )";
}