#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
#include "TADBaralho.h"
struct tpCoordenadas{
	int x1,x2,y1,y2;
};

//funções de exibição
void drawSquare(int x1, int y1, int x2, int y2) {
    int i, j;
    
    gotoxy(x1,y1); printf("%c", 201);
	gotoxy(x1,y2); printf("%c", 200);
	gotoxy(x2,y1); printf("%c", 187);
	gotoxy(x2,y2); printf("%c", 188);

    // Desenhar linhas horizontais
    for (i = x1+1; i < x2; i++) {
        gotoxy(i, y1); printf("%c",205);
        gotoxy(i, y2); printf("%c",205);
    }

    // Desenhar linhas verticais
    for (j = y1+1; j < y2; j++) {
        gotoxy(x1, j); printf("%c",186);
        gotoxy(x2, j); printf("%c",186);
    }
    printf("\n");
}
void drawHCard(tpCoordenadas pos, tpCarta carta){
	pos.y2=pos.y1+3;
	drawSquare(pos.x1,pos.y1,pos.x2,pos.y2);
	if(carta.status==1){
		switch(carta.naipe){
			case 1: textcolor(4); gotoxy(pos.x1+1,pos.y1+2);printf("%c",4);
				break;
			case 2: textcolor(15); gotoxy(pos.x1+1,pos.y1+2);printf("%c",6);
				break;
			case 3: textcolor(4); gotoxy(pos.x1+1,pos.y1+2);printf("%c",3);
				break;
			case 4: textcolor(15); gotoxy(pos.x1+1,pos.y1+2);printf("%c",5);
		}
		if(carta.valor==1){
			gotoxy(pos.x1+1,pos.y1+1);printf("%c",65);
		}
		else
			if(carta.valor>10){
				switch(carta.valor){
					case 11: gotoxy(pos.x1+1,pos.y1+1);printf("%c",74);
						break;
					case 12: gotoxy(pos.x1+1,pos.y1+1);printf("%c",81);
						break;
					case 13: gotoxy(pos.x1+1,pos.y1+1);printf("%c",75);
				}
			}
			else{
				gotoxy(pos.x1+1,pos.y1+1);printf("%d",carta.valor);
			}
		textcolor(15);
	}
	else{
		for(int i=pos.y1+1;i<pos.y2;i++){
			for(int j=pos.x1+1;j<pos.x2;j++){
				gotoxy(j,i);printf("%c",42);
			}
		}
	}
}
void drawCard(tpCoordenadas pos, tpCarta carta){
	drawSquare(pos.x1,pos.y1,pos.x2,pos.y2);
	if(carta.status==1){
		switch(carta.naipe){
			case 1: textcolor(4); gotoxy(pos.x1+1,pos.y1+2);printf("%c",4);
				break;
			case 2: textcolor(15); gotoxy(pos.x1+1,pos.y1+2);printf("%c",6);
				break;
			case 3: textcolor(4); gotoxy(pos.x1+1,pos.y1+2);printf("%c",3);
				break;
			case 4: textcolor(15); gotoxy(pos.x1+1,pos.y1+2);printf("%c",5);
		}
		if(carta.valor==1){
			gotoxy(pos.x1+1,pos.y1+1);printf("%c",65);
		}
		else
			if(carta.valor>10){
				switch(carta.valor){
					case 11: gotoxy(pos.x1+1,pos.y1+1);printf("%c",74);
						break;
					case 12: gotoxy(pos.x1+1,pos.y1+1);printf("%c",81);
						break;
					case 13: gotoxy(pos.x1+1,pos.y1+1);printf("%c",75);	
				}
			}
			else{
				gotoxy(pos.x1+1,pos.y1+1);printf("%d",carta.valor);
			}
		textcolor(15);
	}
	else{
		for(int i=pos.y1+1;i<pos.y2;i++){
			for(int j=pos.x1+1;j<pos.x2;j++){
				gotoxy(j,i);printf("%c",42);
			}
		}
	}
}
void exibirCartas(tpBaralho monte, tpCoordenadas pos){
	if(pilhaVazia(monte))
		drawSquare(pos.x1,pos.y1,pos.x2,pos.y2);
	else{
		tpCarta cartaAux;
		if((pos.x1==2&&pos.y1==2&&pos.x2==13&&pos.y2==10)||
		(pos.x1==18&&pos.y1==2&&pos.x2==29&&pos.y2==10)||
		(pos.x1==50&&pos.y1==2&&pos.x2==61&&pos.y2==10)||
		(pos.x1==66&&pos.y1==2&&pos.x2==77&&pos.y2==10)||
		(pos.x1==82&&pos.y1==2&&pos.x2==93&&pos.y2==10)||
		(pos.x1==98&&pos.y1==2&&pos.x2==109&&pos.y2==10)){//verifica se é as posições para exibir apenas o elemento do topo
			drawCard(pos,elementoTopo(monte));
		}
		else{
			if(monte.topo==0){//apenas uma carta para exibir
				cartaAux = pop(monte);
				drawCard(pos,cartaAux);
			}
			else{
				tpBaralho monteAux;
				inicializar(monteAux);
				while(!pilhaVazia(monte))//colocar em outra pilha para a exibição ficar correta para o usuário
					push(monteAux,pop(monte));
				while(!pilhaVazia(monteAux)){
					cartaAux = pop(monteAux);
					if(monteAux.topo>-1){
						drawHCard(pos,cartaAux);
						pos.y1+=3;
					}
					else{
						pos.y2=pos.y1+8;
						drawCard(pos,cartaAux);
					}
				}
			}
		}
	}
}
void criarCoordenadas(tpCoordenadas pos[13]){
	int x1=2, y1=2, x2=13, y2=10;
	
	//baralho principal
	pos[0].x1=x1;pos[0].y1=y1;pos[0].x2=x2;pos[0].y2=y2;//armezenar a posição do baralho principal
	drawSquare(x1, y1, x2, y2);
	
	//pilhas principais
	//y1 e y2 permanecem os mesmos, porque estamos na mesma linha do baralho principal
	x1+=11+5; x2=x1+11;
	pos[1].x1=x1;pos[1].y1=y1;pos[1].x2=x2;pos[1].y2=y2;//armazenar a posição das "cartas disponíveis"
	x1+=11+5; x2=x1+11;
	
	for(int i=0;i<4;i++){//exibir e armazenar as posições das pilhas principais
		x1+=11+5; x2=x1+11; drawSquare(x1,y1,x2,y2);//i+2
		pos[i+2].x1=x1;pos[i+2].y1=y1;pos[i+2].x2=x2;pos[i+2].y2=y2;//armazenar a posição da iésima pilha principal
	}
	
	//pilhas do jogo
	//y1 e y2 serão mudados tbm, pois essas pilhas ficam em uma linha diferente das pilhas anteriores
	x1=2; x2=13;
	y1=y2+4; y2=y1+8; drawSquare(x1, y1, x2, y2);//1
	pos[6].x1=x1;pos[6].y1=y1;pos[6].x2=x2;pos[6].y2=y2;
	for(int i=0;i<6;i++){
		x1+=11+5; x2=x1+11; drawSquare(x1, y1, x2, y2);//i+7
		pos[i+7].x1=x1;pos[i+7].y1=y1;pos[i+7].x2=x2;pos[i+7].y2=y2;
	}
}

