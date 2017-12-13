#Batalha de Robôs

##TecProg-2017

##Projeto para a matéria MAC216 - 2017/2

Seja bem vindo à Batalha de Robôs!

O objetivo é simples: o primeiro time que depositar 5 cristais na base inimiga é o vencedor!

Para isso, você deve programar seus robôs para que encontrem a maneira mais eficiente de se locomover através do terreno, de atacar inimigos, pegar cristais e é claro, destruir bases.

##Linguagem 
A linguagem que os robôs utilizam é uma mistura de C e Python: a sintaxe é quase idêntica ao C, mas as variáveis não possuem tipos, como em Python.

Para alterar os programas dos robôs, basta editar os arquivos rob0, rob1, etc - cada arquivo desses corresponde ao programa de um dos 10 robôs. Os robôs do time azul são: rob0, rob1, rob2, rob3, rob4
Os robôs do time vermelho são: rob5, rob6, rob7, rob8, rob9

###Peças básicas
>Atribuições:
>> Comum: x = 5;
>> Atributos: x = tile.cristais;
> Controle de fluxo:
>> Condicionais: if(x < 5) { *code* }
		 else { *more code* }
>> Laços: while (True) { *code* }
	  for (i = 1; i < 5; i*=2) { *code* }
> Chamadas de sistema
>> VER: Atualiza os dados que o robô tem dos seus arredores - ver();
>> MOVE: Move o robô na direção indicada - move(NW);
>> ATACA: Ataca a direção indicada - ataca(NW);
>> RECOLHE: Recolhe cristal na direção indicada - recolhe(NW);
>> DEPOSITA: Deposita cristal na direção indicada - deposita(NW);
>> JOGA_CRISTAL: Joga um cristal na direção indicada, fazendo com o que o robô atingido fique atordoado e derrube seus cristais- joga_cristal(NW);
>> KAMIKAZE: Robô se explode e atordoa todos os robôs ao seu redor - kamikaze(); 
>> Resposta: Não é uma chamada de sistema, mas retorna o resultado da última chamada realizada (1 = sucesso, -1 = fracasso)
> Funções:
>> Declaração: func f(x, y) { return x+y } ou def g(x) { return; }
>> Chamadas: w = f(x, y) ou g(w);
>> Variáveis locais: Como em C, as variáveis declaradas dentro do seu programa possuem um escopo limitado: variáveis declaradas fora de funções são consideradas globais e acessíveis de qualquer lugar. Se você quer declarar uma nova variável, dentro de uma função, com um nome igual ao de uma variável global preexistente, basta usar a keyword *new*: 

my_global = 5;

def my_function(){
	new my_global = 25;
	print(my_global);
	return;
}
O código acima imprimirá 25

##Game Logic
Para programar os robôs de maneira ótima, é importante entender algumas coisas sobre o mundo:
>Tiles: Cada hexágono da arena representa um tile e possui 4 atributos:
>> Terreno: Estrada << Grama << Areia << Água << Montanha - em ordem crescente de dificuldade de travessia.
>> Cristais: Quantos cristais existem nesse tile.
>> Ocupado: Qual robô ocupa este tile (-1) se não houver
>> Base: Este terreno é uma base? 1 se for, 0 se não.
>Direções: São representadas da seguinte forma:
>>N: Norte
>>NW: Noroeste
>>SW: Sudoeste
>>S: Sul
>>SE: Sudeste
>>NE: Nordeste
>>CN: Centro (tile que o robô está ocupando no momento)
>Robôs: Cada robô tem 100 pontos de vida - um ataque normal causa 50 de dano, e um kamikaze, 100. Cada vez que precisa chamar o sistema, o robô perde sua vez - use essa informação para planejar as melhores maneiras de finalizar seu turno. Além disso, sempre que um robô fica com 0 de vida, ele fica incapacitado por 5 turnos.
