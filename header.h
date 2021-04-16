#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define TAILLE_MAX 1000
#define size 6

typedef enum { false, true } bool;
// structure pour representer une arrete et son poids
struct Edge
{
	int debut;
    int arrive;
    int poids;
};

// structure pour representer un graphe connexe non orienté et ponderé 

struct Graph
{
	int nbV, nbE;
	struct Edge* edge;
};

//  structure pour representer un sous ensemble des descendants
struct subset
{
	int parent;
	int rang;
};


//---------------PROTOTYPES--------------//

int DistanceMini(int dist[], bool sptSet[]);
int Solution(int dist[], int n);
int Trouve(struct subset subsets[], int n);
void lien(struct subset subsets[], int x, int y);
int Compare(const void* a, const void* b);
void PlusPetitSommet(int dist[size],bool verif[size],int graph[size][size]);

void dijkstra(int graph[size][size], int src);
void Kruskal(struct Graph* graph);
void initialisationKruskal(struct subset *subsets, int nbV);
int Marquage(struct Graph* graph, struct subset *subsets, int nbV, struct Edge result[nbV], int taille);


void clear();
void viderBuffer();
void lecture_texte_int(char chemin[],int number);
void lecture_texte_string(char chemin[],char sentence []);
void click(int count,int n);
void keypressed(char sentence[],char key);

struct Graph *remplissage(int graphe[size][size]);
int nbArc(int graphe[size][size]);
struct Graph* createGraph(int nbV, int nbE);


void ecranLancement();
void menu();
void credit();
void Rules();
void jouer();
void affichageMat(int graphe[size][size]);
void Astuce(int a);

#endif