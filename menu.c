#include "header.h"

//---------------------------------------------------------------------------------------------//
/*Simple fonction qui gere l'animation au lancement du jeu 
	Elle fait appel a la fonction Menu */
void ecranLancement()
{	
	click(1,1);
        viderBuffer();
        //keypressed("Appuyer sur y",'y');
        //viderBuffer();

	menu();
}

// Procédure qui va nous permettre d'afficher le menu à l'utilisateur et ainsi pouvoir appliquer l'algorithme qu'il aura choisi.
void menu()
{
    int choix, continuer = 1;
    clear();
    //lecture_texte_string("menu","ecran");
    while(continuer)
    {
	lecture_texte_string("menu","ecran");        
	lecture_texte_string("menu","menu");
        scanf("%d",&choix);
        viderBuffer();
        switch(choix)
        {
            case 1: 
                clear();
                jouer();
                break;

            case 2: 
                clear();
                credit();
                break;

            case 3: 
                clear();
                Rules();
                break;

            case 0: 
                    continuer = 0;
                    clear();
                    return;
            default :
                printf("Veuillez faire un choix valide");
                break;
        }
        clear();
        viderBuffer();
    }
    clear();
}

//---------------------------------------------------------------------------------------------//
/*De meme que la fonction Rules , la fonction credit ouvre un fichier texte avec les credits*/
void credit()
{
	char sentence[] = "credit";
	char chemin[] = "menu";
	lecture_texte_string(chemin,sentence);
	keypressed("Retour au menu /y",'y');
}

//---------------------------------------------------------------------------------------------//
/*La fonction Rules ouvre un fichier texte qui contient les regles du jeu*/
void Rules()
{
	char sentence[] = "rules";
	char chemin[] = "menu";
	lecture_texte_string(chemin,sentence);
	keypressed("Retour au menu /y",'y');
}

void jouer()
{
     struct Graph *graph1, *graph2;

    //printf("TEST1\n");
    	int graphe1[size][size]=
        {	    
            {0,3,2,6,0,0},
            {3,0,6,0,1,0},
            {2,6,0,5,3,0},
            {6,0,5,0,0,4},
            {0,1,3,0,0,8},
            {0,0,0,4,8,0}
            };

        int graphe2[size][size]=
        { 	      
            {0,7,6,6,0,0},
            {7,0,0,0,0,10},
            {6,0,0,0,0,10},
            {6,0,0,0,0,10},
            {0,0,0,6,0,6},
            {0,10,10,0,6,0}
            };

    //printf("TEST2\n");
        //graph1 = remplissage(graphe1);
        graph1 = remplissage(graphe1);


    //printf("TEST3\n");
    keypressed("Appuyer sur 'z' pour commencer l'aventure",'z');
        for (int i = 1; i <= size; i++)
        {
            lecture_texte_int("scenario",i);
            if(i<size)
            {
                keypressed(" \t\t\t Appuyez sur 'z' pour continuer ",'z');
                if(i == 3)
                {
                    lecture_texte_string("graphe","KRUSKGRAPH");
                    Astuce(1);
                    Kruskal(graph1);
                    
                }
                else if(i == 5)
                {
                    lecture_texte_string("graphe","DIJGRAPH");    
                    Astuce(2);            
                    dijkstra(graphe2,0);
                }
            }
        }
    keypressed("\n\n \t\t\t\t Appuyez sur 'z' pour retourner au menu ",'z');
    free(graph1);
    free(graph2);
	
}

void affichageMat(int graphe[size][size])
{
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%d ",graphe[i][j]);
            }
            printf("\n");
        }
}

void Astuce(int a)
{
    int n;

    printf("\nSouhaites tu une astuce ?\n\t1/Oui\t2/Non\n");
    scanf("%d",&n);

    if (n == 1 )
    {
        if(a == 1)
        {
            lecture_texte_string("graphe","KruAstuce");
        }
        else if(a == 2)
        {
            lecture_texte_string("graphe","DijAstuce");
        }
    }
    else;

    keypressed("Appuies sur 'z' pour connaitre la solution",'z');
}