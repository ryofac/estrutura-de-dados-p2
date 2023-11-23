#include <string.h>
#include <iostream>

#define ELEMENTO_VAZIO -10123

using namespace std;

class Pilha
{
private:
  int tamanho_max = 10;
  int topo = -1;
  int *elementos;

public:
  Pilha(int tamanho_max)
  {
    this->tamanho_max = tamanho_max;
    elementos = new int[tamanho_max];
  }

  bool is_empty()
  {
    return topo == -1;
  }

  bool is_full()
  {
    return topo >= tamanho_max - 1;
  }

  bool put(int item)
  {
    // Se a pilha está cheia
    if (is_full())
    {
      cout << "Pilha cheia :(" << endl;
      return false;
    }
    topo++;
    elementos[topo] = item;
    return true;
  }

  int pop()
  {
    if (is_empty())
    {
      cout << "Pilha vazia : (" << endl;
      return ELEMENTO_VAZIO;
    }
    int a_retornar = elementos[topo];
    topo--;
    return a_retornar;
  }

  int top()
  {
    return elementos[topo];
  }

  ~Pilha()
  {
    delete[] elementos;
  }
};

class Fila
{
private:
  Pilha *entrada;
  Pilha *saida;

public:
  Fila(int tamanho_max)
  {
    entrada = new Pilha(tamanho_max);
    saida = new Pilha(tamanho_max);
  }

  bool meter(int item)
  {
    if (entrada->is_full())
    {
      // cout << "Fila cheia paizao" << endl;
      return false;
    }
    entrada->put(item);
    return true;
  }

  int desenfileirar()
  {
    if (saida->is_empty())
    {
      if (entrada->is_empty())
        return ELEMENTO_VAZIO;

      // Invertendo a ordem com a ajuda da pilha saída auxiliar.
      while (!entrada->is_empty())
        saida->put(entrada->pop());
    }
    return saida->pop();
  }

  ~Fila()
  {
    delete entrada;
    delete saida;
  }
};

void mostrar_menu()
{
  cout << endl;
  cout << "1 - Inserir item" << endl;
  cout << "2 - Remover item" << endl;
  cout << "3 - Mostrar" << endl;
  cout << "0 - Sair" << endl;
}

int main()
{
  int opcao;
  Fila f(5);

  mostrar_menu();
  cout << ">> ";
  cin >> opcao;

  while (opcao != 0)
  {

    switch (opcao)
    {
    case 1:
      int novo_item;

      cout << "Novo item: ";
      cin >> novo_item;

      if (f.meter(novo_item))
      {
        cout << "Sucesso!" << endl;
      }
      else
      {
        cout << "Fila cheia!" << endl;
      }

      break;

    case 2:
      int item_removido;
      item_removido = f.desenfileirar();

      if (item_removido != ELEMENTO_VAZIO)
      {
        cout << "Item removido: " << item_removido << endl;
      }
      else
      {
        cout << "A fila esta vazia!" << endl;
      }

      break;

    default:
      cout << "Escolha um comando valido!" << endl;
      break;
    }

    mostrar_menu();
    cout << ">> ";
    cin >> opcao;
  };
}