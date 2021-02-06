#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void AjouterOuvrage();      // 1.ajouter un ouvrage
void AfficherOuvrages();    // 2.afficher des ouvrages
void chercherOuvrage();     // 3.Chercher un ouvrage
void ModifierOuvrage();     // 4.Mofidier les données d'un ouvrage
void EffacerOuvrage();      // 5.Effacer un ouvrage
void OuvrageCategorie();    // 6.Afficher les ouvrages selon une catégorie saisie
void AjouterExemplaire();   // 7.Ajouter des exemplaire à un ouvrage déja existant
void AfficherExemplaires(); // 8.Afficher les exemplaires
void SupprimerExemplaire(); // 9.Supprimer un exemplaire
void AjouterAdherent();     // 10.Ajouter un adherent
void AfficherAdherent();    // 11.Afficher tous les adherents
void EffacerAdherent();     // 12.Effacer un adherent
void EnregistrerEmprunt();  // 13.Ajouter un emprunt
void AfficherEmprunts();    // 14.afficher les empruntes
void RetourRetardes();      // 15.afficher les retours retardés
void EnregistrerRetours();  // 16.supprimer les empruntes retournés

struct ouvrage
{
    int Code_ouvrage;
    char titre[20];
    char auteur[20];
    char categorie[20];
    char editeur[20];
    int annee_edition;
    struct ouvrage *next;
};

struct ouvrage *start = NULL;

struct exemplaire
{
    int Code_exemplaire;
    int Code_ouvrage;
    char etat[20];
    struct exemplaire *next;
};

struct exemplaire *commen = NULL;

struct adherent
{
    int Code_adherent;
    char nom_adherent[20];
    char Prenom_adherent[20];
    char email[20];
    int num_telephone;
    int date_debut_adhesion;
    int date_fin_adhesion;

    struct adherent *next;
};

struct adherent *deb = NULL;

struct emprunt
{
    int Code_emprunt;
    int Code_adherent;
    int Code_exemplaire;
    int Code_ouvrage;
    int Date_sortie;
    int Date_retour;

    struct emprunt *next;
};

struct emprunt *debut = NULL;

