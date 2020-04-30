// Questão 1

int length (LInt l){

	int t = 0;
	while (l != NULL){ t++; l = l->prox; }
	return t;
}



// Questão 2

void freeL (LInt l){

	free(l);
}



// Questão 3

void imprimeL (LInt l){

	while (l != NULL){
		printf("%d\n", l->valor);
		l = l->prox;
	}
}



// Questão 4

LInt reverseL (LInt l){

	LInt aux, ant = NULL;

	while (l != NULL){
		aux = l;
		l = l->prox;
		aux->prox = ant;
		ant = aux;
	}
	return aux;
}



// Questão 5

void insertOrd (LInt *l, int x){

	LInt aux = malloc (sizeof(struct lligada));
	aux->valor = x;
	
	while (*l != NULL && x > (*l)->valor) l = &((*l)->prox);

	aux->prox = *l;
	*l = aux;
}



// Questão 6

int removeOneOrd (LInt *l, int x){

	if (*l == NULL) return 1;
	else {

		while (*l != NULL && x >= (*l)->valor){

			if ((*l)->valor == x){ *l = (*l)->prox; return 0; }

			l = &((*l)->prox);
		}
		return 1;
	}
}


				
// Questão 7

void merge (LInt *r, LInt a, LInt b){

	*r = malloc (sizeof(struct lligada));

	while (a != NULL && b!= NULL){

		if (a->valor < b->valor){

			(*r)->valor = a->valor;
			(*r)->prox = malloc (sizeof(struct lligada));
			r = &((*r)->prox);
			a = a->prox;
		}
		else {

			(*r)->valor = b->valor;
			(*r)->prox = malloc (sizeof(struct lligada));
			r = &((*r)->prox);
			b = b->prox;
		}
	}
	if (a == NULL) *r = b;
	else *r = a;
}



// Questão 8

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){

	while (l != NULL){
	
		if (l->valor < x){

			(*mx) = malloc (sizeof(struct lligada));
			(*mx)->valor = l->valor;
			mx = &((*mx)->prox);
		}
		else {

			(*Mx) = malloc (sizeof(struct lligada));
			(*Mx)->valor = l->valor;
			Mx = &((*Mx)->prox);
		}

		l = l->prox;
	}
	*mx = NULL;
	*Mx = NULL;
}



// Questão 9

int length (LInt l){

	int t = 0;
	while (l != NULL){ t++; l = l->prox; }
	return t;
}


LInt parteAmeio (LInt *l){

	if ((*l)->prox == NULL) return NULL;

	int i = length (*l) / 2;

	LInt pt = *l;
	LInt *aux = l;
	
	for (i; i > 0; i--) aux = &((*aux)->prox);

	LInt temp = *aux;
	*aux = NULL;
	*l = temp;
	return pt;
}



// Questão 10

int removeAll (LInt *l, int x){

	if (*l == NULL) return 0;
	else {

		int r = 0;

		while (*l != NULL){

			if ((*l)->valor == x){ *l = (*l)->prox; r++; }
			else l = &((*l)->prox);
		}

		return r;
	}
}



// Questão 11

int removeDups (LInt *l){

	if (*l == NULL) return 0;
	else {

		int r = 0;
		
		int x = (*l)->valor;
		LInt *aux = l;

		aux = &((*aux)->prox);

		while (*aux != NULL){

			if ((*aux)->valor == x){ *aux = (*aux)->prox; r++; }
			else aux = &((*aux)->prox);
		}

		r = r + removeDups (&((*l)->prox));

		return r;
	}
}



// Questão 12

int maximo (LInt l){

	int max = l->valor;

	while (l != NULL){

		if (l->valor > max) max = l->valor;
		l = l->prox;
	}

	return max;
}


int removeMaiorL (LInt *l){

	if (*l == NULL) return 0;

	int maior = maximo (*l);

	while ((*l)->valor != maior){

		l = &((*l)->prox);
	}

	*l = (*l)->prox;
		
	return maior;	
}



// Questão 13

void init (LInt *l){

	if (*l != NULL){

		while ((*l)->prox != NULL){

			l = &((*l)->prox);
		}

		*l = NULL;
	}
}



// Questão 14

void appendL (LInt *l, int x){

	LInt aux = malloc (sizeof(struct lligada));
	aux->valor = x;
	aux->prox = NULL;

	while (*l != NULL) l = &((*l)->prox);

	*l = aux;
}
		


