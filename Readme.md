# Criação de fila usando pilhas

Uma fila pode ser criada usando um par de pilhas. Como dados inseridos em uma pilha são retirados em ordem inversa, o uso de duas pilhas possibilita que dados adicionados a uma pilha sejam retirados da outra pilha na ordem em que foram inseridos. O truque está na transferência dos dados de uma pilha para a outra.

Supondo que uma fila como essa, representada pelo tipo *Fila*, seja implementada com duas pilhas, escreva as funções *enfileira*, *desenfileira* e *comprimento*. As declarações do tipo *Fila* e dessas funções estão a seguir:

```c++
struct Fila {
  pilha<string>  p1, p2;
};

void enfileira(Fila & q, const string & dado);
string desenfileira(Fila & q);
int comprimento(Fila & q);
```

Implemente esse tipo de fila e suas funções. Use o arquivo *fila.h* para as declarações, e *fila.cpp* para implementá-las.
