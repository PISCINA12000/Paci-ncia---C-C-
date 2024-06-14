#define MAXBARALHO 52

struct tpCarta{
	int naipe, valor, status;
};

struct tpBaralho{
	int topo;
	tpCarta cartas[MAXBARALHO];
};

void inicializar(tpBaralho &baralho){
	baralho.topo = -1;
}

tpCarta elementoTopo(tpBaralho baralho){
	return baralho.cartas[baralho.topo];
}

tpCarta pop(tpBaralho &baralho){
	return baralho.cartas[baralho.topo--];
}

void push(tpBaralho &baralho, tpCarta carta){
	baralho.cartas[++baralho.topo] = carta;
}

int pilhaVazia(tpBaralho baralho){
	return baralho.topo==-1;
}

int pilhaCheia(tpBaralho baralho){
	return baralho.topo==MAXBARALHO-1;
}

void exibirPilha(tpBaralho baralho){
	while(!pilhaVazia(baralho)){
		tpCarta cartaAux;
		cartaAux = pop(baralho);
		printf("Carta: %d\tNaipe: %d\n",cartaAux.valor,cartaAux.naipe);
	}
}

void exibirDisp(tpBaralho baralho){
	while(!pilhaVazia(baralho)){
		tpCarta cartaAux;
		cartaAux = pop(baralho);
		if(cartaAux.status==1){
			printf("Carta: %d\tNaipe: %d\n",cartaAux.valor,cartaAux.naipe);
		}
	}
}