void criarBaralho(tpBaralho &baralho){
	inicializar(baralho);
	//armazenando cartas com o naipe de ouros/bebo
	for(int i=0,j=0;i<13;i++,j++){
		tpCarta cartaAux;
		cartaAux.naipe=1;
		cartaAux.valor=j+1;
		cartaAux.status=0;
		push(baralho,cartaAux);
	}
	for(int i=13,j=0;i<26;i++,j++){
		tpCarta cartaAux;
		cartaAux.naipe=2;
		cartaAux.valor=j+1;
		cartaAux.status=0;
		push(baralho,cartaAux);
	}
	for(int i=26,j=0;i<39;i++,j++){
		tpCarta cartaAux;
		cartaAux.naipe=3;
		cartaAux.valor=j+1;
		cartaAux.status=0;
		push(baralho,cartaAux);
	}
	for(int i=39,j=0;i<52;i++,j++){
		tpCarta cartaAux;
		cartaAux.naipe=4;
		cartaAux.valor=j+1;
		cartaAux.status=0;
		push(baralho,cartaAux);
	}
}

void embaralhar(tpBaralho &baralho){
	int tamanho = baralho.topo+1;
	srand(time(NULL)); //Inicializa o gerador de números aleatórios com uma semente única
    for (int i=tamanho-1; i>0; i--) {
        int j = rand() % (i+1);
        tpCarta temp = baralho.cartas[i];
        baralho.cartas[i] = baralho.cartas[j];
        baralho.cartas[j] = temp;
    }
}

