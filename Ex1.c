
// Questão 1

int main (){

	int x, maior = 0; 
	scanf("%d", &x);
	while (x != 0) {
		if (x > maior) maior = x;
		scanf ("%d", &x);
    }
    printf("%d\n", maior);
    return 0;
}



// Questão 2

int main (){

	int x, soma = 0,media = 0, i = 0;
	scanf ("%d", &x);
	while (x != 0){
		soma = soma + x;
		i++;
		scanf ("%d", &x);
	}
	media = soma / i;
	printf("%d\n", media);
	return 0;
}



// Questão 3

int main (){

	int x, maior = 0, maior2 = 0;
	scanf ("%d", &x);
	while (x != 0){
		if (x >= maior) maior2 = maior; maior = x; 
		if (x < maior && x > maior2) maior2 = x;
		scanf ("%d", &x);
	}
	printf("%d\n", maior2);
	return 0;
}



// Questão 4

int bitsUm (int n){

	int i = 0; 
	while (n > 1){
		if (n%2 == 1) { i++; n = n/2; }
		else n = n/2;
	}
	if (n == 1) i++;
	return i;
}



// Questão 5

int trailingZ (int n){

	int i = 0;
	while (n%2 == 0){
		i ++;
		n = n/2;
	} 
	return i;
}



// Questão 6

int qDig (int n){

	if (n == 0) return 0;
	else {

		int i = 0;
		while (n > 0){
			i++;
			n = n/10;
		}
		return i;
	}
}



// Questão 7 - ERRO

char *mystrcat (char s1 [], char s2[]){

	int i = 0, j;

	while (s1[i] != '\0'){
		i++;
	}
	for (j = 0; s2[j] != '\0'; j++){
		s1[i] = s2[j];
		i++;
	}
	return s1;
}



// Questão 8

char *mystrcpy (char *dest, char source[]){

	int i = 0;
	while (source[i] != '\0'){
		dest[i] = source [i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}



// Questão 9

int mystrcmp (char s1[], char s2[]){

	int i = 0,r;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0') r = 0;
	if (s1[i] == '\0' && s2[i] != '\0') r = -1;
    if (s1[i] != '\0' && s2[i] == '\0') r = 1;
	if (s1[i] > s2[i]) r = 1;
	if (s1[i] < s2[i]) r = -1;
	return r;	
}



// Questão 10

char *mystrstr (char s1[], char s2 []){

	int i;

	if (*s1 == '\0' || *s2 == '\0') return s1;
	
	while (*s1){

		for (i = 0; s1[i] == s2[i] || s2[i] == '\0'; i++){

			if (s2[i] == '\0') return s1;
		}

		s1++;
	}
	return NULL;
}



// Questão 11

void strrev (char s[]){

	int n = 0;

	while (s[n] != '\0') n++;
	
	char aux[n];
	n--;
	int i;

	for (i = 0; s[i] != '\0'; i++){

		aux[n] = s[i];
		n--;
	}

	i = 0;
	for (i = 0; s[i] != '\0'; i++){

		s[i] = aux[i];
	}
}



// Questão 12

void strnoV (char s[]){

	int n = 0;

	while (s[n] != '\0') n++;

	char aux[n];
	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'){

			aux[j] = s[i];
			j++;
		}
	}

	aux[j] = '\0';

	for (i = 0; aux[i] != '\0'; i++){

		s[i] = aux[i];
	}

	s[i] = '\0';
}



// Questão 13 - ERRO

void truncW (char t[], int n){

	int x = 0, i, j = 0, p = 0, k = 0;
	while (t[x] != '\0'){
		x++;
	}
	x = x - 1;

	char aux[x];
	
	for (i = 0; t[i] != '\0'; i++){

		if (t[i] != ' '){

			if (p < n){

				aux[j] = t[i];
				j++;
				p++;
			}
			
			else { 
				
				aux[j] = ' ';
				
				if (k == 0) {
					
					j++;
					k++;
				}
			}

		}
		else { 
			
			p = 0;
			k = 0;
		}
			
		
	}	
}



// A partir daqui não vi se está certo


// Questão 14

