#include "arbore.h"
// adauga arbore in bst
nodbst *newNode(participant c)
{
   nodbst *nod = (nodbst *)malloc(sizeof(nodbst));
   if (nod == NULL)
   {
      printf("alocarea a esuat\n");
      exit(1);
   }
   nod->candidat.nume = (char *)malloc((strlen(c.nume) + 1) * sizeof(char));
   if (nod->candidat.nume == NULL)
   {
      printf("alocarea numelui a esuat");
      free(nod);
   }
   strcpy(nod->candidat.nume, c.nume);
   nod->candidat.experienta = c.experienta;
   nod->candidat.varsta = c.varsta;
   nod->candidat.statut = c.statut;
   nod->left = nod->right = NULL;
}
nodbst *insert(nodbst *nod, participant key)
{
   if (nod == NULL)
      return newNode(key); // nodul adaugat e frunza
   if (key.experienta < nod->candidat.experienta)
      nod->left = insert(nod->left, key); // inserare in subarorele stang
   else if (key.experienta >= nod->candidat.experienta)
      nod->right = insert(nod->right, key); // inserare in subarborele drept
   return nod;                              // returnez adresa nodului investigat
}

// functie pentru afisarea arborelui
void scriebst(nodbst *root, FILE *f2)
{
   if (root != NULL)
   {

      scriebst(root->right, f2);

      fprintf(f2, "\n%s %.2f %d ", root->candidat.nume, root->candidat.experienta, root->candidat.varsta);
      if (root->candidat.statut == LORD)
         fprintf(f2, "LORD");
      if (root->candidat.statut == AVENTURIER)
         fprintf(f2, "AVENTURIER");
      if (root->candidat.statut == CAVALER)
         fprintf(f2, "CAVALER");
      scriebst(root->left, f2);
   }
}

nodbst *minValueNode(nodbst *node)
{
   if (node == NULL)
      return NULL; // daca arborele e gol returnez NULL
   /* pentru gasirea minimului cobor spre nodul cel mai din stanga */
   while (node->left != NULL)
      node = node->left;
   return node;
}
// o(h)

nodbst *deleteNode(nodbst *root, participant key)
{

   if (root == NULL)
   {
      printf("eroare\n");
      return NULL;
   }

   if (key.experienta < root->candidat.experienta)
   {

      root->left = deleteNode(root->left, key); // se apeleaza pana gasesc nodul
   }
   else if (key.experienta > root->candidat.experienta)
      root->right = deleteNode(root->right, key); // sau nu mai exista noduri cand l-am gasit: key == root=>val
   else if (strcmp(root->candidat.nume, key.nume) == 0)
   {
      // daca nodul de sters nu are 2 copii
      if (root->left == NULL)
      {
         nodbst *temp = root; // retin adresa nodului de sters - cel care contine cheia
         root = root->right;  // locul lui e luat de copilul sau drept
         free(temp);          // sterg nodul
         return root;
      }
      else if (root->right == NULL)
      {
         nodbst *temp = root; // retin adresa nodului de sters - cel care contine cheia
         root = root->left;   // locul lui e luat de copilul sau stang
         free(temp);
         return root;
      }
      else
      {
         // daca are 2 copii
         nodbst *temp = minValueNode(root->right);
         root->candidat = temp->candidat;
         // sterg nodul care continea min - cautand de la nodul de sters in adancime dupa cheie
         root->right = deleteNode(root->right, temp->candidat);
      }
   }

   return root;
}
void freebst(nodbst *root)
{
   if (!root)
      return;
   freebst(root->left);
   freebst(root->right);
   free(root->candidat.nume);
   free(root);
}