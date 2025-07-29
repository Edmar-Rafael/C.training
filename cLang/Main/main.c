#include "practice.c"


int main() {
   printStyles();

   unsigned int table[LENGTH] = {0}; 
   unsigned char *text = {"Well! At least I think I should try it."};

   for(i = 0; text[i] != '\0'; i++) {
      table[text[i]]++;
   }

   for(i = 0; i < LENGTH; i++) {
      if(table[i]) {
         printf("%3d = %c : %2d\n", i, i, table[i]);
      }
   }

   List list;

   list.head = NULL;
   list.length = 0;

   Node *current;

   for(i = 0; i < LENGTH; i++) {
      if(table[i] > 0) {
         Node *newNode = (struct Node *) malloc(sizeof(struct Node));

         if(newNode) {
            newNode->character = i;
            newNode->frequence = table[i];
            newNode->next = NULL;
            newNode->left = NULL;
            newNode->right = NULL;

            if(!list.head || list.head->frequence >= newNode->frequence) {
               newNode->next = list.head;
               list.head = newNode;
               list.length++;
               continue;
            }

            current = list.head;

            while(current->next && current->next->frequence < newNode->frequence) {
               current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            list.length++;
         }
      }
   }

   current = list.head;

   printf("\nSorted List\n");
   while(current) {
      printf("Character: %c\t Frequence: %d\n", current->character, current->frequence);
      current = current->next;
   }

   while(list.length > 1) {
      Node *first = list.head;
      list.head = first->next;
      first->next = NULL;
      list.length--;

      Node *second = list.head;
      list.head = second->next;
      second->next = NULL;
      list.length--;

      Node *newNode = (struct Node *) malloc(sizeof(struct Node));

      if(newNode) {
         newNode->character = '+';
         newNode->frequence = first->frequence + second->frequence;
         newNode->next = NULL;
         newNode->left = first;
         newNode->right = second;

         if(!list.head || list.head->frequence >= newNode->frequence) {
            newNode->next = list.head;
            list.head = newNode;
            list.length++;
            continue;
         }

         current = list.head;

         while(current->next && current->next->frequence < newNode->frequence) {
            current = current->next;
         }

         newNode->next = current->next;
         current->next = newNode;
         list.length++; 
      }
   }
   
   Stack stk;

   stk.height = 0;
   stk.top = NULL;

   current = list.head;
   Node *rm = NULL;

   int cols = 0;

   while(1) {
      if(!current->visited || current->left && !current->left->visited || current->right && !current->right->visited) {
         Node *newNode = (struct Node *) malloc(sizeof(struct Node));

         if(newNode) {
            newNode->character = current->character;
            newNode->frequence = stk.height;
            newNode->left = current->left;
            newNode->right = current->right;
            newNode->next = stk.top;
            stk.top = newNode;
            current->visited = 1;

            if(!newNode->left && !newNode->right)
               printf("\nLeaf: %c\t\tHeight: %d", newNode->character, stk.height);
            
            if(current->left && !current->left->visited) {
               current = current->left;
               stk.height++;
               continue;
            }

            if(current->right && !current->right->visited) {
               current = current->right;
               stk.height++;
               continue;
            }
         }
      }
      
      rm = stk.top;
      stk.top = rm->next;
      current = stk.top;
      free(rm);
      if(stk.height > cols) cols = stk.height;
      if(stk.height == 0) break;
      stk.height = current->frequence;
   }

   printf("\n");

   char **dict = (char **) malloc(sizeof(char *) * LENGTH);

   for(i = 0; i < LENGTH; i++) {
      dict[i] = (char *) calloc(cols, sizeof(char));
   }

   stk.top = NULL;
   stk.height = 0;

   current = list.head;

   char *path = (char *) calloc(cols, sizeof(char));

   while(1) {
      if(current->visited || current->left && current->left->visited || current->right && current->right->visited) {
         Node *node = (struct Node *) malloc(sizeof(struct Node));

         if(node) {
            node->character = current->character;
            node->frequence = stk.height;
            node->left = current->left;
            node->right = current->right;
            node->next = stk.top;
            stk.top = node;
            current->visited = 0;
            if(!node->left && !node->right) {
               stringCopy(dict[node->character], path);
            }

            if(current->left && current->left->visited) {
               char left[cols];
               stringMemSet(left, 0, cols);
               stringCopy(left, path);
               concat(left, "0");
               current = current->left;
               stk.height++;
               stringCopy(path, left);
               continue;
            }

            if(current->right && current->right->visited) {
               char right[cols];
               stringMemSet(right, 0, cols);
               stringCopy(right, path);
               concat(right, "1");
               current = current->right;
               stk.height++;
               stringCopy(path, right);
               continue;
            }
         }
      }

      rm = stk.top;
      stk.top = rm->next;
      current = stk.top;
      path[stk.height - 1] = '\0';
      free(rm);
      if(stk.height == 0) break;
      stk.height = current->frequence;
   }
   printf("\n");

   for(i = 0; i < LENGTH; i++) {
      if(stringLen(dict[i]) > 0) {
         printf("%3d: %s\n", i, dict[i]);
      }
   }

   return 0;
}
/*
y:1->u:1->r:1->o:1->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            y     u
->r:1->o:1->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            r     o
->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            n     k
->d:1->a:1->W:1->A:1->.:1->!:1->+:2-> +:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            d     a
->W:1->A:1->.:1->!:1->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            W     A
->.:1->!:1->+:2 ->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            .     !
->+:2 ->+:2 ->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:4
                          /         \
                        +:2         +:2
                       /   \       /   \
                      .     !     W     A
->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                         +:2        +:2
                        /   \      /   \
                       d     a    n     k
->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          +:2       +:2
                         /   \     /   \
                        r     o   y     u
-> s:2->i:2->h:2->e:2->I:2->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          s          i
->h:2->e:2->I:2->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          h          e
->I:2->+:4 ->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:6
                           /        \
                          I         +:4
                                 /        \
                                h          e
->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->+:6 ->'':8->
                              +:8
                  /                         \
                +:4                         +:4
             /        \               /             \
            s          i            +:2             +:2
                                   /   \           /    \
                                  r     o         y      u
->+:4 ->+:4 ->l:4->t:5->+:6 ->+:8 ->'':8->
                              +:8
                  /                         \
                 +:4                        +:4
            /           \              /            \
          +:2           +:2          +:2            +:2
         /   \         /   \        /   \          /   \
        d     a       n     k      .     !        W     A
->l:4->t:5->+:6 ->+:8 ->+:8 ->'':8->
                                    +:9
                                   /   \
                                  l     t
-> +:6 ->+:8 ->+:8 ->'':8->+:9 ->
                                    +:14
                     /                                      \
                  +:6                                       +:8
            /              \                       /                   \
           I               +:4                    +:4                  +:4
                        /        \             /      \             /        \
                       h          e          +:2      +:2         +:2        +:2
                                            /   \    /   \       /    \     /    \
                                           d     a  n     k     .      !   W      A
->+:8 ->'':8->+:9 ->+:14 ->
                                    +:16
                           /                      \
                         +:8                      ''
               /                       \
             +:4                       +:4
         /        \                 /        \
        s          i              +:2        +:2
                                 /   \      /   \
                                r     o    y     u
->+:9 ->+:14 ->16 ->
                               +:23
               /                                  \
             +:9                                  +:14
          /       \             /                                   \
         l         t          +:6                                   +:8
                         /         \                  /                          \
                        I          +:4               +:4                         +:4
                                /        \       /          \                /          \
                              h           e    +:2          +:2           +:2           +:2
                                              /   \        /   \         /   \         /   \
                                             d     a      n     k       .     !       W     A
->+:16 ->+:23 ->
                                    +:39
                          /                         \
                        +:16                        +:23
           /                    \          /                    \
         +:8                    ''       +:9                    +:14
    /             \                     /   \         /                     \
  +:4             +:4                  l     t      +:6                     +:8
 /   \         /        \                          /   \           /                 \
s     i     +:2        +:2                        I    +:4       +:4                 +:4
           /   \      /   \                           /   \     /     \           /        \
          r     o    y     u                         h     e  +:2     +:2       +:2        +:2
                                                             /   \   /   \     /   \      /   \
                                                            d     a n     k   .     !    W     A
                                 */