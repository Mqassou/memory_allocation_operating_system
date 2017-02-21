//
//  main.c
//  Projet_ProgSys
//
//  Created by Maximilien Petit and Mohamed Qassou on 22/12/2015.
//  Copyright © 2015 M&M. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define nbMem 5

void showMemory(int _nbMem,int* _tabMem);
int* allocateMemory(int* _tabProc);
int* allocateProcesses(int* _nbFileSize);
int* firstFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc);
int* bestFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc);
int* worstFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc);
int* releaseArea(int* _tabMem, int* tabFrag,int _nbMem, int* listProc, int* sizeListProc);
int* groupSmallArea(int* _tabMem,int* _nbMem,int* tabFrag);
int* copy(int* _tabMem,int* _nbMem);
int* keepCopy(int* _tabMem,int* _nbMem,int* tabFrag);




int main(int argc, const char * argv[]) {
system("cls");
    /*
     int i , taille1 = 2 , taille2 = 3;
int **ptr;

ptr = malloc(taille1 * sizeof(*ptr));       //On alloue 'taille1' pointeurs.
if(ptr == NULL)
      //Ne pas oublier de notifier l'erreur et de quitter le programme.

for(i=0 ; i < taille1 ; i++){
     ptr[i] = malloc(taille2 * sizeof(**ptr) );       //On alloue des tableaux de 'taille2' variables.
     if(ptr[i] == NULL){                              //En cas d'erreur d'allocation
         //Il faut libérer la mémoire déjà allouée
         //Ne pas oublier de notifier l'erreur et de quitter le programme.
     }
}

//notre tableau ptr[2][3] est maintenant utilisable...

     */
    
    int* tabMem;
	int* tabFrag; // Tableau qui retient la taille des blocks mémoires que saisira l'utilisateur,
				  // pour ensuite être utilisé pour la défragmentation, c'est une copie du tableau initial qui n'est jamais modifié
    int* tabFiles;
	
	int sizeListProc=1;// retenir la taille du tableau qui contient  l'ensemble des process
	int* listProc=calloc(1,sizeof(int)); //retenir l'ensemble des process
	
    int i;
    int nbMemFinal=nbMem;
    int nbFileSize;
    tabMem = calloc(nbMem,sizeof(int));
    
    
     printf("\n \n === Veuillez definir la taille des 5 blocks memoires === \n\n");
  
    
    
    tabMem = allocateMemory(tabMem);
	tabFrag=copy(tabMem,&nbMemFinal);
    system("cls");
	printf(" \n\n la taille des 5 blocks memoires ont bien ete defini \n\n");
    int choseMenu = 0;
	
    char enterMenu[255];
    do
    {
        printf("\n \n === Menu ACCUEIL === \n\n");
        printf("0. Quit \n \n");
        printf("1. Allocation of a memory area (First-fit,Best-fit,Worst-fit) \n \n");
        printf("2. Release of a memory area \n \n");
        printf("3. Viewing the memory occupation \n \n");
        printf("4. Fragmentation \n \n");
		printf("5. Redefinir les blocks memoire \n \n");
        printf(" \n \nChoisissez ce que vous souhaitez realiser en tapant le numero de votre choix ? \n \n");
         printf("numero choisi : ");
        while(1)
        {
            fgets(enterMenu, 255, stdin);
            if(sscanf(enterMenu, "%d", &choseMenu) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
        
        switch(choseMenu)
        {
            case 0:
			system("cls");
                printf("\n \n You would like to quit the program \n \n");
                break;
            case 1:
				system("cls");
                printf("\n \n === Choose an algorithm to execute === \n\n");
				printf("1. First-fit \n \n");
				printf("2. Best-fit\n \n");
				printf("3. Worst-fit \n \n");
			   printf("numero choisi : ");
					 int choseMenu2 = 0;
					  while(1)
						{
							fgets(enterMenu, 255, stdin);
							if(sscanf(enterMenu, "%d", &choseMenu2) == 1) break;
							printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
						}
						 switch(choseMenu2)
						{
							case 1:
								printf("\n \n ==== YOU CHOSE FIRST-FIT ALGORTIHM ====\n \n");
								
								  
								tabFiles = allocateProcesses(&nbFileSize);
								listProc=firstFit(tabMem, tabFiles, nbFileSize, nbMemFinal,listProc,&sizeListProc);
							
								break;
							case 2:
								printf("\n \n ==== YOU CHOSE BEST-FIT ALGORTIHM ====\n \n");						
								tabFiles = allocateProcesses(&nbFileSize);
								
								
								listProc=bestFit(tabMem, tabFiles, nbFileSize, nbMemFinal,listProc,&sizeListProc);
					
							
								
								break;	
							case 3:
								printf("\n \n ==== YOU CHOSE WORST-FIT ALGORTIHM ====\n \n");
							  
								tabFiles = allocateProcesses(&nbFileSize);

								
								listProc=worstFit(tabMem, tabFiles, nbFileSize, nbMemFinal,listProc,&sizeListProc);
							
								
								break;	
							default:
								printf(" \n \n Mauvaise saisie \n \n");
								break;
						}	

               
                break;
            case 2:
				system("cls");
                printf("\n \n ==== RELEASE OF MEMORY AREA ====\n \n");
				 listProc=releaseArea(tabMem, tabFrag,nbMemFinal,listProc,&sizeListProc);
				 
                break;
            case 3:
				system("cls");
                printf("\n \n Viewing the memory occupation \n \n");
				 showMemory(nbMemFinal,tabMem);
                break;
            case 4:
				system("cls");
                printf("\n \n Fragmentation \n \n");
				tabMem=groupSmallArea(tabMem,&nbMemFinal,tabFrag);
				tabFrag=keepCopy(tabMem,&nbMemFinal,tabFrag);
                break;
			case 5:
				system("cls");
                printf("\n\n ====  REDEFINITION DES BLOCKS MEMOIRES ====\n \n");
				 tabMem = allocateMemory(tabMem);
				tabFrag=copy(tabMem,&nbMemFinal);
                break;
            default:
                printf(" \n \n Mauvaise saisie \n \n");
                break;
        }
        
        
    }while(choseMenu!=0);
    
    
    
    
    return 0;
}

int* allocateMemory(int* _tabMem){
    int j;
    char enterInput[255];
    printf("\n \n Vous allez choisir quel taille feront les 5 blocs memoires \n\n");
    for(j=0;j<nbMem;j++){
        printf("\n\nEntrez une valeure pour le bloc numero %d \n\n", j+1);
        while(1)
        {
            fgets(enterInput, 255, stdin);
            if(sscanf(enterInput, "%d", &_tabMem[j]) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
        //scanf("%d",&_tabMem[j]);
    }
    
    return _tabMem;
    
}

int* allocateProcesses(int* _nbProcize){
    int* _tabProc;
    int nbProc;
    int size;
    int j;
    char enterInput[255];
    char enterInput2[255];
    printf("\n Combien de requetes souhaitez vous utiliser ? \n \n");
    while(1)
    {
        fgets(enterInput, 255, stdin);
        if(sscanf(enterInput, "%d", &nbProc) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    //scanf("%d", &nbProc);
    _tabProc = calloc(nbProc, sizeof(int));
   // printf("Le tableau fait %d",nbProc);
    *_nbProcize = nbProc;
    for(j=0;j<nbProc;j++){
        printf("\n \n Quelle taille fait la requetes %d ? \n \n" ,j+1);
        while(1)
        {
            fgets(enterInput2, 255, stdin);
            if(sscanf(enterInput2, "%d", &size) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
        //scanf("%d", &size);
        _tabProc[j] = size;
    }
    
    return _tabProc;
    
}

int* firstFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc){
    int i,j,k,test=0;
    for(i=0;i<_nbFiles;i++)
    {
        test=0;
        for(j=0;j<_nbMem;j++)
        {
            if(_tabFiles[i]<=_tabMem[j]) //Dans le cas où la taille du bloc mémoire est strictement supérieur au processus
            {
                _tabMem[j]=_tabMem[j]-_tabFiles[i]; //On soustrait au bloc mémoire l'espace nécessaire pour allouer de la mémoire au processus
				
				listProc=realloc(listProc,sizeof(int));
				listProc[(*sizeListProc)]=_tabFiles[i];
				*sizeListProc=1+(*sizeListProc);
				
               // printf("\n De la mémoire est alloué au processeur %d :(%d)",i+1,_tabFiles[i]);
                test=1;
                break;
            }
            
        }
       
        
    }
	
	 if(test==0)// Dans le cas ou il n'y a pas d'espace libre pour le processus
        {
            printf("\n Les blocs mémoires necessaires ne sont pas disponibles");
           
        }
		else
		{
		 printf("\n\n L'algorithme s'est correctement execute \n\n");
		}
return listProc;
   
    
}

void showMemory(int _nbMem,int* _tabMem)
{
system("cls");
 printf("\n\n\n");
    int i=0;
    for(i=0;i<_nbMem;i++){
        printf("Blocs memoires %d  a pour quantite restante : %d \n",i,_tabMem[i]);
    }
}

int* bestFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc)
{//Le plus petit bloc suffisamment grand pour contenir notre processus est choisi. 

/*12 8  14 12 36
  7  11 35 13 11
*/
 int i,j,k,l=0,test=0,flag=0,sizeMem=EOF ;


//nbFiles =nombre de processus
// _tabFiles =taille du processus
//_nbMem = nombre de bloc mémoire
// _tabMem = taille du bloc mémoire
	
for(j=0;j<_nbFiles;j++)
	{
		
		for(i=0;i<_nbMem;i++)
			{
				
			if(_tabFiles[j]<=_tabMem[i]  )
				{
				for(k=0;k<_nbMem;k++)// parti du code s'assurant que l'on prend le block ayant la plus petite mémoire
				{
				
					if(_tabFiles[j]<=_tabMem[k] && _tabMem[k]<=_tabMem[i] && sizeMem!=EOF )
					{
					if(sizeMem>=_tabMem[k])
					{
					sizeMem=_tabMem[k];
					l=k;
					}
	
					}
					
					if(_tabFiles[j]<=_tabMem[k] && _tabMem[k]<=_tabMem[i] && sizeMem==EOF )
					{
					sizeMem=_tabMem[k];
					l=k;
					flag=1;
					}
				}
				
				}
				if(flag==1)
				{
				flag=0;
				sizeMem=EOF;
				// printf("\n Soustraction de %d - %d =",_tabMem[l], _tabFiles[j]);
				_tabMem[l]=_tabMem[l]-_tabFiles[j];
				// printf("%d",_tabMem[l]);
				 
				 listProc=realloc(listProc,sizeof(int));
				listProc[(*sizeListProc)]=_tabFiles[j];
				*sizeListProc=1+(*sizeListProc);
				
				test=1;
				break;
				}
				
			}
			
	
	}
	
	 if(test==0)// Dans le cas ou il n'y a pas d'espace libre pour le processus
        {
            printf("\n Les blocs mémoires necessaires ne sont pas disponibles");
           
        }
		else
		{
		 printf("\n\n L'algorithme s'est correctement execute \n\n");
		}
	return listProc;

}
int* worstFit(int* _tabMem, int* _tabFiles,int _nbFiles,int _nbMem, int* listProc, int* sizeListProc)
{//Le bloc qui nous laisse le plus grand morceau de mémoire libre est choisi (le plus grand bloc). 
int i,j,k,l=0,test=0,flag=0,sizeMem=EOF ;


//nbFiles =nombre de processus
// _tabFiles =taille du processus
//_nbMem = nombre de bloc mémoire
// _tabMem = taille du bloc mémoire
	
for(j=0;j<_nbFiles;j++)// je boucle pour tous les fichiers demandé
	{
		
		for(i=0;i<_nbMem;i++) //je boucle pour tous les 5 blocks mémoires
			{
				
			if(_tabFiles[j]<=_tabMem[i]  )
				{
				for(k=0;k<_nbMem;k++)// parti du code s'assurant que l'on prend le block ayant la plus grande mémoire
				{
				
					if(_tabFiles[j]<=_tabMem[k] && _tabMem[k]>=_tabMem[i] && sizeMem!=EOF )
					{
					if(sizeMem<=_tabMem[k])
					{
					sizeMem=_tabMem[k];
					l=k;
					}
	
					}
					
					if(_tabFiles[j]<=_tabMem[k] && _tabMem[k]>=_tabMem[i] && sizeMem==EOF )
					{
					sizeMem=_tabMem[k];
					l=k;
					flag=1;
					}
				}
				
				}
				if(flag==1)
				{
				flag=0;
				sizeMem=EOF;
				// printf("\n Soustraction de %d - %d =",_tabMem[l], _tabFiles[j]);
				_tabMem[l]=_tabMem[l]-_tabFiles[j];
				// printf("%d",_tabMem[l]);
				 
				 listProc=realloc(listProc,sizeof(int));
				listProc[(*sizeListProc)]=_tabFiles[j];
				*sizeListProc=1+(*sizeListProc);
				
				test=1;
				break;
				}
				
			}
			
		
	}
	
	 if(test==0)// Dans le cas ou il n'y a pas d'espace libre pour le processus
        {
            printf("\n Les blocs mémoires necessaires ne sont pas disponibles");
           
        }
		else
		{
		 printf("\n\n  L'algorithme s'est correctement execute \n\n");
		}
	
	
	return listProc;
}

int* groupSmallArea(int* _tabMem,int* _nbMem,int* tabFrag)
{

	int i=0,j=0, tailleTotale=0,tailleMemoire=0,countZero=0;

	for(i=0;i<(*_nbMem);i++)
	{
	tailleTotale=tailleTotale+_tabMem[i];
		if(+_tabMem[i]==0)
		{
		countZero=countZero+1;
		}
	}
	
	if(countZero==(*_nbMem) ||countZero==(*_nbMem)-1 )
		{
		return _tabMem;
		}

	for(i=0;i<(*_nbMem);i++)
	{
	tailleMemoire=tailleMemoire+tabFrag[i];

		
	}
//	printf("\n \n Taille total = %d // tailleMemoire= %d // *_nbMem = %d ",tailleTotale,tailleMemoire,*_nbMem);
	int* newTab=_tabMem;
	if(tailleTotale<=(tailleMemoire/(*_nbMem)))
	{
	*_nbMem=*_nbMem+1;
	newTab=calloc(*_nbMem,sizeof(int));

		for(i=0;i<*_nbMem;i++)
		{
			if(i==(*_nbMem-1))
			{
			newTab[i]=tailleTotale;
			//printf("\n \n newTab[i] = %d // tailleTotale= %d ",newTab[i],tailleTotale);
			}
			
			else
			{
			tabFrag[i]=tabFrag[i]-_tabMem[i];
			newTab[i]=0;
			}
			
		}

	printf("\n\n ==== The small memory areas have been grouped ==== \n\n");
	}
	else
	{
	printf("\n\n ==== The memory areas do not need to be grouped ==== \n\n");
	return _tabMem;
	}
	return newTab;
}

int* keepCopy(int* _tabMem,int* _nbMem,int* tabFrag)
{
int i =0;
tabFrag=realloc(tabFrag,(*_nbMem)*sizeof(int));
tabFrag[*_nbMem-1]=_tabMem[*_nbMem-1];



return tabFrag;

}

int* copy(int* _tabMem,int* _nbMem)
{
int* tabFrag=calloc((* _nbMem),sizeof(int));
int i=0;
for(i=0;i<(*_nbMem);i++)
{
tabFrag[i]=_tabMem [i];
}

return tabFrag;

}

int* releaseArea(int* _tabMem, int* tabFrag,int _nbMem, int* listProc, int* sizeListProc)
{

int flag2=0;
int k=0;
for(k=1;k<*sizeListProc;k++)
	{
	if(listProc[k]!=0)
	{
	flag2=1;
	}
		
	}
	
if((*sizeListProc)==1)
{
printf("\n \n == No request to release ==\n \n ");
}
else if(flag2==0)
{
printf("\n \n == No request to release ==\n \n ");
}

else
{

	int i=0;
	int flag=0;

	


		int nbProc;
		char enterInput[255];
		printf("\n Which request do you want to release ? \n \n");
		printf("\n tapez : 0 pour quitter \n \n");
		
		for(i=1;i<*sizeListProc;i++)
			{
			if(listProc[i]!=0)
			{
			printf("\n == La requete numero \"%d\",  occupe \"%d\" de memoire  == \n ",i,listProc[i]);
			}
				
			}
		printf("\n saisi :  ");	
			
		while(1)
		{
			fgets(enterInput, 255, stdin);
			if(sscanf(enterInput, "%d", &nbProc) == 1) 
			{
				if(0==nbProc)
				{
				return listProc;
				}
				for(i=1;i<*sizeListProc;i++)
				{
					if(i==nbProc)
					{
					printf("\n \n The request has been released \n \n");
					flag=1;
					break;
					}
				}
				
			 if(flag==0)
				{
					 printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
				}
			
			}
			
			 if(flag==1)
				{
				
				break;
				}
		}


		for(i=0;i<_nbMem;i++)
		{
			if((tabFrag[i]-_tabMem[i])>=listProc[nbProc])
			{
			_tabMem[i]=_tabMem[i]+listProc[nbProc];
			listProc[nbProc]=0;
			*sizeListProc=*sizeListProc-1;
			
			}
		}
		
}



return listProc;

}