char charMaisfreq (char s[]){

	int n = 0,i,j,p,k,r;

	while (s[n] != '\0'){
		n++;
	}
	n = n - 1;

	int aux[n];



	for (i = 0; s[i] != '\0'; i++){

		for (j = 0; s[j] != '\0'; j++){

			if (s[i] == s[j]) p++;
		}

			aux[i] = p;
			p = 0;	
	}

	for (k = 0; k < n; k++){

		p = 0;
		if (aux[k] >= p){

			p = aux[k];
			r = k;
		}
	}

	return s[r];	
}



// Questão 15

int iguaisConsecutivos (char s[]){

	int n = 0, i, p = 1, k, r = 0;

	while (s[n] != '\0'){
		n++;
	}
	n = n - 1;

	int aux[n];

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] == s[i+1]){

			p++;
			aux[i] = p;
		}
		else { 
			aux[i] = p;
			p = 1;
		}
	}

	for (k = 0; aux[k] < n; k++){

		if (aux[k] >= r) r = aux[k]; 
	}

	return r;
}



// Questão 16

int difConsecutivos (char s[]){

	int n = 0, i, p = 1, k, r = 0;

	while (s[n] != '\0'){
		n++;
	}
	n = n + 1;

	int aux[n];

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] != s[i+1]){

			p++;
			aux[i] = p;
		}
		else {
			p = 1;
			aux[i] = p;
		}
	}

	for (k = 0; aux[k] < n; k++){

		if (aux[k] >= r) r = aux[k];
	}

	return r;
}



// Questão 17

int maiorPrefixo (char s1 [], char s2 []){

	int i = 0, p = 0;

	while (s1[i] == s2[i]){
		p++;
		i++;
	}

	return p;
}



// Questão 18

int maiorSufixo (char s1 [], char s2 []){

	int a = 0, b = 0, i,p = 0;

	while (s1[a] != '\0'){
		a++;
	}
	a = a - 1;

	while (s2[b] != '\0'){
		b++;
	}
	b = b - 1;

	char aux1[a];
	char aux2[b];

	for (i = 0; s1[i] != '\0'; i++){

		aux1[a] = s1[i];
		a = a - 1;
	}

	i = 0;

	for (i = 0; s2[i] != '\0'; i++){

		aux2[b] = s2[i];
		b = b - 1;
	}

	i = 0;

	while (aux1[i] == aux2 [i]){

		p++;
		i++;
	}

	return p;
}



// Questão 19

int sufPref (char s1[], char s2[]){

	int i, j = 0, k = 0, p = 0, r;

	for (i = 0; s1[i] != '\0'; i++){

		if (s1[i] == s2[j] && s1[i+1] != '\0'){

			k = i;

			while (s1[k] == s2[j]){

				p++;
				k++;
				j++;
			}

			p = p - 1;
			k = 0;
			j = 0;

			if (s1[i+p] == '\0') r = p;
			
		}
	}
	return r;
}



// Questão 20

int contaPal (char s[]){

	int i, r = 0;

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] != ' ' && s[i+1] == ' ') r++;

		if (s[i] != ' ' && s[i+1] == '\0') r++;
	}

	return r;
}



// Questão 21

int contaVogais (char s[]){

	int i, r = 0;

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') r++;
	}

	return r;
}



// Questão 22

int contida (char a[], char b[]){

	int i, j, n = 0, p = 0, r = 0;

	while (a[n] != '\0'){
		n++;
	}

	for (i = 0; a[i] != '\0'; i++){

		for (j = 0; b[j] != '\0'; j++){

			if (a[i] == b[j] && p == 0) p++;
		}

		r = r + p;
		p = 0;
	}

	char v[100] = "Verdadeiro";
	char f[100] = "Falso";

	if (r == n) printf("%s\n",v);
	else printf("%s\n", f);
	
	return 0;
}



// Questão 23

int palindorome (char s[]){

	int n = 0, i, r = 1;

	while (s[n] != '\0'){
		n++;
	}

	for (i = 0; s[i] != '\0'; i++){

		if (s[i] == s[n-1]) n = n - 1;
		else r = 0;
		
	}

	char v[100] = "Verdadeiro";
	char f[100] = "Falso";

	if (r == 1) printf("%s\n", v);
	else printf("%s\n", f);

	return 0;
}