void criarMontes(tpBaralho &baralho, tpBaralho montes[7]){
	for(int i=0;i<7;i++){
		for(int j=i;j<7;j++){
			tpCarta cartaAux;
			cartaAux = pop(baralho);
			if(i==j)
				cartaAux.status=1;
			else
				cartaAux.status=0;
			
			push(montes[j],cartaAux);
		}
	}
}

void inicializarMontesPrincipais(tpBaralho montesPrincipais[4]){
	for (int i=0; i < 4; i++)
		inicializar(montesPrincipais[i]);
}

//exibir antigo
void exibirMontes(tpBaralho montes[7]) {
    for (int i = 0; i < 7; i++) {
        printf("\nMONTE: %d\n", i + 1);
        if (!pilhaVazia(montes[i])) {
            tpCarta aux = elementoTopo(montes[i]);
            printf("ELEMENTO TOPO: %d-%d\n\n", aux.valor, aux.naipe);
        } else {
            printf("A pilha está vazia.\n\n");
        }
        exibirPilha(montes[i]);
        printf("\n-----------------------------\n");
    }
}
void exibirMontesPrincipais(tpBaralho montesPrincipais[4]) {
    for (int i = 0; i < 4; i++) {
        printf("\nMONTE PRINCIPAL: %d", i + 1);
        if (!pilhaVazia(montesPrincipais[i])) {
            tpCarta aux = elementoTopo(montesPrincipais[i]);
            printf("\nELEMENTO TOPO: %d-%d\n\n", aux.valor, aux.naipe);
        } else {
            printf("\nAinda nao ha elementos\n");
        }
        exibirPilha(montesPrincipais[i]);
        printf("\n-----------------------------\n");
    }
}

// FUNCOES DE IMPLEMENTAÇÃO
int jogoVencido(tpBaralho montesPrincipais[4]) {
	int i=0;
	tpCarta aux = elementoTopo(montesPrincipais[i]);
    while(i<4 && aux.valor==13){
    	i++;
    	aux = elementoTopo(montesPrincipais[i]);
    }
    if(i==4){//todos os topos tem REIS
    	return 1;
    }
    else{
    	return 0;
    }
}

int movimentoValido(tpCarta origem, tpCarta destino){
    if (origem.valor == destino.valor - 1) { // Verifica se o valor da carta de origem é um a menos que o valor da carta de destino
        if ((origem.naipe == 1 || origem.naipe == 3) && (destino.naipe == 2 || destino.naipe == 4)) // Verifica se os naipes são de cores opostas
            return 1;
        if ((origem.naipe == 2 || origem.naipe == 4) && (destino.naipe == 1 || destino.naipe == 3))
            return 1;
    }
    return 0;
}

int podeMoverParaPilhaFinal(tpCarta carta, tpBaralho pilhaFinal) {
    if (pilhaVazia(pilhaFinal)) {
        if (carta.valor == 1) // Apenas o Ás pode ser movido para uma pilha final vazia
            return 1;
    } else {
        tpCarta topo = elementoTopo(pilhaFinal);
        if (carta.naipe == topo.naipe && carta.valor == topo.valor + 1) // Verifica se a carta é do mesmo naipe e tem valor um a mais que o topo da pilha final
            return 1;
    }
    return 0;
}
// MOVER CARTA
void moverCarta(tpBaralho &origem, tpBaralho &destino) {
    // Verificar se a pilha de origem não está vazia
    if (!pilhaVazia(origem)) {
        tpCarta cartaOrigem = pop(origem); // Remover carta da pilha de origem
        push(destino, cartaOrigem); // Adicionar carta à pilha de destino
    }
}