// Questão 15

void concatL (LInt *a, LInt b){

	while (*a != NULL) a = &((*a)->prox);
	
	*a = b;
}



// Questão 16

LInt cloneL (LInt l){

	if (l == NULL) return NULL;
	else {

		LInt clone;
		clone = malloc(sizeof(struct lligada));
		clone->valor = l->valor;
		clone->prox = cloneL (l->prox);
	}
}



// Questão 17

LInt cloneRev (LInt l){

	if (l == NULL) return NULL;
	else {

		LInt clone, aux;
		aux = NULL;

		while (l != NULL){

			clone = malloc(sizeof(struct lligada));
			clone->valor = l->valor;
			clone->prox = aux;
			aux = clone;
			l = l->prox;
		}

		return aux;
	}
}



// Questão 18

int maximo (LInt l){

	int max = l->valor;

	while (l != NULL){

		if (l->valor > max) max = l->valor;
		l = l->prox;
	}

	return max;
}



// Questão 19

int length (LInt l){

	int t = 0;
	while (l != NULL){ t++; l = l->prox; }
	return t;
}


int take (int n, LInt *l){

	int t = length (*l);
	int r = n;

	if (t <= n) return t;
	else {

		while (n > 0){ l = &((*l)->prox); n--; }

		*l = NULL;
	}
	
	return r;
}



// Questão 20

int length (LInt l){

	int t = 0;
	while (l != NULL){ t++; l = l->prox; }
	return t;
}

int drop (int n, LInt *l){

	int t = length (*l);
	int i = 0;

	if (n >= t){ *l = NULL; return t; }
	else {

		while (i < n){

			*l = (*l)->prox;
			i++;
		}
		return n;
	}
}



// Questão 21

LInt Nforward (LInt l, int N){

	if (N == 0) return l;
	else Nforward (l->prox, N-1);
}



// Questão 22

int listToArray (LInt l, int v[], int N){

	if (l == NULL || N == 0) return 0;
	else {

		int r = 0, i = 0;

		while (l != NULL && i < N){

			v[i] = l->valor;
			i++;
			l = l->prox;
			r++;
		}

		return r;
	}
}



// Questão 23		

LInt arrayToList (int v[], int N){

	if (N == 0) return NULL;
	else {

		LInt l = malloc(sizeof(struct lligada));
		l->valor = *v;
		l->prox = arrayToList (v+1, N-1);
	
		return l;
	}
}



// Questão 24

int length (LInt l){

	int t = 0;
	while (l != NULL){ t++; l = l->prox; }
	return t;
}


LInt arrayToList (int v[], int N){

	if (N == 0) return NULL;
	else {

		LInt l = malloc(sizeof(struct lligada));
		l->valor = *v;
		l->prox = arrayToList (v+1, N-1);
	
		return l;
	}
}


LInt somasAcL (LInt l){

	if (l == NULL) return NULL;
 	else {

 		LInt aux = malloc(sizeof(struct lligada));
 		int soma = 0;
 		int t = length (l);
 		int v[t];
 		int i = 0;

 		while (l != NULL){

 			soma = soma + l->valor;
 			v[i] = soma;
 			l = l->prox;
 			i++;
 		}

 		return (arrayToList (v, t));
 	}
}



// Questão 25

void remreps (LInt l){

	if (l != NULL){

		LInt ant = NULL;

		while (l != NULL){

			if (ant != NULL){

				if (ant->valor == l->valor){ l = l->prox; ant->prox = l; }
				else { ant = l; l = l->prox; }
			}
			else { ant = l; l = l->prox; }
		}
	}
}



// Questão 26

LInt rotateL (LInt l){

	if (l == NULL || l->prox == NULL) return l;
	else {

		int r = l->valor;
		LInt aux = l->prox;

		while (l->prox != NULL){

			l = l->prox;
		}

		l->prox = malloc(sizeof(struct lligada));
		l = l->prox;
		l->valor = r;
		l->prox = NULL;

		return aux;
	}
}



// Questão 27 -- ERRO

