Minha Explicação:


Este projeto foi desenvolvido em linguagem C utilizando estruturas de dados encadeadas. O objetivo do sistema é permitir que o usuário adicione tarefas, visualize tarefas pendentes, conclua tarefas e desfaça a última conclusão realizada.

Para desenvolver o sistema foram utilizadas duas estruturas de dados: Fila e Pilha.

A fila foi utilizada para armazenar as tarefas pendentes. A escolha da fila faz sentido porque as tarefas devem ser executadas na mesma ordem em que foram cadastradas. Esse comportamento segue o conceito FIFO (First In, First Out), ou seja, o primeiro elemento que entra é o primeiro a sair.

A pilha foi utilizada para armazenar o histórico das tarefas concluídas. Isso permite que o usuário possa desfazer a última conclusão realizada. A pilha segue o conceito LIFO (Last In, First Out), onde o último elemento inserido é o primeiro a ser removido.

No início do código são utilizadas as bibliotecas stdio.h, stdlib.h e string.h. A biblioteca stdio.h é utilizada para funções de entrada e saída como printf, scanf, fopen e fclose. A biblioteca stdlib.h é utilizada para funções relacionadas à memória, como malloc e free. Já a string.h é utilizada para manipulação de textos através de funções como strcpy.

A linha "#define ARQUIVO "tarefas.txt"" cria uma constante que armazena o nome do arquivo utilizado para salvar e carregar os dados do sistema. Dessa forma, caso seja necessário alterar o nome do arquivo, basta modificar apenas essa linha.

A estrutura No representa cada nó da lista encadeada. Cada nó possui um campo chamado tarefa, responsável por armazenar o texto da tarefa, e um ponteiro chamado next, que guarda o endereço do próximo nó da estrutura.

A estrutura Fila possui dois ponteiros: front e rear. O ponteiro front aponta para o primeiro elemento da fila e o ponteiro rear aponta para o último elemento.

A estrutura Pilha possui apenas um ponteiro chamado top, que aponta para o elemento localizado no topo da pilha.

A função inicializarFila é responsável por criar uma fila vazia, atribuindo NULL aos ponteiros front e rear. Da mesma forma, a função inicializarPilha cria uma pilha vazia atribuindo NULL ao ponteiro top.

A função enqueue é utilizada para inserir uma nova tarefa na fila. Primeiro é criado um novo nó utilizando malloc. Em seguida, o texto da tarefa é copiado para o nó utilizando strcpy. Caso a fila esteja vazia, o novo nó passa a ser o primeiro e o último elemento. Caso contrário, o novo nó é adicionado ao final da fila.

A função dequeue é responsável por remover a primeira tarefa da fila. Ela salva temporariamente o primeiro nó, copia o conteúdo para uma variável auxiliar, move o ponteiro front para o próximo elemento e libera a memória ocupada pelo nó removido através da função free.

A função push é utilizada para inserir elementos na pilha. Um novo nó é criado e ligado ao topo atual da pilha. Em seguida, esse novo nó passa a ser o novo topo.

A função pop remove o elemento que está no topo da pilha. O topo atual é armazenado temporariamente, o ponteiro top passa a apontar para o próximo elemento e a memória utilizada pelo nó removido é liberada.

A função listarTarefas percorre toda a fila utilizando um ponteiro auxiliar e exibe cada tarefa cadastrada pelo usuário.

A função salvarArquivo grava todas as tarefas pendentes em um arquivo chamado tarefas.txt. Para isso, ela percorre toda a fila e escreve cada tarefa em uma linha do arquivo.

A função carregarArquivo é executada quando o programa inicia. Ela abre o arquivo tarefas.txt, lê cada linha e utiliza a função enqueue para reconstruir a fila na memória. Dessa forma, as tarefas permanecem disponíveis mesmo após o encerramento do programa.

Na função main são criadas as estruturas fila e histórico. Em seguida, elas são inicializadas e os dados salvos anteriormente são carregados do arquivo.

O programa apresenta um menu interativo contendo as opções de adicionar tarefa, listar tarefas, concluir tarefa, desfazer conclusão, salvar e sair. Após executar qualquer operação, o sistema retorna ao menu principal até que o usuário escolha a opção de sair.

Quando uma tarefa é concluída, ela é removida da fila através da função dequeue e adicionada à pilha utilizando a função push. Quando o usuário escolhe desfazer a última conclusão, a tarefa é removida da pilha utilizando a função pop e adicionada novamente à fila utilizando a função enqueue.

Ao encerrar o programa, as tarefas pendentes são salvas automaticamente no arquivo para que possam ser recuperadas na próxima execução.

Este projeto permitiu aplicar na prática os conceitos de listas encadeadas, filas, pilhas, alocação dinâmica de memória, manipulação de arquivos e organização de código em linguagem C para resolver um problema real de forma simples e funcional.