// Função para mover uma sequência de cartas de uma pilha para outra
void moverSequencia(tpBaralho &aux, tpBaralho &destino) {
    while(!pilhaVazia(aux))
        push(destino, pop(aux));
}
int movimentoValidoSequencia(tpBaralho monteOrigem, tpBaralho monteDestino, int qtde){
	tpBaralho aux;
	inicializar(aux);
	tpCarta origem, destino;
	if (monteOrigem.topo - qtde >= -1){
		for(int i=0;i<qtde;i++){
			tpCarta cartaTeste=pop(monteOrigem);
			push(aux,cartaTeste);
		}
		if(!pilhaVazia(monteDestino)){
			origem = elementoTopo(aux);
			destino = elementoTopo(monteDestino);
			if(movimentoValido(origem,destino)){
				return 1;
			}
		}
		else{
			origem = elementoTopo(aux);
			if(origem.valor==13){
				return 1;
			}
		}
	}
	else
		return 0;
}
int movimentoValidoSequenciaVazia(tpBaralho monteOrigem, int qtde){
	tpBaralho aux;
	inicializar(aux);
	tpCarta origem;
	if (monteOrigem.topo - qtde >= -1){
		for(int i=0;i<qtde;i++){
			tpCarta cartaTeste=pop(monteOrigem);
			push(aux,cartaTeste);
		}
		origem = elementoTopo(aux);
		if(origem.valor==13){
			return 1;
		}
	}
	else
		return 0;
}
char Menu(void)
{
	char op;
	gotoxy(120,34);printf("#########################################################################################################");
	gotoxy(120,35);printf("%%                                             ____                                                      %%");
	gotoxy(120,36);printf("%%   ______                _________    __    |____|_     __       __     _________    __                %%");
	gotoxy(120,37);printf("%%  |      |      |       |  _______|  |  |  |   ____|   |  |     |  |   |  _______|  |  |       |       %%");
	gotoxy(120,38);printf("%%  |  ##  |     | |     |  |          |  |  |  |        |   |    |  |  |  |          |  |      | |      %%");
	gotoxy(120,39);printf("%%  |   ___|    |   |    |  |          |  |  |  |__      |    |   |  |  |  |          |  |     |   |     %%");
	gotoxy(120,40);printf("%%  |  |       | |_| |   |  |          |  |  |   __|     |     |  |  |  |  |          |  |    | |_| |    %%");
	gotoxy(120,41);printf("%%  |  |      | |___| |  |  |          |  |  |  |        |  ||  | |  |  |  |          |  |   | |___| |   %%");
	gotoxy(120,42);printf("%%  |  |      | |   | |  |  |_______   |  |  |  |_____   |  | |  ||  |  |  |_______   |  |   | |   | |   %%");
	gotoxy(120,43);printf("%%  |__|     |_|     |_|  |_________|  |__|  |________|  |__|  |_____|   |_________|  |__|  |_|     |_|  %%");
	gotoxy(120,44);printf("%%                                                                                                       %%");
	gotoxy(120,45);printf("#########################################################################################################");
	gotoxy(120,1);printf ("############# Bem Vindo ao Jogo da PACIENCIA #############\n");
	gotoxy(120,2);printf ("[A] - MOVER CARTAS (PILHAS)\n");
	gotoxy(120,3);printf ("[B] - MOVER CARTAS (MONTES PRINCIPAIS)\n");
	gotoxy(120,4);printf ("[C] - PROXIMA CARTA\n");
	gotoxy(120,5);printf ("[D] - MOVER CARTA (BARALHO)\n");
	gotoxy(120,6);printf ("[E] - MOVER MONTES (PILHAS)\n");
	gotoxy(120,7);printf ("[F] - MOVER CARTAS (PRINCIPAL - MONTES)\n");
	gotoxy(120,8);printf ("[ESC] - SAIR\n");
	gotoxy(120,9);op = toupper(getch());
	return op;
}
void executar(void)
{
	tpCoordenadas pos[13];
	criarCoordenadas(pos);
	getch();
	tpBaralho baralho;
	tpBaralho montes[7], montesPrincipais[4];
	tpBaralho monteDisp;
	inicializar(monteDisp);
	int origem, destino, qtde;
	char op;
		
	criarBaralho(baralho);
	embaralhar(baralho);
	for(int i=0;i<7;i++)
	{
		inicializar(montes[i]);
	}
	criarMontes(baralho, montes);
	inicializarMontesPrincipais(montesPrincipais);
	
	while(!jogoVencido(montesPrincipais) && op != 27)
	{
		//exibição das cartas
		system("cls");
		exibirCartas(baralho,pos[0]);
		exibirCartas(monteDisp,pos[1]);
		for(int i=0;i<4;i++)
			exibirCartas(montesPrincipais[i],pos[i+2]);
		for(int i=0;i<7;i++)
			exibirCartas(montes[i],pos[i+6]);
		gotoxy(120,9);op = Menu();
		switch(op)
		{
			case 'B': //mover para montes principais
				gotoxy(120,9);printf ("Digite a PILHA ORIGEM:");
				gotoxy(120,10);scanf ("%d", &origem);
				if (origem >= 1 && origem <=7)
				{
					origem--;
					if(!pilhaVazia(montes[origem])){
						gotoxy(120,11);printf ("Digite a PILHA DESTINO (Montes principais):");
						gotoxy(120,12);scanf ("%d", &destino);
						if (destino >=1 && destino <= 4)
						{
							destino--;
							tpCarta cartaOrigem, cartaDestino;
							cartaOrigem = elementoTopo(montes[origem]);
							if (podeMoverParaPilhaFinal(cartaOrigem, montesPrincipais[destino]))
							{
								gotoxy(120,13);printf("*Carta Movida*");
								moverCarta(montes[origem],montesPrincipais[destino]);
								if(!pilhaVazia(montes[origem])){
									tpCarta aux=pop(montes[origem]);
									aux.status=1;
									push(montes[origem],aux);
								}
							}
							else{
								gotoxy(120,13);printf ("#Movimento Invalido!!");
							}
						}
						else{
							gotoxy(120,13);printf ("#Monte Principal Incorreto!!");
						}
					}
					else{
						gotoxy(120,11);printf("#Monte Vazio!!");
					}
				}
				else{
					gotoxy(120,11);printf ("#Monte Incorreto!!");
				}
				break;
			case 'A': // MOVER CARTA ENTRES AS PILHAS
				gotoxy(120,9);printf ("Digite a PILHA ORIGEM:");
				gotoxy(120,10);scanf ("%d", &origem);
				if (origem >= 1 && origem <=7) // MONTE EXISTE
				{
					origem--;
					if(!pilhaVazia(montes[origem])){
						gotoxy(120,11);printf ("Digite a PILHA DESTINO:");
						gotoxy(120,12);scanf ("%d", &destino);
						if (destino >=1 && destino <= 7) // MONTE PRINCIPAL EXISTE
						{
							destino--;
							if(!pilhaVazia(montes[destino])){
								if(destino!=origem){
									tpCarta cartaOrigem, cartaDestino;
									cartaOrigem = elementoTopo(montes[origem]);
									cartaDestino = elementoTopo(montes[destino]);
									if (movimentoValido(cartaOrigem, cartaDestino))
									{
										gotoxy(120,13);printf("*Carta Movida*");
										moverCarta(montes[origem],montes[destino]);
										if(!pilhaVazia(montes[origem])){
											tpCarta aux=pop(montes[origem]);
											aux.status=1;
											push(montes[origem],aux);
										}
									}
									else{
										gotoxy(120,13);printf ("#Movimento Invalido!!");
									}
								}
								else{
									gotoxy(120,13);printf("#Mesmo monte escolhido!!");
								}
							}
							else{
								tpCarta cartaAux = elementoTopo(montes[origem]);
								if(cartaAux.valor==13){
									moverCarta(montes[origem],montes[destino]);
									if(!pilhaVazia(montes[origem])){
										tpCarta aux=pop(montes[origem]);
										aux.status=1;
										push(montes[origem],aux);
									}
								}
								else{
									gotoxy(120,13);printf("#Movimento invalido!!");
								}
							}
						}
						else{
							gotoxy(120,13);printf ("#Monte Principal Incorreto!!");
						}
					}
					else{
						gotoxy(120,11);printf("#Monte Vazio!!");
					}
				}
				else{
					gotoxy(120,11);printf ("#Monte Incorreto!!");
				}
				break;
			case 'C': //VIRAR CARTA
				if(!pilhaVazia(baralho)){
						tpCarta carta=pop(baralho);
						carta.status=1;
						push(monteDisp,carta);
					}
				else{
						while(!pilhaVazia(monteDisp))
						{
							tpCarta cartaVoltar=pop(monteDisp);
							cartaVoltar.status=0;
							push(baralho,cartaVoltar);
						}
					}
				break;
				
			case 'D': //Mover do monte disponível
				if(!pilhaVazia(monteDisp))
				{
					char opc;
					gotoxy(120,9);printf("[A] Montes principais");
					gotoxy(120,10);printf("[B] Montes");
					gotoxy(120,11);printf("[ESC] Voltar");
					gotoxy(120,12);opc = toupper(getch());
					switch(opc)
					{
						case 'A': //Mover para monte final
							gotoxy(120,13);printf ("Digite a PILHA DESTINO (Montes Principais):\n");
							gotoxy(120,14);scanf ("%d", &destino);
							if (destino >=1 && destino <= 4) // MONTE PRINCIPAL EXISTE
							{
								destino--;
								tpCarta cartaOrigem, cartaDestino;
								cartaOrigem = elementoTopo(monteDisp);
								if (podeMoverParaPilhaFinal(cartaOrigem, montesPrincipais[destino]))
								{
									gotoxy(120,15);printf("*Carta Movida*");
									moverCarta(monteDisp,montesPrincipais[destino]);
								}
								else{
									gotoxy(120,15);printf ("#Movimento Invalido!!");
								}
							}
							else{
								gotoxy(120,15);printf ("#Monte Principal Incorreto!!");
							}
							break;
						
						case 'B': //Mover para montes secundários
							gotoxy(120,13);printf ("Digite a PILHA DESTINO:\n");
							gotoxy(120,14);scanf ("%d", &destino);
							if (destino >=1 && destino <= 7) // MONTE PRINCIPAL EXISTE
							{
								destino--;
								if(!pilhaVazia(montes[destino])){
									tpCarta cartaOrigem, cartaDestino;
									cartaOrigem = elementoTopo(monteDisp);
									cartaDestino = elementoTopo(montes[destino]);
									if (movimentoValido(cartaOrigem, cartaDestino))
									{
										gotoxy(120,15);printf("*Carta Movida*");
										moverCarta(monteDisp,montes[destino]);
									}
									else{
										gotoxy(120,15);printf ("#Movimento Invalido!!");
									}
								}
								else{
									tpCarta cartaAux = elementoTopo(monteDisp);
									if(cartaAux.valor==13)
										moverCarta(monteDisp,montes[destino]);
									else{
										gotoxy(120,15);printf("#Movimento INVALIDO!!");
									}
								}
							}
							else{
								gotoxy(120,15);printf ("#Monte Principal Incorreto!!");
							}
							break;
							
						default: gotoxy(120,13);printf("#Valor fora de range!!");
					}
					
				}
				else{
					gotoxy(120,10);printf("#Pilha Vazia!!");
				}
				break;
				
			case 'E':
				gotoxy(120,9);printf ("Digite a PILHA ORIGEM:\n");
				gotoxy(120,10);scanf ("%d", &origem);
				if (origem >= 1 && origem <= 7)
				{
					origem--;
					if (!pilhaVazia(montes[origem]))
					{
						gotoxy(120,11);printf ("Digite a PILHA DESTINO:\n");
						gotoxy(120,12);scanf ("%d", &destino);
						if (destino >= 1 && destino <= 7)
						{
							destino--;
							if (!pilhaVazia(montes[destino]))
							{
								if (origem != destino)
								{
									gotoxy(120,13);printf ("Digite a Quantidade de Cartas da SEQUENCIA:\n");
									gotoxy(120,14);scanf ("%d", &qtde);
									if (movimentoValidoSequencia(montes[origem],montes[destino], qtde))
									{
										gotoxy(120,15);printf("*Monte movido*");
										tpBaralho aux;
										tpCarta cartaAuxiliar;
										inicializar(aux);
										for(int i=0;i<qtde;i++)
											push(aux,pop(montes[origem]));
										moverSequencia(aux,montes[destino]);
										if(!pilhaVazia(montes[origem])){
											cartaAuxiliar = pop(montes[origem]);
											cartaAuxiliar.status = 1;
											push(montes[origem],cartaAuxiliar);
										}
									}
									else{
										gotoxy(120,15);printf ("#Movimento Invalido!!");
									}
								}
								else{
									gotoxy(120,10);printf ("#Mesmo Monte!!");
								}
							}
							else{
								gotoxy(120,13);printf ("Digite a Quantidade de Cartas da SEQUENCIA:\n");
								gotoxy(120,14);scanf ("%d", &qtde);
								if (movimentoValidoSequenciaVazia(montes[origem], qtde)==1)
								{
									gotoxy(120,15);printf("*Monte Movido*");
									gotoxy(120,16);printf("entrei no vazio");
									gotoxy(120,17);getch();
									tpBaralho aux;
									tpCarta cartaAuxiliar;
									inicializar(aux);
									for(int i=0;i<qtde;i++)
										push(aux,pop(montes[origem]));
									moverSequencia(aux,montes[destino]);
									if(!pilhaVazia(montes[origem])){
										cartaAuxiliar = pop(montes[origem]);
										cartaAuxiliar.status = 1;
										push(montes[origem],cartaAuxiliar);
									}
								}
								else{
									gotoxy(120,15);printf ("#Movimento Invalido!!");
								}
							}
						}
						else{
							gotoxy(120,13);printf ("#Movimento Invalido!!");
						}
					}
					else{
						gotoxy(120,11);printf ("#Pilha Vazia!!");
					}
				}
				else{
					gotoxy(120,11);printf ("#Pilha fora de range!!");
				}
				break;
				
			case 'F':
				gotoxy(120,9);printf ("Digite a PILHA ORIGEM (Montes Principais):");
				gotoxy(120,10);scanf ("%d", &origem);
				if (origem >= 1 && origem <=4) // MONTE EXISTE
				{
					origem--;
					if(!pilhaVazia(montesPrincipais[origem])){
						gotoxy(120,11);printf ("Digite a PILHA DESTINO (Montes):");
						gotoxy(120,12);scanf ("%d", &destino);
						if (destino >=1 && destino <= 7) // MONTE PRINCIPAL EXISTE
						{
							destino--;
							if(!pilhaVazia(montes[destino]))
							{
								tpCarta cartaOrigem, cartaDestino;
								cartaDestino = elementoTopo(montes[destino]);
								cartaOrigem = elementoTopo(montesPrincipais[origem]);
								if (movimentoValido(cartaOrigem, cartaDestino))
								{
									gotoxy(120,13); printf("*Carta Movida*");
									moverCarta(montesPrincipais[origem],montes[destino]);
								}
								else{
									gotoxy(120,13); printf("#Movimento Invalido!!");
								}
							}
							else{
								gotoxy(120,13); printf("#Monte Vazio!!");
							}
						}
						else{
							gotoxy(120,13); printf("#Monte Incorreto!!");
						}
					}
					else{
						gotoxy(120,11); printf("#Monte Principal Vazio!!");
					}
				}
				else{
					gotoxy(120,11); printf("#Monte Principal Incorreto!!");
				}
		}
	}
	
}
int main(void)
{
	executar();
	getch();
}