LInt parte (LInt l){

	if (l == NULL || l->prox == NULL) return NULL;
	else {

		LInt x = malloc(sizeof(struct lligada));
		LInt aux = x;
		LInt ant = NULL;
		int i = 1;

		while (l != NULL){

			if (i % 2 != 0){

				if (ant == NULL){ ant = l; l = l->prox; }
				else { ant->prox = l; ant = l; l = l->prox; }
			}
			else { 

				x->valor = l->valor;
				x->prox = malloc(sizeof(struct lligada));
				x = x->prox;
				l = l->prox;
				ant->prox = l;
			}
			i++;
		}
		
		x = NULL;
		return aux;
	}
}
	


// Questão 28

int altura (ABin a){

	if (a == NULL) return -1;
	else {

		int e = altura (a->esq) + 1;
		int d = altura (a->dir) + 1;

		if (e > d) return e;
		else return d;
	}
} 



// Questão 29

ABin cloneAB (ABin a){

	if (a == NULL) return NULL;
	else {

		ABin clone = malloc(sizeof(struct nodo));
		clone->valor = a->valor;
		clone->esq = cloneAB (a->esq);
		clone->dir = cloneAB (a->dir);
		return clone;
	}
}				



// Questão 30

void mirror (ABin *a){

	if (*a != NULL){

		ABin temp = (*a)->esq;

		(*a)->esq = (*a)->dir;
		(*a)->dir = temp;

		mirror (&((*a)->esq));
		mirror (&((*a)->dir));
	}
}



// Questão 31 - ERRO

void inorder (ABin a, LInt *l){

	if (a == NULL) *l = NULL;
	else {

		inorder (a->esq, l);

		while (*l != NULL) l = &((*l)->prox);

		*l = malloc(sizeof(struct lligada));
		(*l)->valor = a->valor;
		l = &((*l)->valor);
		inorder (a->dir, l);
	}
}



// Questão 32

void preorder (ABin a, LInt *l){

	if (a == NULL) *l = NULL;
	else {

		*l = malloc(sizeof(struct lligada));
		(*l)->valor = a->valor;
		l = &((*l)->prox);
		preorder (a->esq, l);

		LInt *aux = l;
		while (*aux != NULL){ aux = &((*aux)->prox); }
		preorder (a->dir, aux);
	}
}



// Questão 33 - ERRO primeira

void posorder (ABin a, LInt *l){

	if (a == NULL) *l = NULL;
	else {

		posorder (a->esq, l);
		while (*l != NULL) l = &((*l)->prox);

		posorder (a->dir, l);
		while (*l != NULL) l = &((*l)->prox);

		*l = malloc(sizeof(struct lligada));
		(*l)->valor = a->valor;
		(*l)->prox = NULL;
	}
}  



// Questão 34

int depth (ABin a, int x){

	if (a == NULL) return -1;
	else {

		if (a->valor == x) return 1;
		else {

			int e = depth (a->esq, x);
			int d = depth (a->dir, x);

			if (e == -1){

				if (d == -1) return -1;
				else return d+1;
			}
			else {

				if (d == -1) return e+1;
				else {

					if (e < d) return e+1;
					else return d+1;
				}
			}
		}
	}
}



// Questão 35

int freeAB (ABin a){

	if (a == NULL) return 0;
	else {

		if (a->esq == NULL && a->dir == NULL){ a = NULL; return 1; }
		else {

			return freeAB (a->esq) + freeAB (a->dir) + 1;
		}
	}
}



// Questão 36

int pruneAB (ABin *a, int l){

	if (*a == NULL) return 0;
	else {

		if (l == 0){

			int r = freeAB(*a);
			*a = NULL;
			return r;
		}
		else {

			int e, d;

			if (l == 1){

				e = freeAB ((*a)->esq);
				d = freeAB ((*a)->dir);
				(*a)->esq = NULL;
				(*a)->dir = NULL;
				return e + d;
			}
			else {

				l--;
				return pruneAB (&((*a)->esq), l) + pruneAB(&((*a)->dir), l);
			}
		}
	}
}



// Questão 37

int iguaisAB (ABin a, ABin b){

	if (a == NULL && b == NULL) return 1;
	else if (a == NULL && b != NULL || a != NULL && b == NULL) return 0;
	else {

		if (a->valor != b->valor) return 0;
		else {

			int e = iguaisAB (a->esq, b->esq);
			int d = iguaisAB (a->dir, b->dir);

			if (e == 1 && d == 1) return 1;
			else return 0;
		}
	}
}



// Questão 38