int main()
{
    int choix;
    while (1)
    {
        printf("\033[0;31m");
        printf("\n******LA BIBLIOTHEQUE******");
        printf("\033[0;35m\n");
        printf("1 Gestion des ouvrages\n");
        printf("2 Gestion des exmplaires\n");
        printf("3 Gestion des adh\x82rents\n");
        printf("4 Gestion des empruntes\n");
        printf("5 Quitter  \n");
        printf("--------------------------------------");
        printf("\033[0;31m\n");
        printf("Entrez votre choix svp :");
        printf("\033[0m\n");
        scanf("%d", &choix);

        printf("\n");
        switch (choix)
        {
        case 1:
            printf("\033[0;31m");
            printf("******la gestion des ouvrages******");
            int i = 0;
            printf("\033[0;34m\n");
            printf("1 Consulter la liste des ouvrages\n");
            printf("2 Ajouter un ouvrage \x85 la biblioth\x8Aque\n");
            printf("3 Chercher un ouvrage dans la biblioth\x8Aque\n");
            printf("4 Chercher des ouvrages selon une cat\x82gorie\n");
            printf("5 Modifier un ouvrage de la biblioth\x8Aque\n");
            printf("6 Supprimer un ouvrage de la biblioth\x8Aque\n");
            printf("7 Quitter  \n");
            printf("--------------------------------------");
            printf("\033[0;31m\n");
            printf("Entrez votre choix svp :\033[0m");
            printf("\033[0m\n");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                AfficherOuvrages();
                break;
            case 2:
                AjouterOuvrage();
                break;
            case 3:
                chercherOuvrage();
                break;
            case 4:
                OuvrageCategorie();
                break;
            case 5:
                ModifierOuvrage();
                break;
            case 6:
                EffacerOuvrage();
                break;

            case 7:
                exit(0);
                break;
            case 8:
                EnregistrerEmprunt();
                break;
            default:
                printf("Vous n'avez pas rentre un nombre correct.\n\n");
                break;
            }

            break;

        case 2:
            printf("\033[0;31m");
            printf("******la gestion des exemplaire******");
            int j = 0;
            printf("\033[0;34m\n");
            printf("1 Ajouter un exemplaire \x85 un ouvrages\n");
            printf("2 Afficher les exemplaires \n");
            printf("3 supprimer un exemplaire\n");
            printf("4 Quitter  \n");
            printf("--------------------------------------");
            printf("\033[0;31m\n");
            printf("Entrez votre choix svp :\033[0m");
            printf("\033[0m\n");
            scanf("%d", &j);
            switch (j)
            {
            case 1:
                AjouterExemplaire();
                break;
            case 2:
                AfficherExemplaires();
                break;
            case 3:
                SupprimerExemplaire();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Vous n'avez pas rentre un nombre correct.\n\n");
                break;
            }
            break;

        case 3:
            printf("\033[0;31m");
            printf("******la gestion des adh\x82rents******");
            int k = 0;
            printf("\033[0;34m\n");
            printf("1 Ajouter un adh\x82rent\n");
            printf("2 Afficher les adherents \n");
            printf("3 supprimer un adherent\n");
            printf("3 Quitter  \n");
            printf("--------------------------------------");
            printf("\033[0;31m\n");
            printf("Entrez votre choix svp :\033[0m");
            printf("\033[0m\n");
            scanf("%d", &k);
            switch (k)
            {
            case 1:
                AjouterAdherent();
                break;
            case 2:
                AfficherAdherent();
                break;
            case 3:
                EffacerAdherent();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Vous n'avez pas rentre un nombre correct.\n\n");
                break;
            }
            break;
        case 4:

            printf("\033[0;31m");
            printf("******la gestion des emprunts******");
            int b = 0;
            printf("\033[0;34m\n");
            printf("1 Enregistrer un nouveaux emprunt\n");
            printf("2 Enregistrer le retour d'un emprunt\n");
            printf("3 Afficher la liste des empruntes  \n");
            printf("4 Afficher la liste des retours retard\x82s  \n");
            printf("5 Quitter  \n");
            printf("--------------------------------------");
            printf("\033[0;31m\n");
            printf("Entrez votre choix svp :\033[0m");
            printf("\033[0m\n");
            scanf("%d", &b);
            switch (b)
            {
            case 1:
                EnregistrerEmprunt();
                break;
            case 2:
                EnregistrerRetours();
                break;
            case 3:
                AfficherEmprunts();
                break;
            case 4:
                RetourRetardes();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Vous n'avez pas rentre un nombre correct.\n\n");
                break;
            }
            break;

        default:
            printf("le num\x82ro entrer n'est pas valide.\n\n");
            break;
        }
    }
    return 0;
}

