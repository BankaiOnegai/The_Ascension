#include "header.h"


//Fonction qui permet de trouver le sommet accessible avec le plus petit poids 
int DistanceMini(int dist[], bool sptSet[]) 
{ 
    // Initialise la valeur minimale 
    int min = INT_MAX, minSommet; 
  
    for (int v = 0; v < size; v++) 
	{
        if (sptSet[v] == false && dist[v] <= min) 
		{
            min = dist[v];
			minSommet = v; 
		}
	}
    return minSommet; 
} 
  
// Fonction pour afficher les distances les plus courtes  
int Solution(int dist[], int n) 
{ 
    printf("\t\tLe plus court chemin de Timothee jusqu'a Tanji\n"); 
    for (int i = 0; i < size; i++) 
        printf("\t\t\t S%d -> %d\n", i, dist[i]); 
		keypressed("'z' pour continuer",'z');
} 


// Fonction utile pour trouver l'ensemble d'un élement i (il utilise la technique de compression du chemin)
int Trouve(struct subset subsets[], int n)
{
	if (subsets[n].parent != n)
	{
		subsets[n].parent = Trouve(subsets, subsets[n].parent);
	}
	return subsets[n].parent;
}

// Fonction qui fait l'union de deux ensembles x et y par exemple (utilise l'union par rang)
void lien(struct subset subsets[], int x, int y)
{
	int racine1 = Trouve(subsets, x);
	int racine2 = Trouve(subsets, y);

	if (subsets[racine1].rang < subsets[racine2].rang)
	{
		subsets[racine1].parent = racine2;
	}
	else if (subsets[racine1].rang > subsets[racine2].rang)
	{
		subsets[racine2].parent = racine1;
	}
	else
	{
		subsets[racine2].parent = racine1;
		subsets[racine1].rang++;
	}
}

// Compare 2 arcs par rapport à leurs poids
// utilisé dans qsort() pour le tri et la matrice des arcs
int Compare(const void* a, const void* b)
{
 	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return (a1->poids) > (b1->poids);
}

  
// Fonction qui implémente l’algorithme du chemin le plus court  de Dijkstra
// pour un graphe représenté à l’aide la matrice d'adjacence
void dijkstra(int graph[size][size], int src) 
{ 
    int dist[size]; //tableau qui contient la plus petite distance du début du graphe jusqu'a 'i'
  
    bool verif[size]; 
    // plus courte distance entre source et i trouvée
	
	//On initialise toutes les distance a l'infini et on met verif a faux  
    // initialise toute les distance à l'infini et stpSet[] à faux 
    for (int i = 0; i < size; i++) 
    {  
		dist[i] = INT_MAX,
		verif[i] = false; 
	}
  
    // Distance de la source est tjrs a 0 
    dist[src] = 0; 
	PlusPetitSommet(dist,verif,graph);
    Solution(dist, size); 
} 


void PlusPetitSommet(int dist[size],bool verif[size],int graph[size][size]){

	// trouve le chemin le plus courts vers les sommets
		for (int i = 0; i < size - 1; i++) { 
			// prends la plus petite distance des sommets qui sont encore non marqué
			
			int u = DistanceMini(dist, verif); 
	
			// marque le sommet  
			verif[u] = true; 
	
			// met a jour la valeur de la distance des sommets adjacents
			for (int j = 0; j < size; j++){
	
				
				if (!verif[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]){
					dist[j] = dist[u] + graph[u][j]; 
				}
			}
		} 	
}	

	
// Fonction qui reprend le principe de l'algorithme de Krusal, le but est d'avoir l'arbre couvrant de poids minimum.

void Kruskal(struct Graph* graph)
{
	int nbV = graph->nbV;
	struct Edge result[nbV]; 
	int taille = 0;
	int comptPoid = 0;

	qsort(graph->edge, graph->nbE, sizeof(graph->edge[0]), Compare);

	struct subset *subsets = (struct subset*) malloc( nbV * sizeof(struct subset) );

	
	initialisationKruskal(subsets, nbV);

	printf("\t\tL'arbre couvrant de poids minimum\n");
	taille = Marquage(graph, subsets, nbV, result, taille);
	for (int i = 0; i < taille; i++)
	{
		printf("\t\t\tS%d <--> S%d == %d poids\n", result[i].debut , result[i].arrive , result[i].poids);
		comptPoid = comptPoid + result[i].poids;
	}
	printf("L'arc de poids minimal fait : %d de poids \n\n", comptPoid);
	keypressed("Appuie sur 'z' ",'z');
	return;
}


void initialisationKruskal(struct subset *subsets, int nbV)
{
	for (int v = 0; v < nbV; v++)
	{
		subsets[v].parent = v;
		subsets[v].rang = 0;
	}
}

int Marquage(struct Graph* graph, struct subset *subsets, int nbV, struct Edge result[nbV], int taille)
{
	int i = 0;
	int x,y;
	while (taille < nbV - 1 && i < graph->nbE)
	{

		struct Edge prochain = graph->edge[i++];

		x = Trouve(subsets, prochain.debut);
		y = Trouve(subsets, prochain.arrive);

		if (x != y)
		{
			result[taille++] = prochain;
			lien(subsets, x, y);
		}
	}
	return taille;
}