// Questão 24

int remRep (char x[]){

	int n = 0, i, j = 0;

	while (x[n] != '\0'){
		n++;
	}

	char aux[n];

	for (i = 0; x[i] != '\0'; i++){

		if (x[i] != x[i+1]){

			aux[j] = x[i];
			j++;
		}

		aux[j] = '\0';
	}

	n = 0;

	while (aux[n] != '\0'){
		n++;
	}

	printf("%s\n", aux);
	printf("%d\n", n);

	return 0;
}



// Questão 25

int limpaEspacos (char t[]){

	int n = 0, i, j = 0, r;

	while (t[n] != '\0'){
		n++;
	}

	char aux[n];

	for (i = 0; t[i] != '\0'; i++){

		if (t[i] == ' ' && t[i+1] == ' ') r = 0;    // r = 0 -> "não faz nada"

		else {

			aux[j] = t[i];
			j++;
		}
	}

	aux[j] = '\0';

	n = 0;

	while (aux[n] != '\0'){
		n++;
	}

	printf("%s\n", aux);
	printf("%d\n", n);

	return 0;
}



// Questão 26

void insere (int v[], int n, int x){

	int a = 0, b, i = 0, j = 0, k = 0;

	while (v[a] != 0){
		a++;
	}
	
	b = a + 1;

	int aux[b];

	if (v[n-1] < x){

		while (j < n){

			aux[j] = v[j];
			j++;
		}

		aux[n] = x;

		j = n + 1;

		while (v[n] != 0){

			aux[j] = v[n];
			j++;
			n++;
		}
	}

	else {

		while (v[i] < x){
			i++;
		}

		while (k < i){

			aux[k] = v[k];
			k++;
		}

		aux[i] = x;
		i++;

		while (v[n] != 0){

			aux[i] = v[n];
			i++;
			n++;
		}
	}	
}



// Questão 27

void merge (int r [], int a[], int b[], int na, int nb){

	int n, i = 0, j = 0, k = 0;

	n = na + nb;

	while (i < na){

		if (a[i] < b[j]){ 

			r[k] = a[i]; 
			i++;
			k++;
		}
		else {

			r[k] = b[j];
			k++;
			j++;
		}
	}
	
	while (j < nb){
		
		r[k] = b[j];
		k++;
		j++;
	}

	k = 0;

	while (k < n){

		printf("%d\n", r[k]);
		k++;
	}
}



// Questão 28

int crescente (int a[], int i, int j){

	int k, p = 0, r;

	for (k = i; k < j; k++){

		if (a[k] <= a[k+1]) p++;
	}

	if (a[j] > a[j-1]) p++;

	r = j - i;
	r++;

	if (r == p) return 1;
	else return 0;
}



// Questão 29

int retiraNeg (int v[], int n){

	int i, p = 0, k = 0, r;

	for (i = 0; i < n; i++){

		if (v[i] < 0) p++;
	}

	p = n - p;

	int aux[p];

	i = 0;

	while (i < n){

		if (v[i] >= 0){

			aux[k] = v[i];
			k++;
		}

		i++;
	}

	k = 0;

	while (k < p){

		printf("%d\n", aux[k]);
		k++;
	}

	r = n - p;

	return r;
}



// Questão 30

int menosFreq (int v[], int n){

	int i, j, p = 0, r, s;

	int aux[n];

	for (i = 0; i < n; i++){

		for (j = 0; j < n; j++){

			if (v[i] == v[j]) p++;		
		}

		aux[i] = p;

		p = 0;
	}

	i = 0;
	p = 0;

	r = aux[i];
	p = i;

	while (i < n){

		if (aux[i] < r){

			r = aux[i];
			p = i;
		}

		i++;
	}

	s = v[p];

	return s;
}



// Questão 31