void AjouterOuvrage()
{
    struct ouvrage *p, *q;
    p = (struct ouvrage *)malloc(sizeof(struct ouvrage));
    if (p == NULL)
    {
        printf("hors de memoire \n");
        exit(0);
    }
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage : ");
    printf("\033[0m\n");
    scanf("%d", &p->Code_ouvrage);
    printf("\033[0;36m\n");
    printf("Entez le titre de l'ouvrage : ");
    printf("\033[0m\n");
    scanf("%s", &p->titre);
    printf("\033[0;36m\n");
    printf("Entrez le nom de l'auteur  de l'ouvrage : ");
    printf("\033[0m\n");
    scanf("%s", &p->auteur);
    printf("\033[0;36m\n");
    printf("Entez la categorie de l'ouvrage : ");
    printf("\033[0m\n");
    scanf("%s", &p->categorie);
    printf("\033[0;36m\n");
    printf("Entrez le nom de l'editeur : ");
    printf("\033[0m\n");
    scanf("%s", &p->editeur);
    printf("\033[0;36m\n");
    printf("Entrez l'annee de l'edition  : ");
    printf("\033[0m\n");
    scanf("%d", &p->annee_edition);
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

void AfficherOuvrages()
{
    struct ouvrage *p;
    if (start == NULL)
    {
        printf("=> La liste des ouvrages est vide\n");
        return;
    }
    else
    {
        p = start;
        printf("=> La liste des ouvrages :\n");
        while (p != NULL)
        {
            printf("\033[0;32m");
            printf("code ouvrage : ");
            printf("\033[0m");
            printf("%d", p->Code_ouvrage);
            printf("\033[0;32m");
            printf(", titre : ");
            printf("\033[0m");
            printf("%s", p->titre);
            printf("\033[0;32m");
            printf(", auteur : ");
            printf("\033[0m");
            printf("%s", p->auteur);
            printf("\033[0;32m");
            printf(", categorie : ");
            printf("\033[0m");
            printf("%s", p->categorie);
            printf("\033[0;32m");
            printf(", editeur : ");
            printf("\033[0m");
            printf("%s", p->editeur);
            printf("\033[0;32m");
            printf(", annee edition : ");
            printf("\033[0m");
            printf("%d", p->annee_edition);
            printf("\n");
            p = p->next;
        }
    }
}

int chercheOuvrage(int chercherOuv)
{
    int index;
    int n, OuvChercher;
    struct ouvrage *p;

    index = 0;
    p = start;

    while (p != NULL && p->Code_ouvrage != chercherOuv)
    {
        index++;
        p = p->next;
    }

    return (p != NULL) ? index : -1;
}

int chercherExemplaire(int chercherExemp)
{
    int indexExemp;
    int n, ExempChercher;
    struct exemplaire *p;

    indexExemp = 0;
    p = commen;

    while (p != NULL && p->Code_exemplaire != chercherExemp)
    {
        indexExemp++;
        p = p->next;
    }

    return (p != NULL) ? indexExemp : -1;
}

int chercherAdherent(int chercherAdhe)
{
    int indexAdherent;
    int n, AdheChercher;
    struct adherent *p;

    indexAdherent = 0;
    p = deb;

    while (p != NULL && p->Code_adherent != chercherAdhe)
    {
        indexAdherent++;
        p = p->next;
    }

    return (p != NULL) ? indexAdherent : -1;
}

void chercherOuvrage()
{
    int i, leCode;
    struct ouvrage *p;
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage a cherche");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (start == NULL)
    {
        printf("=> la liste des ouvrages est vide");
    }
    else
        p = start;
    {
        while (p != NULL)
        {
            if (p->Code_ouvrage = leCode)
            {
                i = 1;
                printf("\033[0;32m");
                printf("code ouvrage : ");
                printf("\033[0m");
                printf("%d", p->Code_ouvrage);
                printf("\033[0;32m");
                printf(", titre : ");
                printf("\033[0m");
                printf("%s", p->titre);
                printf("\033[0;32m");
                printf(", auteur : ");
                printf("\033[0m");
                printf("%s", p->auteur);
                printf("\033[0;32m");
                printf(", categorie : ");
                printf("\033[0m");
                printf("%s", p->categorie);
                printf("\033[0;32m");
                printf(", editeur : ");
                printf("\033[0m");
                printf("%s", p->editeur);
                printf("\033[0;32m");
                printf(", annee edition : ");
                printf("\033[0m");
                printf("%d", p->annee_edition);
                printf("\n");
                p = p->next;
            }
            else
            {
                p = p->next;
            }
            if (i == 0)
            {
                printf("\033[0;36m");
                printf("l'ouvrage cherche n'existe pas");
                printf("\033[0m\n");
            }
        }
    }
}

void ModifierOuvrage()
{
    int i, leCode, lequel;

    struct ouvrage *p;
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage a cherche");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (start == NULL)
    {
        printf("\033[0;36m");
        printf("la liste des ouvrages est vide");
        printf("\033[0m\n");
    }
    else
        p = start;
    {
        while (p != NULL)
        {
            if (p->Code_ouvrage = leCode)
            {
                printf("\033[0;36m");
                printf("choisisser la quel valeur vous voulez modifier quel valeur \n 1 : titre ,2 : auteur ,3 : categorie 4 : editeur, 5 : annee edition");
                printf("\033[0m\n");
                scanf("%d", &lequel);
                switch (lequel)
                {
                    char modif[20], modifa[20], cat[20], edit[20];
                    int annee;
                case 1:
                    printf("\033[0;36m");
                    printf("entrer le nouveaux titre");
                    printf("\033[0m\n");
                    scanf("%s", &modif);
                    strcpy(p->titre, modif);
                    break;
                case 2:
                    printf("\033[0;36m");
                    printf("entrer le nouveaux auteur");
                    printf("\033[0m\n");
                    scanf("%s", &modifa);
                    strcpy(p->auteur, modifa);
                    break;
                case 3:
                    printf("\033[0;36m");
                    printf("entrer la nouvelle categorie");
                    printf("\033[0m\n");
                    scanf("%s", &cat);
                    strcpy(p->categorie, cat);
                    break;
                case 4:
                    printf("\033[0;36m");
                    printf("entrer le nouveaux editeur");
                    printf("\033[0m\n");
                    scanf("%s", &edit);
                    strcpy(p->editeur, edit);
                    break;
                case 5:
                    printf("\033[0;36m");
                    printf("entrer la nouvelle annee d'edition");
                    printf("\033[0m\n");
                    scanf("%s", &annee);
                    p->annee_edition = annee;
                    break;

                default:
                    printf("pas valide.\n");
                }
                break;
            }
            else
            {
                p = p->next;
            }
        }
    }
}

void EffacerOuvrage()
{
    int i, leCode;
    struct ouvrage *p, *q;
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage a effacer");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (start == NULL)
    {
        printf("\033[0;36m");
        printf("la liste des ouvrages est vide");
    }
    else
        p = start;
    if (p != NULL && p->Code_ouvrage == leCode)
    {
        start = start->next;
        printf("\033[0;36m");
        printf("l'ouvrage est efface %d ", p->Code_ouvrage);
        printf("\033[0m\n");
        free(p);
    }
    else
    {
        while (p != NULL && p->Code_ouvrage != leCode)
        {
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            printf("\033[0;36m");
            printf("IL n'y a pas un ouvrage avec ce code!");
            printf("\033[0m\n");
            return;
        }
        else
        {
            q->next = p->next;
            printf("\033[0;36m");
            printf("l'ouvrage est effac\x82 %d", p->Code_ouvrage);
            printf("\033[0m\n");
            free(p);
        }
    }
}

void OuvrageCategorie()
{
    int i, k;
    char cat[20];
    struct ouvrage *p;
    printf("\033[0;36m");
    printf("Entrez la cat%cgorie souhait%ce", 130, 130);
    printf("\033[0m\n");
    scanf("%s", &cat);
    if (start == NULL)
    {
        printf("\033[0;36m");
        printf("La liste des ouvrages est vides");
        printf("\033[0m\n");
    }
    else
        p = start;
    {
        while (p != NULL)
        {
            if (strcmp(p->categorie, cat) == 0)
            {
                printf("\033[0;32m");
                printf("code ouvrage : ");
                printf("\033[0m");
                printf("%d", p->Code_ouvrage);
                printf("\033[0;32m");
                printf(", titre : ");
                printf("\033[0m");
                printf("%s", p->titre);
                printf("\033[0;32m");
                printf(", auteur : ");
                printf("\033[0m");
                printf("%s", p->auteur);
                printf("\033[0;32m");
                printf(", categorie : ");
                printf("\033[0;33m");
                printf("%s", p->categorie);
                printf("\033[0;32m");
                printf(", editeur : ");
                printf("\033[0m");
                printf("%s", p->editeur);
                printf("\033[0;32m");
                printf(", annee edition : ");
                printf("\033[0m");
                printf("%d", p->annee_edition);
                printf("\n");
                printf("\033[0m");
                printf(" ");
                p = p->next;
            }
            else
            {

                p = p->next;
            }
        }
    }
}

void AjouterExemplaire()
{
    int i, leCode, trouver = 0;
    struct ouvrage *p, *q;
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (start == NULL)
    {
        printf("\033[0;36m");
        printf("La liste des ouvrages est vide");
        printf("\033[0m\n");
    }
    else
        p = start;
    if (p != NULL && p->Code_ouvrage == leCode)
    {
        trouver = 1;
        printf("=> L'ouvrage est trouv%c dans la bibliotheque\n", 130);

        struct exemplaire *p, *q;
        p = (struct exemplaire *)malloc(sizeof(struct exemplaire));
        if (p == NULL)
        {
            printf("hors de la memoire \n");
            exit(0);
        }

        p->Code_ouvrage = leCode;

        printf("\033[0;36m");
        printf("Entez le code de l'exemplaire : ");
        printf("\033[0m\n");
        scanf("%d", &p->Code_exemplaire);
        printf("\033[0;36m");
        printf("Entez l'etat de l'ouvrage : ");
        printf("\033[0m\n");
        scanf("%s", &p->etat);

        p->next = NULL;
        if (commen == NULL)
        {
            commen = p;
        }
        else
        {
            q = commen;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
    else
    {
        while (p != NULL && p->Code_ouvrage != leCode)
        {
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            trouver = 0;
            printf("=> IL n'y a pas un ouvrage avec ce code!");
        }
        else
        {
            trouver = 1;
            printf("=> l'ouvrage est trouv%c dans la bibliotheque\n", 130);

            struct exemplaire *p, *q;
            p = (struct exemplaire *)malloc(sizeof(struct exemplaire));
            if (p == NULL)
            {
                printf("Hors de memoire \n");
                exit(0);
            }
            p->Code_ouvrage = leCode;
            printf("Entez le code de l'exemplaire : \n");
            scanf("%d", &p->Code_exemplaire);
            printf("Entez l'etat de l'ouvrage : \n");
            scanf("%s", &p->etat);

            p->next = NULL;
            if (commen == NULL)
            {
                commen = p;
            }
            else
            {
                q = commen;
                while (q->next != NULL)
                {
                    q = q->next;
                }
                q->next = p;
            }
        }
    }
}

void AfficherExemplaires()
{
    struct exemplaire *p;
    if (commen == NULL)
    {
        printf("=> La liste des exemplaires est vide \n");
        return;
    }
    else
    {
        p = commen;
        printf("=> La liste des exemplaires :\n");
        while (p != NULL)
        {  printf("\033[0;32m");
            printf("code exemplaire : ");
            printf("\033[0m");
            printf("%d", p->Code_exemplaire);
            printf("\033[0;32m");
            printf(" code ouvrage : ");
            printf("\033[0m");
            printf("%d", p->Code_ouvrage);
             printf("\033[0;32m");
            printf(" etat exemplaire : ");
            printf("\033[0m");
            printf("%s", p->etat);
            printf("\n");
            p = p->next;
        }
    }
}

void SupprimerExemplaire()
{
    int i, leCode;
    struct exemplaire *p, *q;
    printf("\033[0;36m");
    printf("Entrez le code d'ouvrage a effacer");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (commen == NULL)
    {
        printf("La liste des exemplaire est vide");
    }
    else
        p = commen;
    if (p != NULL && p->Code_exemplaire == leCode)
    {
        commen = commen->next;
        printf("l'exemplaire est efface %d ", p->Code_exemplaire);
        free(p);
    }
    else
    {
        while (p != NULL && p->Code_exemplaire != leCode)
        {
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            printf("IL n'y a pas un exemplaire avec ce code!");
            return;
        }
        else
        {
            q->next = p->next;
            printf("l'exemplaire est efface %d", p->Code_exemplaire);
            free(p);
        }
    }
}

void AjouterAdherent()
{
    struct adherent *p, *q;
    p = (struct adherent *)malloc(sizeof(struct adherent));
    if (p == NULL)
    {
        printf("hors de memoire \n");
        exit(0);
    }
    printf("\033[0;36m");
    printf("Entrez le code d'adherent : ");
    printf("\033[0m\n");
    scanf("%d", &p->Code_adherent);
    printf("\033[0;36m");
    printf("Entez le nom de l'adherent : ");
    printf("\033[0m\n");
    scanf("%s", &p->nom_adherent);
    printf("\033[0;36m");
    printf("Entez le prenom de l'adherent : ");
    printf("\033[0m\n");
    scanf("%s", &p->Prenom_adherent);
    printf("\033[0;36m");
    printf("Entez l'email de l'adherent : ");
    printf("\033[0m\n");
    scanf("%s", &p->email);
    printf("\033[0;36m");
    printf("Entez le numero telephoe de l'adherent : ");
    printf("\033[0m\n");
    scanf("%d", &p->num_telephone);
    printf("\033[0;36m");
    printf("Entrez la date du d%cbut de l'adhesion en seconde : ", 130);
    printf("\033[0m\n");
    scanf("%d", &p->date_debut_adhesion);
    printf("\033[0;36m");
    printf("Entrez la date du fin de l'adhesion en seconde : ", 130);
    printf("\033[0m\n");
    scanf("%d", &p->date_fin_adhesion);

    p->next = NULL;
    if (deb == NULL)
    {
        deb = p;
    }
    else
    {
        q = deb;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

void AfficherAdherent()
{
    struct adherent *p;
    if (deb == NULL)
    {
        printf("La liste des adherents est vide\n");
        return;
    }
    else
    {
        p = deb;
        printf("La liste des adherent est :\n");
        while (p != NULL)
        {

            printf("\033[0;32m");
            printf("code adherent : ");
            printf("\033[0m");
            printf("%d", p->Code_adherent);
            printf("\033[0;32m");
            printf(", nom adherent : ");
            printf("\033[0m");
            printf("%s", p->nom_adherent);
            printf("\033[0;32m");
            printf(", prenom adherent : ");
            printf("\033[0m");
            printf("%s", p->Prenom_adherent);
            printf("\033[0;32m");
            printf(", email adherent : ");
            printf("\033[0m");
            printf("%s", p->email);
            printf("\033[0;32m");
            printf(", num telephone adherent : ");
            printf("\033[0m");
            printf("%d", p->num_telephone);
            printf("\033[0;32m");
            printf(", date debut adherent : ");
            printf("\033[0m");
            printf("%d", p->date_debut_adhesion);
            printf("\033[0;32m");
            printf(", date fin adherent : ");
            printf("\033[0m");
            printf("%d", p->date_fin_adhesion);

            printf("\n");
            p = p->next;
        }
    }
}

void EffacerAdherent()
{
    int i, leCode;
    struct adherent *p, *q;
    printf("\033[0;36m");
    printf("Entrez le code d'adherent %c effacer", 133);
    printf("\033[0m\n");
    scanf("%d", &leCode);

    if (deb == NULL)
    {
        printf("\033[0;36m");
        printf("La liste des adherents est vide");
        printf("\033[0m\n");
    }
    else
        p = deb;
    if (p != NULL && p->Code_adherent == leCode)
    {
        deb = deb->next;
        printf("\033[0;36m");
        printf("l'*adherent '%d' est effac%c  ", p->Code_adherent, 130);
        printf("\033[0m\n");
        free(p);
    }
    else
    {
        while (p != NULL && p->Code_adherent != leCode)
        {
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            printf("\033[0;36m");
            printf("IL n'y a pas un adherent avec ce code!");
            printf("\033[0m\n");
            return;
        }
        else
        {
            q->next = p->next;
            printf("\033[0;36m");
            printf("l'adherent est effac%c %d", 130, p->Code_adherent);
            printf("\033[0m\n");
            free(p);
        }
    }
}

void EnregistrerEmprunt()
{
    int n, OuvChercher, index;
    printf("\033[0;36m");
    printf("Entrer le code de l'ouvrage ");
    printf("\033[0m\n");
    scanf("%d", &OuvChercher);
    index = chercheOuvrage(OuvChercher);

    if (index >= 0)
    {
        printf("=> l'ouvrage est trouv%c dans la liste\n", 130);
        int n, ExempChercher, indexExemp;
        printf("\033[0;36m");
        printf("Entrer le code de l'exemplaire");
        printf("\033[0m\n");
        scanf("%d", &ExempChercher);
        indexExemp = chercherExemplaire(ExempChercher);
        if (indexExemp >= 0)
        {
            printf("=> l'exemplaire est trouv%c dans la liste ",  130);
            struct exemplaire *R;
            R = commen;
            while (R != NULL && R->Code_exemplaire != ExempChercher)
            {
                R = R->next;
            }
            if (strcmp(R->etat, "libre") == 0)
            {
                printf("et libre\n");
                int n, AdheChercher, indexAdherent;
                printf("\033[0;36m");
                printf("Entrer le code de l'adherent ");
                printf("\033[0m\n");
                scanf("%d", &AdheChercher);
                indexAdherent = chercherAdherent(AdheChercher);
                if (indexAdherent >= 0)
                {
                    printf("=> l'adherent est trouve%c dans la liste\n" , 130);
                    struct emprunt *p, *q;
                    p = (struct emprunt *)malloc(sizeof(struct emprunt));
                    if (p == NULL)
                    {
                        printf("hors de memoire \n");
                    }
                    p->Code_ouvrage = OuvChercher;
                    p->Code_exemplaire = ExempChercher;
                    p->Code_adherent = AdheChercher;
                    printf("\033[0;36m");
                    printf("            ********\n");
                    printf("Entrez le code de l'emprunt : ");
                    printf("\033[0m\n");
                    scanf("%d", &p->Code_emprunt);
                    printf("\033[0;36m");
                    printf("Entez la Date de sortie de l'emprunt en seconde : ");
                    printf("\033[0m\n");
                    scanf("%d", &p->Date_sortie);
                    printf("\033[0;36m");
                    printf("Entez la Date de retour de l'emprunt en seconde : ");
                    printf("\033[0m\n");
                    scanf("%d", &p->Date_retour);
                    printf("\n");
                    struct exemplaire *k;
                    k = commen;
                     while (k != NULL)
                    {
                        if (k->Code_exemplaire = ExempChercher)
                        {  strcpy(k->etat, "emprunte");
                            printf("\033[0;36m");
                            printf("=> l'emprunt est realis%c avec succ%ces", 130 , 130);
                            k = k->next;
                        }
                        else
                        {  k = k->next; }
                    }
                    p->next = NULL;
                    if (debut == NULL)
                    {  debut = p;  }
                    else
                    { q = debut;
                        while (q->next != NULL)
                        {
                            q = q->next;
                        }
                        q->next = p;
                    }
                }
                else
                    printf("=> l'adherent '%d' n'est pas trouve%c dans la liste. \n", AdheChercher , 130);
            }
            else
            {
              printf("mais il est emprunt%c\n" ,130 );
            }
        }
        else
            printf("=> L'exemplaire '%d' n'est pas trouv%c dans la liste \n", ExempChercher, 130);
    }
     else
        printf("=> l'ouvrage '%d' n'est pas trouv%c dans la liste \n", OuvChercher, 130);
}

void AfficherEmprunts()
{
    struct emprunt *p;
    if (debut == NULL)
    {
        printf("=> La liste des emprunts est vide\n");
        return;
    }
    else
    {
        p = debut;
        printf("=> La liste des emprunts :\n");
        while (p != NULL)
        {
            printf("\033[0;32m");
            printf("code emprunt : ");
            printf("\033[0m");
            printf("%d", p->Code_emprunt);
            printf("\033[0;32m");
            printf(", code ouvrage : ");
            printf("\033[0m");
            printf("%d", p->Code_ouvrage);
            printf("\033[0;32m");
            printf(", code exemplaire : ");
            printf("\033[0m");
            printf("%d", p->Code_exemplaire);
            printf("\033[0;32m");
            printf(", code adherent : ");
            printf("\033[0m");
            printf("%d", p->Code_adherent);
            printf("\033[0;32m");
            printf(", Date sortie : ");
            printf("\033[0m");
            printf("%d", p->Date_sortie);
            printf("\033[0;32m");
            printf(", Date retour : ");
            printf("\033[0m");
            printf("%d", p->Date_retour);
            printf("\n");
            p = p->next;
        }
    }
}

void RetourRetardes()
{
    int laDate, i = 0;
    printf("\033[0;32m");
    printf("Donner la date d'aujourd'hui en seconde");
    printf("\033[0m\n");
    scanf("%d", &laDate);
    struct emprunt *p;
    if (debut == NULL)
    { printf("=> La liste des emprunts est vide\n"); }
    else
    {
        p = debut;
        printf("=> La liste des emprunts retard%ce :\n", 130);
        while (p != NULL)
        {  
            if (p->Date_retour > laDate)
            {   i++;
                printf("\033[0;32m");
                printf("code emprunt : ");
                printf("\033[0m");
                printf("%d", p->Code_emprunt);
                printf("\033[0;32m");
                printf(", code ouvrage : ");
                printf("\033[0m");
                printf("%d", p->Code_ouvrage);
                printf("\033[0;32m");
                printf(", code exemplaire : ");
                printf("\033[0m");
                printf("%d", p->Code_exemplaire);
                printf("\033[0;32m");
                printf(", code adherent : ");
                printf("\033[0m");
                printf("%d", p->Code_adherent);
                printf("\033[0;32m");
                printf(", Date sortie : ");
                printf("\033[0m");
                printf("%d", p->Date_sortie);
                printf("\033[0;32m");
                printf(", Date retour : ");
                printf("\033[0m");
                printf("%d", p->Date_retour);
                printf("\n");
                p = p->next;
            }
            else p = p->next;
            if (i = 0)
            {
                printf("\033[0;32m");
                printf("Il n'ya pas des emprunts retardes");
                printf("\033[0m");
            }
        }
    }
}

void EnregistrerRetours()
{
    int i, leCode;
    struct emprunt *p, *q;
    printf("\033[0;36m");
    printf("Entrez le code de l'emprunt a retourne");
    printf("\033[0m\n");
    scanf("%d", &leCode);
    if (debut == NULL)
    {
        printf("=> La liste des empruntes est vide");
    }
    else
        p = debut;
    if (p != NULL && p->Code_emprunt == leCode)
    {
        struct exemplaire *R;
        R = commen;
        while (R != NULL && R->Code_exemplaire != p->Code_exemplaire)
        {
            R = R->next;
        }
        strcpy(R->etat, "libre");

        debut = debut->next;
        printf("=> L'emprunt '%d' est efface  ", p->Code_exemplaire);
        free(p);
    }
    else
    {
        while (p != NULL && p->Code_exemplaire != leCode)
        {

            struct exemplaire *R;
            R = commen;
            while (R != NULL && R->Code_exemplaire != p->Code_exemplaire)
            {
                R = R->next;
            }
            strcpy(R->etat, "libre");
            q = p;
            p = p->next;
        }

        if (p == NULL)
        {
            printf("IL n'y a pas un emprunt avec ce code!");
            return;
        }
        else
        {
            q->next = p->next;
            printf("\033[0;36m");
            printf("L'emprunt numero'%d' est effac%c ", p->Code_exemplaire , 130);
            printf("\033[0m");
            free(p);
        }
    }
}