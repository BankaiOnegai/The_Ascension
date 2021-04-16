#include "header.h"

void clear()
{
    system("clear");
}

/*Fonction qui permet de lire des fichiers textes ayant pour nom un nombre */
void lecture_texte_int(char chemin[],int number)
{
    FILE *fichier = NULL;
    char chaine[1000] = "";
    int SIZE = 20;
    char  path[SIZE];
   

         if (sprintf(path, "./%s/%d.txt",chemin,number) == 0)
                printf("Erreur du sprintf\n"); // en cas d'erreur on arrête
        // ici on a écrit comme le ferais printf dans un terminal, mais dans la chaine path  
    fichier = fopen(path, "r+");

    if (fichier != NULL)
    {
        while (fgets(chaine, 1000, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire 
        }
        fclose(fichier);
    }
    else
    {
      printf("Erreur d'ouverture du fichier\n");
    } 
}

/*Fonction qui permet de lire des fichiers textes ayant pour nom un mot */
void lecture_texte_string(char chemin[],char sentence [])
{

    FILE *fichier = NULL;
    char chaine[1000] = "";
    int SIZE = 20;
    char  path[SIZE];

    if (sprintf(path, "./%s/%s.txt",chemin,sentence) == 0)
     printf("Erreur du sprintf\n"); // en cas d'erreur on arrête
        // ici on a écrit comme le ferais printf dans un terminal, mais dans la chaine path 
    
    fichier = fopen(path, "r+");

    //printf("test\n");
    //system("clear");

    if (fichier != NULL)
    {
        while (fgets(chaine, 1000, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
        fclose(fichier);
    }
    else
    {
      printf("Erreur d'ouverture du fichier string \n");
    }
    printf("\n\n");
}


/*Fonction qui attend un certain temps avant que l'utilisateur puisse clicker*/
void click(int count,int n)
{
    	/*for (int i = 0; i < count; ++i)
    	{
        sleep(2);
        if(n == 1)
        {
           clear();
        }
	*/
	clear();        
	lecture_texte_string("animation","click");
    //}
    keypressed("",'y');
}

/* Foction keypressed qui sert a ne pas fermer la fonction tant qu'une touche entrée en parametre n'est pas tapper sur le terminale*/
void keypressed(char sentence[],char key)
{
	printf("%s \n", sentence);
	// saisie d'une confirmation 
	char c;

		//le ou avec la valeur 0x20 permet
	   //de forcer la casse en minuscule 
	do
		c = getchar() | 0x20;
	while (c != key);

	// vidange du flux 
	//while(getchar() != '\n');

	clear();
}
//Crée une matrice et la remplie a partir d'un graphe
struct Graph *remplissage(int graphe[size][size])
{
    int S;
    struct Graph* graph;
    S = nbArc(graphe);
    //printf("%d\n",S);
    graph = createGraph(S, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(graphe[i][j]!= 0)
            {
                graph->edge[i].debut = i;
               // printf("%d",graph->edge[i].debut);
                graph->edge[i].arrive = j;
               // printf("%d",graph->edge[i].arrive);
                graph->edge[i].poids = graphe[i][j];
               // printf("%d",graph->edge[i].poids);
            }
        }   
    }  
    return graph;
}

//Determine le nombre d'arcs dans un graphe a partir d'une matrice
int nbArc(int graphe[size][size])
{
    int somme = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           if(graphe[i][j] != 0)
           {
               somme ++;
           }
           else;
        }
    }
    return (somme/2);
}

// pour creer un graphe avec nbV sommets et E arretes
struct Graph* createGraph(int nbV, int nbE)
{
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->nbV = nbV;
	graph->nbE = nbE;
	graph->edge = (struct Edge*) malloc( graph->nbE * sizeof( struct Edge ) );

	return graph;
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
