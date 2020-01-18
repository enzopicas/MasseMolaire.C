#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Path of the file with all datas of atoms
#define ATOMSFILE "/home/enzo/Documents/massemolaire/update/Atoms.txt"

struct sAtomes {
		char nom[10];
		char symbole[3];
		float masse;
	};

int main(int argc, char **argv)
{
	//Variables
	FILE* doc = NULL;
	struct sAtomes atome[24];
	char buffer[10]="";
	char molecule[20]="";
	int nombre, nombre_bis, compteur;
	float masse_mol;
	
	//Lecture des données des atomes
	doc = fopen(ATOMSFILE, "r");
	if (doc != NULL)
	{
		for (int i=0 ; !feof(doc) ; i++)
		{
			fscanf(doc, "%s", buffer);
			sprintf(atome[i].nom, buffer);
			fscanf(doc, "%s", buffer);
			sprintf(atome[i].symbole, buffer);
			fscanf(doc, "%f", &atome[i].masse);
		}
		
		fclose(doc);
		
	} else {
		printf("PB fichier\n");
	}
	
	//Entree de la molecule
    printf("\nEntrer la formule de votre molecule : ");
    scanf("%s",molecule);
	
	//Identification et calcul
	for(int i=0 ; i<24 ; i++)
	{
        compteur=0;
		
        //Cas pour les atomes à deux caractères
        if(strlen(atome[i].symbole)==2) 
		{
            for(int k=0 ; k<strlen(molecule) ; k++)
			{
                if((molecule[k]==atome[i].symbole[0])&&(molecule[k+1]==atome[i].symbole[1]))
				{
                    if((molecule[k+2]>='A')&&(molecule[k+2]<='Z'))
					{
						compteur++;
                    } else {
                        nombre=molecule[k+2]-48; /* -48 pour codes ASCII */
                        if(nombre>0)
						{
                            if((molecule[k+3]>='0')&&(molecule[k+3]<='9'))
							{
                                nombre_bis=molecule[k+3]-48;
								nombre*=10;
								compteur+=nombre+nombre_bis;
                            } else {
								compteur+=nombre;
                            }
                        } else { /* Pour le dernier caractere */
							compteur++;
                        }
                    }
                }
            }
        }

        //Cas pour les atomes à un caractère
        else if(strlen(atome[i].symbole)==1)
		{
            for(int k=0 ; k<strlen(molecule) ; k++)
			{
                if(molecule[k]==atome[i].symbole[0])
				{
                    if((molecule[k+1]>='A')&&(molecule[k+1]<='Z'))
					{
						compteur++;
                    } else if((molecule[k+1]>='a')&&(molecule[k+1]<='z')) {
						break;
                    } else {
                        nombre=molecule[k+1]-48; /* -48 pour codes ASCII */
                        if(nombre>0)
						{
                            if((molecule[k+2]>='0')&&(molecule[k+2]<='9'))
							{
                                nombre_bis=molecule[k+2]-48;
                                nombre=nombre*10;
								compteur+=nombre+nombre_bis;
                            } else {
								compteur+=nombre;
                            }
                        } else { /* Pour le dernier caractere */
							compteur++;
                        }
                    }
                }
            }
        }
		
		masse_mol+=compteur*atome[i].masse;
        if(compteur>0)
            printf("\nLa molecule contient %d fois : %s",compteur,atome[i].nom);

    }

    //Affichage final
    printf("\n\nLa masse molaire de %s vaut %.3f g par mol.\n",molecule,masse_mol);
	
	//FOR WINDOWS ONLY
	/*printf("Appuyez sur une touche pour continuer.\n");
	getchar();*/
	return EXIT_SUCCESS;
}