LInt nivelL (ABin a, int n){

	if (a == NULL) return NULL;
	else {


		LInt l;
		LInt aux = l;

		if (n == 1){

			l = malloc(sizeof(struct lligada));
			l->valor = a->valor;
			l->prox = NULL;
			return l;
		}
		else {

			LInt le = nivelL (a->esq, n-1);
			LInt ld = nivelL (a->dir, n-1);
			LInt *aux = &le;
			
			while (*aux != NULL) aux = &((*aux)->prox);
			*aux = ld;
			return le;
		}
	}
} 



// Questão 39

int nivelV (ABin a, int n, int v[]){

	if (a == NULL) return 0;
	else {

		if (n == 1){

			*v = a->valor;
			return 1;
		}
		else {

			int e = nivelV (a->esq, n-1, v);
			int d = nivelV (a->dir, n-1, v+e);
			return e + d;
		}
	}
}



// Questão 40

int dumpAbin (ABin a, int v[], int N){

	int i = 0;

	if (a == NULL || N < 1) return 0;
	else {

		i = i + dumpAbin (a->esq, v, N);

		if (i < N) v[i++] = a->valor;

		i = i + dumpAbin (a->dir, v+i, N-i);

		return i;
	}
	
}



// Questão 41

int soma (ABin a){

	if (a == NULL) return 0;
	else { 

		int r = a->valor;
		r = r + soma (a->esq) + soma (a->dir);
		return r;
	}
}


ABin somasAcA (ABin a){

	if (a == NULL) return NULL;
	else {

		ABin r = malloc(sizeof(struct nodo));
		r->valor = soma (a);
		r->esq = somasAcA (a->esq);
		r->dir = somasAcA (a->dir);
		return r;
	}
}



// Questão 42

int contaFolhas (ABin a){

	if (a == NULL) return 0;
	else {

		int r = 0;

		if (a->esq == NULL && a->dir == NULL) r++;
		r = r + contaFolhas (a->esq) + contaFolhas (a->dir);
		return r;
	}
}



// Questão 43

ABin cloneMirror (ABin a){

	if (a == NULL) return NULL;
	else {

		ABin r = malloc(sizeof(struct nodo));
		r->valor = a->valor;
		r->esq = cloneMirror (a->dir);
		r->dir = cloneMirror (a->esq);
		return r;
	}
}



// Questão 44

int addOrd (ABin *a, int x){

	while (*a != NULL){

		if (x < (*a)->valor) a = &((*a)->esq);
		else {

			if (x > (*a)->valor) a = &((*a)->dir);
			else return 1;
		}
	}

	*a = malloc(sizeof(struct nodo));
	(*a)->valor = x;
	(*a)->esq = NULL;
	(*a)->dir = NULL;
	return 0;
}



// Questão 45

int lookupAB (ABin a, int x){

	while (a != NULL){

		if (a->valor == x) return 1;
		else {

			if (x < a->valor) a = a->esq;
			else a = a->dir;
		}
	}
	return 0;
}



// Questão 47

int maiorAB (ABin a){

	while (a->dir != NULL) a = a->dir;

	return a->valor;
}



// Questão 48

void removeMaiorA (ABin *a){

	if (*a != NULL){

		if ((*a)->dir == NULL) *a = (*a)->esq;
		else removeMaiorA (&((*a)->dir));
	}
}	



// Questão 49

int quantosMaiores (ABin a, int x){

	if (a == NULL) return 0;
	else {

		int r = 0;

		if (a->valor > x) r++;

		r = r + quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);

		return r;
	}
}



// Questão 50

void listToBTree (LInt l, ABin *a){

	if (l == NULL) *a == NULL;
	else {

		*a = malloc(sizeof(struct nodo));
		(*a)->valor = l->valor;
		(*a)->esq = NULL;

		listToBTree (l->prox, &((*a)->dir));
	}
}



// Questão 51

int todosMenores (ABin a, int x){

	if (a == NULL) return 1;
	else {

		int r = x > a->valor && todosMenores (a->esq, x) && todosMenores (a->dir, x);

		return r;
	}
}


int todosMaiores (ABin a, int x){

	if (a == NULL) return 1;
	else {

		int r = x < a->valor && todosMaiores (a->esq, x) && todosMaiores (a->dir, x);

		return r;
	}
}


int deProcura (ABin a){

	if (a == NULL) return 1;
	else {

		int r = todosMenores (a->esq, a->valor) && todosMaiores (a->dir, a->valor) && deProcura (a->esq) && deProcura (a->dir);

		return r;
	}
}

		