int maisFreq (int v[], int n){

	int i, j, p = 0, r, s;

	int aux[n];

	for (i = 0; i < n; i++){

		for (j = 0; j < n; j++){

			if (v[i] == v[j]) p++;
		}

		aux[i] = p;

		p = 0;
	}

	i = 0;
	p = 0;

	r = aux[i];
	p = i;

	while (i < n){

		if (aux[i] > r){ 

			r = aux[i];
			p = i;
		}

		i++;
	}

	s = v[p];

	return s;
}



// Questão 32

int maxCresc (int v[], int n){

	int i, p = 1, j = 0, r;

	int aux[n];

	for (i = 0; i < n; i++){

		if (v[i] <= v[i+1]) p++;
		
		else {

			aux[j] = p;
			j++;
			p = 1;
		}
	}

	aux[j] = 0;

	i = 0;

	r = aux[i];

	while (aux[i] > 0){

		if (aux[i] > r) r = aux[i];

		i++;
	}


	return r;
}



// Questão 33

int elimRep (int v[], int n){

	int i, j, k = 0, p = 0, r = 0;

	int aux[n];

	aux[k] = v[k];
	k++;
	r++;

	for (i = 1; i < n; i++){

		for (j = 0; j < i; j++){

			if (v[i] == v[j]) p++;
		}

		if (p == 0){

			aux[k] = v[i];
			k++;
			r++;
		}
		p = 0;
	}

	i = 0;

	while (i < r){

		printf("%d\n", aux[i]);
		i++;
	}

	return 0;
}



// Questão 34

int elimRepOrd (int v[], int n){

	int i, k = 0, r = 0;

	int aux[n];

	aux[k] = v[k];
	k++;
	r++;

	for (i = 1; i < n; i++){

		if (v[i] != v[i-1]){

			aux[k] = v[i];
			k++;
			r++;
		}
	}

	i = 0;

	while (i < r){

		printf("%d\n", aux[i]);
		i++;
	}

	return 0;
}



// Questão 35

int comunsOrd (int a[], int na, int b[], int nb){

	int i, j, p = 0, r = 0;

	for (i = 0; i < na; i++){

		for (j = 0; j < nb; j++){

			if (a[i] == b[j] && a[i] != a[i-1]) p++;
		}

		if (p != 0) r++;
		p = 0;
	}

	return r;
}



// Questão 36

int comuns (int a[], int na, int b[], int nb){

	int i, j, p = 0, r = 0;

	for (i = 0; i < na; i++){

		for (j = 0; j < nb; j++){

			if (a[i] == b[j] && a[i] != a[i-1]) p++;
		}

		if (p != 0) r++;
		p = 0;
	}

	return r;
}



// A partir daqui está tudo certo

// Questão 37

int minInd (int v[], int n){

	int i, r, p;

	r = v[0];
	p = 0;

	for (i = 1; i < n; i++){

		if (v[i] < r){

			r = v[i];
			p = i;
		}
	}

	return p;
}



// Questão 38

void somasAc (int v[], int ac[], int n){

	int i, j, r = 0;

	for (i = 0; i < n; i++){

		for (j = 0; j <= i; j++){

			r = r + v[j];
		}

		ac[i] = r;
		r = 0;
	}
}



// Questão 39

int triSup (int n, float m[n][n]){

	int i, j, p = 0;

	for (i = 1; i < n; i++){

		for (j = 0; j < i; j++){

			if (m[i][j] != 0) p++;
		}
	}

	if (p == 0) return 1;
	else return 0;
}



// Questão 40

void transposta (int n, float m[n][n]){

	int i, j, r, s;

	float aux[n][n];

	for (i = 0; i < n; i++){

		for (j = 0; j < n; j++){

			aux[i][j] = m[j][i];
		}
	}

	for (r = 0; r < n; r++){

		for (s = 0; s < n; s++){

			m[r][s] = aux[r][s];
		}
	}
}



// Questão 41

void addTo (int n, int m, int a[n][m], int b[n][m]){

	int i, j;

	for (i = 0; i < n; i++){

		for (j = 0; j < m; j++){

			a[i][j] = a[i][j] + b[i][j];
		}
	}
}



// Questão 42

int unionSet (int n, int v1[n], int v2[n], int r[n]){

	int i;

	for (i = 0; i < n; i++){

		if (v1[i] == 0 && v2[i] == 0) r[i] = 0;

		if (v1[i] == 0 && v2[i] == 1) r[i] = 1;

		if (v1[i] == 1 && v2[i] == 0) r[i] = 1;

		if (v1[i] == 1 && v2[i] == 1) r[i] = 1;
	}

	return 0;
}



// Questão 43

int intersectSet (int n, int v1[n], int v2[n], int r[n]){

	int i;

	for (i = 0; i < n; i++){

		if (v1[i] == 0 && v2[i] == 0) r[i] = 0;

		if (v1[i] == 0 && v2[i] == 1) r[i] = 0;

		if (v1[i] == 1 && v2[i] == 0) r[i] = 0;

		if (v1[i] == 1 && v2[i] == 1) r[i] = 1;
	}

	return 0;
}



// Questão 44

int intersectMSet (int n, int v1[n], int v2[n], int r[n]){

	int i;

	for (i = 0; i < n; i++){

		if (v1[i] == 0 || v2[i] == 0) r[i] = 0;

		else {

			if (v1[i] <= v2[i]) r[i] = v1[i];

			else r[i] = v2[i];
		}
	}

	return 0;
}



// Questão 45

int unionMSet (int n, int v1[n], int v2[n], int r[n]){

	int i;

	for (i = 0; i < n; i++){

		r[i] = v1[i] + v2[i]
	}

	return 0;
}



// Questão 46

int cardinalMSet (int n, int v[n]){

	int i, r = 0;

	for (i = 0; i < n; i++){

		r = r + v[i];
	}

	return r;
}



// Questão 47

Posicao posFinal (Posicao inicial, Movimento mov[], int n){

	int i;

	for (i = 0; i < n; i++){

		if (mov[i] == Norte) inicial.y++;

		if (mov[i] == Oeste) inicial.x--;

		if (mov[i] == Sul) inicial.y--;

		if (mov[i] == Este) inicial.x++;
	}

	return inicial;
}



// Questão 48

int caminho (Posicao inicial, Posicao final, Movimento mov[], int n){

	int i = 0, p = 0;

	if (inicial.x < final.x){

		while (inicial.x < final.x){ 

			mov[i] = Este;
			p++;
			i++;
			inicial.x++;
		}
	}

	else {

		while (inicial.x > final.x){ 

			mov[i] = Oeste;
			p++;
			i++;
			inicial.x--;
		}
	}

	if (inicial.y < final.y){

		while (inicial.y < final.y){ 

			mov[i] = Norte;
			p++;
			i++;
			inicial.y++;
		}
	}

	else {

		while (inicial.y > final.y){ 

			mov[i] = Sul;
			p++;
			i++;
			inicial.y--;
		}
	}

	if (p <= n) return p;
	else return -1;
}



// Questão 49

int norma (Posicao a){

	int b;

	if (a.x >= 0 && a.y < 0) b = a.x - a.y;

	if (a.x < 0 && a.y >= 0) b = a.y - a.x;

	if (a.x < 0 && a.y < 0) b = -a.x - a.y;

	if (a.x >= 0 && a.y >= 0) b = a.x + a.y;

	return b;
}



int maiscentral (Posicao pos[], int n){

	int i, p, r;

	int aux[n];

	for (i = 0; i < n; i++){

		aux[i] = norma (pos[i]);
	}

	i = 0;
	p = aux[i];
	r = i;

	while (i < n){

		if (aux[i] < p){

			p = aux[i];
			r = i;
			i++;
		}

		else i++;
	}

	return r;
}



// Questão 50

int vizinhos (Posicao p, Posicao pos[], int n){

	int i, r = 0;

	for (i = 0; i < n; i++){

		if (pos[i].x == p.x && pos[i].y == p.y - 1) r++;
		if (pos[i].x == p.x && pos[i].y == p.y + 1) r++;
		if (pos[i].x == p.x - 1 && pos[i].y == p.y) r++;
		if (pos[i].x == p.x + 1 && pos[i].y == p.y) r++;
	}

	return r;
}


